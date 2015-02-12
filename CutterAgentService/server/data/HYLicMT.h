#ifndef HYLICMT_H
#define HYLICMT_H

#include <QObject>

class HYLicMT : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString s001 READ getS001 WRITE setS001)
    Q_PROPERTY(QString s002 READ getS002 WRITE setS002)
    Q_PROPERTY(QString s003 READ getS003 WRITE setS003)

public:
    explicit HYLicMT();
    QString toString();
    void setS001(QString s);
    QString getS001();
    void setS002(QString s);
    QString getS002();
    void setS003(QString s);
    QString getS003();
private:
    QString s001;
    QString s002;
    QString s003;
signals:

public slots:

};

#endif // HYLICMT_H
