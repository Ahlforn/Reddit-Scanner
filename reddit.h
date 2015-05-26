#ifndef REDDIT_H
#define REDDIT_H

#include <QObject>
#include <QtNetwork>

class Reddit : public QObject
{
    Q_OBJECT
public:
    explicit Reddit(QObject *parent = 0);
    QUrl getUrl();
    int getLimit();
    void query(QString dataType);
signals:
    void urlChanged(QUrl url);
    void limitChanged(int limit);
    void queryFinished(QJsonArray&);
    void requestFired();
public slots:
    void setUrl(QUrl url);
    void setLimit(int limit);
    void onResult();
private:
    QString datatypes[8];
    void getData(QString after = "");
    QUrl m_url;
    int m_limit;
    QJsonArray m_data;
    QString m_dataType;
    QString m_postType;
    QNetworkAccessManager nam;
    QNetworkReply* reply;
    QQueue<QNetworkRequest> requestQueue;
};

#endif // REDDIT_H
