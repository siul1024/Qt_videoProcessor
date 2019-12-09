#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include "mygpio.h"


class BlinkThread : public QThread
{
    Q_OBJECT

public:
    explicit BlinkThread(QObject *parent = 0)
    {

    }
private:

    void run() override
    {
        myGPIO::blink();
    }


};


#endif // MYTHREAD_H


