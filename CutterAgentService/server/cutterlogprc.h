#ifndef CUTTERLOGPRC_H
#define CUTTERLOGPRC_H

#include <QThread>

class CutterLogPrc : public QThread
{
    Q_OBJECT
public:
    explicit CutterLogPrc(QObject *parent = 0);

signals:

public slots:

};

#endif // CUTTERLOGPRC_H
