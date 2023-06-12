#include "manager.h"

manager::manager()
{
    for(int i=0;i<5;i++){

        QThread *thread  = new QThread(this);
        thread->setObjectName("Thread "+ QString::number(i));
        qInfo()<<"Created "<<thread->objectName();
        connect(thread, &QThread::started, this, &manager::started);
        connect(thread, &QThread::finished, this, &manager::finished);
        threads.append(thread);
    }

}

void manager::start()
{
    qInfo()<<"Started.....";
    foreach(QThread *thread, threads){
        counter *c = new counter();
        c->moveToThread(thread);
        connect(thread, &QThread::started, c, &counter::start);
        thread->start();
    }

}

void manager::started()
{
    qInfo()<<"Staring "<<sender();
    QThread *thread = qobject_cast<QThread*>(sender());
    if(!thread) return;
    qInfo()<<"Started "<<thread->objectName();
}

void manager::finished()
{
    qInfo()<<"Finishing "<<sender();
    QThread *thread = qobject_cast<QThread*>(sender());
    if(!thread) return;
    qInfo()<<"Children "<<thread->children().length();
    qInfo()<<"Finished "<<thread->objectName();

    threads.removeAll(thread);
    delete thread;
}
