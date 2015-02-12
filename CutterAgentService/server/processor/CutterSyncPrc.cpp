#include "CutterSyncPrc.h"
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QMap>
#include <QDebug>
#include <QDateTime>
#include <QLocale>
#include <QTextCodec>
#include <QByteArray>
#include <QSettings>

#include "Utility.h"

CutterSyncPrc::CutterSyncPrc(QObject *parent) :
    QThread(parent)
{
    this->isProcessing=false;
    connect(&http,SIGNAL(httpDone(const bool ,const QString,const QString )),this,SLOT(synced(bool ,QString,QString )));
}
void CutterSyncPrc::setGlobal(Global *global){
    this->global =global;
}
void CutterSyncPrc::run(){
    while (true){
        if (this->isProcessing == false){
            //Í¬²½ÊÚÈ¨
            this->checkMO();

        }

        //
        this->sleep(300);
    }
}


void CutterSyncPrc::handleMO(const QString &data){
    QMap<QString,QString> map;
    //map.insert("deviceid","13596034438");
    map.insert("sensorid","33");
    //map.insert("plcid","1");
    map.insert("assetid",this->global->assetId);

    map.insert("eid","1001000000");//global->eid);
    map.insert("data",data);
    QLocale lo(QLocale::Chinese);
    QDateTime d = QDateTime::currentDateTime();
    QString evtid(lo.toString(d,"yyyyMMddhhmmss"));
    map.insert("evtid",evtid);
    QUrl url(this->global->licUrl);

    qDebug()<<"url="<<url.host()<<endl;
    qDebug()<<"port="<<url.port()<<endl;

    http.post(url,map);

    this->isProcessing = true;
    map.clear();
    //emit handled(log->toString());
    qDebug()<<"process mo file...."<<evtid<<endl;
}

void CutterSyncPrc::checkMO(){
    QFile src(global->licPath+"hymo.log");
    QString str("");
    if (src.exists())
    {
        if (!src.open(QIODevice::ReadOnly)){
            //error to open the file
            //return null;
        }else{
            QByteArray bytes = src.readAll();
            //QTextCodec *codec = QTextCodec::codecForName("utf-8");
                str= bytes.toHex().data();//codec->toUnicode(bytes);//bytes.toHex();

             qDebug()<<str<<endl;
             src.close();
        }

    }
//    QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Yingroup\\CutterAgent",
//                         QSettings::NativeFormat);
//    reg->setIniCodec("utf-8");
//    str  = reg->value("hymo","").toString();
//    delete reg;
//        //QTextCodec *codec = QTextCodec::codecForName("utf-8");
//        //str=bytes.toHex();
//        qDebug()<<"debug bytes"<<str<<endl;

    this->handleMO(str);

}

void CutterSyncPrc::synced(bool ok,QString transid,QString result){
    if (ok){
       QFile src(global->licPath+"hymt.log");
       if (src.exists())
       {
           src.remove();
       }

            qDebug()<<"process mt file..1.."<<global->licPath<<endl;
       if (src.open(QIODevice::WriteOnly)){
            QByteArray data ;
            data = QByteArray::fromHex(result.toUtf8());//.toLocal8Bit());
            //QDataStream out(&src);
            //out<<data;

            src.write(data);

            src.close();

            qDebug()<<"process mt file..2.."<<result<<endl;
       }

       qDebug()<<"process mt file..3.."<<(src.error()== QFile::NoError)<<src.errorString()<<endl;
//        QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Yingroup\\CutterAgent",
//                             QSettings::NativeFormat);
//        reg->setValue("hymt",result);
//        qDebug()<<"process mt file..3.."<<reg->value("hymt").toString()<<endl;
//        delete reg;
    }
    QString str("synchronized...");
    str.append(ok).append("@").append(transid);
    this->isProcessing = false;
    emit handled(str);
}
