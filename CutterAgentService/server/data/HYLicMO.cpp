#include "HYLicMO.h"
#include "CutterSerializer.h"
HYLicMO::HYLicMO()
{
}

QString HYLicMO::toString(){
    QString result =  CutterSerializer::serialize(*this);
    return result;
 }

 void HYLicMO::setS001(QString s){
     s001 =s;
 }

 QString HYLicMO::getS001(){
     return s001;
 }


 void HYLicMO::setS002(QString s){
     s002 =s;
 }

 QString HYLicMO::getS002(){
     return s002;
 }


 void HYLicMO::setS003(QString s){
     s003 =s;
 }

 QString HYLicMO::getS003(){
     return s003;
 }


 void HYLicMO::setS004(QString s){
     s004 =s;
 }

 QString HYLicMO::getS004(){
     return s004;
 }


 void HYLicMO::setS005(QString s){
     s005 =s;
 }

 QString HYLicMO::getS005(){
     return s005;
 }


 void HYLicMO::setS006(QString s){
     s006 =s;
 }

 QString HYLicMO::getS006(){
     return s006;
 }
