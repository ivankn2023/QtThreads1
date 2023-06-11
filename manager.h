#ifndef MANAGER_H
#define MANAGER_H

#include "QObject"
#include "QThread"
#include "QTimer"
#include "QDebug"
#include "QList"
#include "counter.h"
class manager:public QObject
{
    Q_OBJECT
public:
    manager();
    void start();
public slots:
    void started();
    void finished();

private:
    QList<QThread*> threads;
};

#endif // MANAGER_H
