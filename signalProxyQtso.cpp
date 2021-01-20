#include "signalProxyQtso.hpp"

#include "signalso/signal.hpp"
#include "threadedFunctionQtso/threadedFunctionQt.hpp"

#include <QCoreApplication>

#ifdef DEBUGJOUVEN
//#include "backwardSTso/backward.hpp"
//#include "comuso/loggingMacros.hpp"
//#include <iostream>
//#include <cstring>
#endif


namespace signalso
{

signalProxy_c* signalProxy_ptr_ext = nullptr;

void signalProxy_c::monitorSignal_f()
{
    while (not signalso::isTheEnd_f() and not quitting_pri)
    {
    }
    if (signalso::isTheEnd_f())
    {
        Q_EMIT signalTriggered_signal(signalso::signalNumber_f());
    }
}

signalProxy_c::signalProxy_c(QObject* parent_par)
 : QObject(parent_par)
{
    threadedFunction_c* threadedFunction_ptr(new threadedFunction_c(std::bind(&signalProxy_c::monitorSignal_f, this), true));
    QObject::connect(threadedFunction_ptr, &threadedFunction_c::finished, threadedFunction_ptr, &threadedFunction_c::deleteLater);
    QObject::connect(this, &signalProxy_c::signalTriggered_signal, threadedFunction_ptr, &threadedFunction_c::quit);
    QObject::connect(qApp, &QCoreApplication::aboutToQuit, threadedFunction_ptr, &threadedFunction_c::deleteLater);
    threadedFunction_ptr->start();
}

void signalProxy_c::setQuitting_f()
{
    quitting_pri = true;
}

}

