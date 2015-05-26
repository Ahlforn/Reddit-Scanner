#include "imgur.h"

Imgur::Imgur(QObject *parent) : QObject(parent)
{
    m_gallery_url = "https://api.imgur.com/3/gallery/";
    m_image_url = "https://api.imgur.com/3/image/";
    m_active = false;

    connect(&nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResponse(QNetworkReply*)));
}

void Imgur::setClientID(QString id)
{
    if(id != m_clientID) {
        m_clientID = id;
        emit changedClientID(id);
    }

    return;
}

QString Imgur::getClientID()
{
    return m_clientID;
}

void Imgur::setUrl(QString url)
{
    if(url != m_url) {
        m_url = url;
        emit changedUrl(url);
    }

    return;
}

QString Imgur::getUrl()
{
    return m_url;
}

void Imgur::query(QString id)
{
    QByteArray clientID = (const char*) ("Client-ID " + m_clientID.toUtf8());

    QNetworkRequest request;
    request.setRawHeader("Authorization", clientID);
    request.setUrl(m_gallery_url + id + ".json");

    qDebug() << "queing imgur: " << request.url().toString();
    requestQueue.enqueue(request);

    if(!m_active)
        getData();
}

void Imgur::getData()
{
    if(requestQueue.isEmpty())
        return;

    m_active = true;

    qDebug() << "imgur request queue: " << requestQueue.count();
    QNetworkRequest request = requestQueue.dequeue();
    qDebug() << "requesting";
    nam.get(request);
}

void Imgur::onResponse(QNetworkReply* reply)
{
    m_active = false;

    qDebug() << "reply url " << reply->url().toString();
    //if(imgurReply->error() != QNetworkReply::NoError)
        //return;

    QByteArray replyData = reply->readAll();

    QJsonParseError jerror;
    QJsonDocument jdoc = QJsonDocument::fromJson(replyData, &jerror);

    if(jerror.error != QJsonParseError::NoError)
        return;

    QJsonObject obj = jdoc.object();
    QJsonObject data = obj["data"].toObject();

    if(obj["status"].toInt() == 200 && obj["success"].toBool()) {
        QJsonArray images = data["images"].toArray();

        if(!images.isEmpty()) {
            foreach(const QJsonValue image, images) {
                QString link = image.toObject()["link"].toString();
                QUrl url = QUrl(link);
                emit finishedQuery(url);
            }
        }
        else if(!data["link"].isNull()) {
            QString link = data["link"].toString();
            QUrl url = QUrl(link);
            emit finishedQuery(url);
        }
    }
    else if(data["request"].toString().startsWith("/3/gallery/")){
        qDebug() << "Not gallery, query for image";
        QString url = reply->url().toString().replace("/gallery/", "/image/");

        QNetworkRequest request;

        QByteArray clientID = (const char*) ("Client-ID " + m_clientID.toUtf8());
        request.setRawHeader("Authorization", clientID);
        request.setUrl(url);

        requestQueue.enqueue(request);
    }

    if(!requestQueue.isEmpty())
        getData();
}
