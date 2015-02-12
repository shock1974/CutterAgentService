#include "cutterdailyrpt.h"
#include "CutterSerializer.h"
CutterDailyRpt::CutterDailyRpt(QObject *parent) :
    QObject(parent)
{
}

QString CutterDailyRpt::toString(){
    QString result =  CutterSerializer::serialize(*this);
    return result;
}

void CutterDailyRpt::setS001(QString s){
    s001 =s;
}

QString CutterDailyRpt::getS001(){
    return s001;
}


void CutterDailyRpt::setS002(QString s){
    s002 =s;
}

QString CutterDailyRpt::getS002(){
    return s002;
}


void CutterDailyRpt::setS003(QString s){
    s003 =s;
}

QString CutterDailyRpt::getS003(){
    return s003;
}


void CutterDailyRpt::setS004(QString s){
    s004 =s;
}

QString CutterDailyRpt::getS004(){
    return s004;
}


void CutterDailyRpt::setS005(QString s){
    s005 =s;
}

QString CutterDailyRpt::getS005(){
    return s005;
}


void CutterDailyRpt::setS006(QString s){
    s006 =s;
}

QString CutterDailyRpt::getS006(){
    return s006;
}


void CutterDailyRpt::setS007(QString s){
    s007 =s;
}

QString CutterDailyRpt::getS007(){
    return s007;
}


void CutterDailyRpt::setS008(QString s){
    s008 =s;
}

QString CutterDailyRpt::getS008(){
    return s008;
}


