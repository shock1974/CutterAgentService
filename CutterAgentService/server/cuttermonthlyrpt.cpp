#include "cuttermonthlyrpt.h"
#include "CutterSerializer.h"
CutterMonthlyRpt::CutterMonthlyRpt(QObject *parent) :
    QObject(parent)
{
}
QString CutterMonthlyRpt::toString(){
    QString result =  CutterSerializer::serialize(*this);
    return result;
}
void CutterMonthlyRpt::setS001(QString s){
    s001 =s;
}

QString CutterMonthlyRpt::getS001(){
    return s001;
}


void CutterMonthlyRpt::setS002(QString s){
    s002 =s;
}

QString CutterMonthlyRpt::getS002(){
    return s002;
}


void CutterMonthlyRpt::setS003(QString s){
    s003 =s;
}

QString CutterMonthlyRpt::getS003(){
    return s003;
}


void CutterMonthlyRpt::setS004(QString s){
    s004 =s;
}

QString CutterMonthlyRpt::getS004(){
    return s004;
}


void CutterMonthlyRpt::setS005(QString s){
    s005 =s;
}

QString CutterMonthlyRpt::getS005(){
    return s005;
}


void CutterMonthlyRpt::setS006(QString s){
    s006 =s;
}

QString CutterMonthlyRpt::getS006(){
    return s006;
}


void CutterMonthlyRpt::setS007(QString s){
    s007 =s;
}

QString CutterMonthlyRpt::getS007(){
    return s007;
}


void CutterMonthlyRpt::setS008(QString s){
    s008 =s;
}

QString CutterMonthlyRpt::getS008(){
    return s008;
}



void CutterMonthlyRpt::setS009(QString s){
    s009 =s;
}

QString CutterMonthlyRpt::getS009(){
    return s009;
}
