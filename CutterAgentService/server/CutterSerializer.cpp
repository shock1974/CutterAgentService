#include "CutterSerializer.h"
#include "Utility.h"
CutterSerializer::CutterSerializer()
{
}

QString CutterSerializer::serialize(HYLicMT  &obj){
    return Utility::serialize(obj);
}

QString CutterSerializer::serialize(HYLicMO  &obj){
    return Utility::serialize(obj);
}

QString CutterSerializer::serialize(CutterAltLog  &obj){

    return Utility::serialize(obj);
}
QString CutterSerializer::serialize(CutterMonthlyRpt  &obj){
    return Utility::serialize(obj);
}
QString CutterSerializer::serialize(CutterDailyRpt  &obj){
    return Utility::serialize(obj);
}
QString CutterSerializer::serialize(CutterOptLog &obj){
    return Utility::serialize(obj);
}



HYLicMT* CutterSerializer::unserMTLicCmd(const QString &json, bool &ok){
    QObject* obj = new HYLicMT();
    Utility::unserialize(json,*obj,ok);
    HYLicMT* mt  = dynamic_cast<HYLicMT *>(obj);
    return mt;
}

HYLicMO* CutterSerializer::unserMOLicCmd(const QString &json, bool &ok){
    QObject* obj = new HYLicMT();
    Utility::unserialize(json,*obj,ok);
    HYLicMO* mo  = dynamic_cast<HYLicMO *>(obj);
    return mo;
}

CutterMonthlyRpt* CutterSerializer::unserCutterMonthlyRpt(const QString &json, bool &ok){

}

CutterAltLog* CutterSerializer::unserCutterAltLog(const QString &json, bool &ok){

}
CutterOptLog* CutterSerializer::unserCutterOptLog(const QString &json, bool &ok){

}

CutterDailyRpt* CutterSerializer::unserCutterDailyRpt(const QString &json, bool &ok){

}
