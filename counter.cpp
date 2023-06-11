#include "counter.h"


counter::counter(QObject *parent)
{
        qInfo()<<this<<" Constructed ";
}

counter::~counter()
{
    qInfo()<<this<<" Deconstructed ";
}

void counter::start()
{
    for(int i=0; i<10; i++){
        qInfo()<<QThread::currentThread()->objectName()<<" = "<<i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));
        QThread::msleep(value);
        qInfo()<<QThread::currentThread()->objectName()<<" Complete" ;
    }

    qInfo()<<this<<"complited";
    deleteLater();

    QThread::currentThread()->quit();
}
