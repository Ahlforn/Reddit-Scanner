#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include "imgur.h"
#include "reddit.h"

class Scanner : public QObject
{
   Q_OBJECT

public:
    Scanner(QObject *parent = 0);
    QUrl getUrl();
    int getLimit();
    QString getClientID();
    QString getPath();
private:
    void ProcessLink(QJsonObject entry);
    void RequestFile(QUrl url);
    QUrl m_url;
    Reddit reddit;
    Imgur imgur;
    QNetworkReply* m_currentReply;
    QNetworkAccessManager nam;
    //QNetworkReply* reply;
    QQueue<QNetworkRequest> downloadQueue;
    bool m_active;
    int m_requests;
    QString m_path;
private slots:
    void onDownload(QNetworkReply* reply);
    void BeginDownload();
    void onReddit(QJsonArray&);
    void onImgur(QUrl&);
    void recordRequest();
public slots:
    void setUrl(QUrl url);
    void setLimit(int limit);
    void setClientID(QString id);
    void setPath(QString path);
    void scan();
    void scan(QString url);
};

#endif // SCANNER_H
