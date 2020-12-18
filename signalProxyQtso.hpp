#ifndef SIGNALPROXTQTSO_SIGNAL_H_
#define SIGNALPROXTQTSO_SIGNAL_H_

#include "crossPlatformMacros.hpp"

#include <QObject>

namespace signalso
{
//creating an object of this class uses 1 thread from threadedFunction_c
class EXPIMP_SIGNALPROXYQTSO signalProxy_c : public QObject
{
    Q_OBJECT

    void monitorSignal_f();

public:
    signalProxy_c(QObject* parent_par);
Q_SIGNALS:
    void signalTriggered_signal(int signalNumber);
};

//needs to be initialized
extern EXPIMP_SIGNALPROXYQTSO signalProxy_c* signalProxy_ptr_ext;

}

#endif /* SIGNALPROXTQTSO_SIGNAL_H_ */
