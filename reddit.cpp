#include "reddit.h"

Reddit::Reddit(QObject *parent) : QObject(parent)
{
    m_limit = 100; // default
    m_postType ="t3";

    connect(&nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult()));
}

QUrl Reddit::getUrl()
{
    return m_url;
}

int Reddit::getLimit()
{
    return m_limit;
}

void Reddit::getData(QString after)
{
    QString strAfter = (!after.isEmpty()) ? "&after=" + after : "";
    QUrl fetchUrl = m_url;
    fetchUrl.setUrl(fetchUrl.url() + "?limit=100" + strAfter);

    qDebug() << fetchUrl.url();

    QNetworkRequest request;
    request.setUrl(fetchUrl);

    reply = nam.get(request);
}

void Reddit::query(QString dataType)
{
    qDebug() << "Query init.";
    m_dataType = dataType;
    getData();
}

void Reddit::setUrl(QUrl url)
{
    if(m_url != url) {
        m_url = url;
        emit urlChanged(url);
    }
}

void Reddit::setLimit(int limit)
{
    if(m_limit != limit) {
        m_limit = limit;
        emit limitChanged(limit);
    }
}

void Reddit::onResult()
{
    if(reply->error() != QNetworkReply::NoError)
        return;

    QByteArray data = reply->readAll();

    QJsonParseError jerror;
    QJsonDocument jdoc = QJsonDocument::fromJson(data,&jerror);

    if(jerror.error != QJsonParseError::NoError)
        return;

    QJsonArray entries = jdoc.object()["data"].toObject()["children"].toArray();

    foreach(const QJsonValue entry, entries) {
        QJsonObject obj = entry.toObject()["data"].toObject();

        if((m_dataType == "" || m_dataType == entry.toObject()["kind"].toString()) && m_limit > 0) {
            qDebug() << obj["name"].toString() << "limit=" << m_limit;
            m_data.append(obj);
            m_limit--;
        }
    }

    if(m_limit > 0) {
        QString after = jdoc.object()["data"].toObject()["after"].toString();
        qDebug() << after;
        getData(after);
    }
    else {
        emit queryFinished(m_data);
    }

    return;
}
