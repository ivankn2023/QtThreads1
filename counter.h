#ifndef COUNTER_H
#define COUNTER_H

#include "QObject"
#include "QThread"
#include "QTimer"
#include "QDebug"
#include "QRandomGenerator"
class counter:public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);
    ~counter();
public slots:
    void start();
};

#endif // COUNTER_H
