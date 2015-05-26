#include "scanner.h"

Scanner::Scanner(QObject *parent) : QObject(parent)
{
    connect(&nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onDownload(QNetworkReply*)));
    connect(&reddit, SIGNAL(queryFinished(QJsonArray&)), this, SLOT(onReddit(QJsonArray&)));
    connect(&imgur, SIGNAL(finishedQuery(QUrl&)), this, SLOT(onImgur(QUrl&)));

    connect(&reddit, SIGNAL(requestFired()), this, SLOT(recordRequest()));
    connect(&imgur, SIGNAL(requestFired()), this, SLOT(recordRequest()));

    m_active = false;
    m_requests = 0;
}

void Scanner::onDownload(QNetworkReply* reply)
{
    qDebug() << "onDownload";
    m_active = false;

    if(reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "saving " << reply->url().toString();
    QString random = (QString) qrand();
    QString path = m_path + reply->url().fileName();

    QFile* file = new QFile(path);
    if(file->open(QIODevice::WriteOnly)) {
        file->write(reply->readAll());
    }
    file->flush();
    file->close();
    delete file;
    file = 0;

    if(!downloadQueue.isEmpty())
        BeginDownload();

    return;
}

void Scanner::onReddit(QJsonArray& data)
{
    qDebug() << "reddit data." << data.count();

    foreach(QJsonValue value, data) {
        ProcessLink(value.toObject());
    }
}

void Scanner::onImgur(QUrl& url)
{
    qDebug() << "imgur data: " << url.fileName();
    RequestFile(url);
}

void Scanner::ProcessLink(QJsonObject entry)
{
    QUrl url = QUrl(entry["url"].toString());
    QString filename = url.fileName();

    if(filename != "") {
        int dotPos = filename.indexOf(".");

        if(dotPos == -1 && entry["domain"].toString().endsWith("imgur.com")) {
            if(url.fileName().indexOf(",") != -1) {
                QStringList ids = url.fileName().split(",", QString::SkipEmptyParts);
                for(QStringList::const_iterator it = ids.begin(); it != ids.end(); ++it) {
                    QString id = *it;
                    qDebug() << "imgur: "  << id;
                    imgur.query(id);
                }
            }
            else {
                qDebug() << "imgur: "  << url.toString() << ", " << url.fileName();
                imgur.query(filename);
            }
            return;
        }

        if(dotPos > -1) {
            if(filename.endsWith(".jpg") || filename.endsWith(".png") || filename.endsWith(".gif")) {
                RequestFile(url);
                //qDebug() << "other: " << url.toString();
                return;
            }
        }
    }

    return;
}

void Scanner::RequestFile(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);

    qDebug() << "requesting " << url.toString();

    downloadQueue.enqueue(request);

    if(!m_active)
        BeginDownload();

    return;
}

void Scanner::BeginDownload()
{
    if(downloadQueue.isEmpty())
        return;

    qDebug() << downloadQueue.count() << " pending files.";

    m_active = true;

    QNetworkRequest request = downloadQueue.dequeue();
    nam.get(request);

    return;
}

QUrl Scanner::getUrl()
{
    return m_url;
}

void Scanner::setUrl(QUrl url)
{
    if(url != m_url)
        m_url = url;

    return;
}

int Scanner::getLimit()
{
    return reddit.getLimit();
}

void Scanner::setLimit(int limit)
{
    if(limit != reddit.getLimit())
        reddit.setLimit(limit);
}

QString Scanner::getClientID()
{
    return imgur.getClientID();
}

void Scanner::setClientID(QString id)
{
    if(id != imgur.getClientID())
        imgur.setClientID(id);
}

void Scanner::recordRequest()
{
    m_requests++;
}

QString Scanner::getPath()
{
    return m_path;
}

void Scanner::setPath(QString path)
{
    if(path != m_path)
        m_path = path;
}

void Scanner::scan()
{
    reddit.setUrl(m_url);
    reddit.query("t3");
}

void Scanner::scan(QString url)
{
    m_url = QUrl(url);
    setUrl(url);
    scan();
}
