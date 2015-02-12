#ifndef JSONRPCSVC_H
#define JSONRPCSVC_H

#include <QObject>
#include <QFile>
#include <QHttp>
#include <QUrl>

class JSonRpcSvc : public QObject
{
    Q_OBJECT
public:
    explicit JSonRpcSvc();
    ~JSonRpcSvc();
    bool post(const QUrl &url,QMap<QString,QString> &map);
signals:
    void httpDone(const bool &error,const QString &transid,const QString &result);
public slots:
    void on_http_done(bool error);
    void on_http_stateChanged(int stat);
    void on_http_dataReadProgress(int done, int total);
    void on_http_dataSendProgress(int done, int total);
    void on_http_requestFinished(int id, bool error);
    void on_http_requestStarted(int id);
    void on_http_responseHeaderReceived(const QHttpResponseHeader &resp);

private:
    QHttp http;
    QString evtid;
    bool isFilished;
};

#endif // JSONRPCSVC_H
