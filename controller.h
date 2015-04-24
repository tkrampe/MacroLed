#ifndef CONTROLLER
#define CONTROLLER

#include "androidrfcomm.h"
#include <QColor>

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor color WRITE setColor)

public:
    Controller();
    ~Controller();
    Q_INVOKABLE void makeRed();
    Q_INVOKABLE void makeBlue();
    Q_INVOKABLE void makeGreen();
    Q_INVOKABLE void makeWhite();
    Q_INVOKABLE void turnOff();

    void setColor(QColor clr);
private:
    AndroidRfComm rfcomm;
};

#endif // CONTROLLER

