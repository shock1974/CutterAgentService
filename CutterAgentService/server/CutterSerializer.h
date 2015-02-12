#ifndef CUTTERSERIALIZER_H
#define CUTTERSERIALIZER_H

#include "cuttermonthlyrpt.h"
#include "cutterdailyrpt.h"
#include "CutterAltLog.h"
#include "cutteroptlog.h"
#include "data/HYLicMO.h"
#include "data/HYLicMT.h"

class CutterSerializer
{
public:
    CutterSerializer();
    static QString serialize(HYLicMT  &obj);
    static QString serialize(HYLicMO  &obj);
    static QString serialize(CutterAltLog  &obj);
    static QString serialize(CutterOptLog  &obj);
    static QString serialize(CutterMonthlyRpt  &obj);
    static QString serialize(CutterDailyRpt  &obj);
    static HYLicMT* unserMTLicCmd(const QString &json, bool &ok);
    static HYLicMO* unserMOLicCmd(const QString &json, bool &ok);
    static CutterMonthlyRpt* unserCutterMonthlyRpt(const QString &json, bool &ok);
    static CutterAltLog* unserCutterAltLog(const QString &json, bool &ok);
    static CutterOptLog* unserCutterOptLog(const QString &json, bool &ok);
    static CutterDailyRpt* unserCutterDailyRpt(const QString &json, bool &ok);
};

#endif // CUTTERSERIALIZER_H
