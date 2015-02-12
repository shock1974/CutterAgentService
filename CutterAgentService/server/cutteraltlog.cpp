#include "cutteraltlog.h"
#include "CutterSerializer.h"
CutterAltLog::CutterAltLog(QObject *parent) :
    QObject(parent)
{
}
    QString CutterAltLog::toString(){
        QString result =  CutterSerializer::serialize(*this);
        return result;
    }

    void CutterAltLog::setS001(QString s){
        s001 =s;
    }

    QString CutterAltLog::getS001(){
        return s001;
    }


    void CutterAltLog::setS002(QString s){
        s002 =s;
    }

    QString CutterAltLog::getS002(){
        return s002;
    }


    void CutterAltLog::setS003(QString s){
        s003 =s;
    }

    QString CutterAltLog::getS003(){
        return s003;
    }
