#include "HYLicMT.h"

#include "CutterSerializer.h"
HYLicMT::HYLicMT()
{
}
QString HYLicMT::toString(){
    QString result =  CutterSerializer::serialize(*this);
    return result;
}

void HYLicMT::setS001(QString s){
    s001 =s;
}

QString HYLicMT::getS001(){
    return s001;
}


void HYLicMT::setS002(QString s){
    s002 =s;
}

QString HYLicMT::getS002(){
    return s002;
}


void HYLicMT::setS003(QString s){
    s003 =s;
}

QString HYLicMT::getS003(){
    return s003;
}
