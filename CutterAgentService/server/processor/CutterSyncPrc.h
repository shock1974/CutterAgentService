#ifndef CUTTERSYNCPRC_H
#define CUTTERSYNCPRC_H

#include <QThread>
#include <QString>

#include "Global.h"
#include "utiities/JSonRpcSvc.h"

class CutterSyncPrc : public QThread
{
    Q_OBJECT
public:
    explicit CutterSyncPrc(QObject *parent = 0);
    void setGlobal(Global *global);

    void run();

signals:
    void handled(const QString &msg);
private:
    Global *global;
    JSonRpcSvc  http;
    //当前是否在上传报警，如果是，则不能处理下一个文件
    bool isProcessing;

    void checkMO();
    void handleMO(const QString &data);


public slots:
    void synced(bool ok,QString transid,QString result);

};

#endif // CUTTERSYNCPRC_H
