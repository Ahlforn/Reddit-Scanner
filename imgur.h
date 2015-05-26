#ifndef IMGUR_H
#define IMGUR_H

#include <QObject>
#include <QtNetwork>

class Imgur : public QObject
{
    Q_OBJECT
private:
    QString m_clientID;
    QString m_url;
    QString m_gallery_url;
    QString m_image_url;
    bool m_active;
    QNetworkAccessManager nam;
    //QNetworkReply* reply;
    QQueue<QNetworkRequest> requestQueue;

    void getData();
public:
    explicit Imgur(QObject *parent = 0);
    QString getClientID();
    QString getUrl();
    void query(QString id);
signals:
    void changedClientID(QString);
    void changedUrl(QString);
    void finishedQuery(QUrl&);
    void requestFired();
public slots:
    void setClientID(QString id);
    void setUrl(QString url);
private slots:
    void onResponse(QNetworkReply* reply);
};

#endif // IMGUR_H
