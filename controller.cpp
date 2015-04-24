#include "controller.h"

Controller::Controller()
{
    rfcomm.connect("LED");
}

Controller::~Controller()
{
    rfcomm.disconnect();
}

void Controller::makeRed()
{
    QByteArray pixels(48, 0);
    QByteArray on(1, 255);

    for(int i=0; i<48; i+=3)
        pixels.replace(i, 1, on);

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}

void Controller::makeGreen()
{
    QByteArray pixels(48, 0);
    QByteArray on(1, 255);

    for(int i=1; i<48; i+=3)
        pixels.replace(i, 1, on);

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}

void Controller::makeBlue()
{
    QByteArray pixels(48, 0);
    QByteArray on(1, 255);

    for(int i=2; i<48; i+=3)
        pixels.replace(i, 1, on);

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}

void Controller::makeWhite()
{
    QByteArray pixels(48, 255);

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}

void Controller::turnOff()
{
    QByteArray pixels(48, 0);

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}

void Controller::setColor(QColor clr)
{
    QByteArray pixels(48, 0);
    QByteArray r(1, (char)clr.red());
    QByteArray g(1, (char)clr.green());
    QByteArray b(1, (char)clr.blue());

    for(int i=0; i<48; i+=3)
    {
        pixels.replace(i, 1, r);
        pixels.replace(i+1, 1, g);
        pixels.replace(i+2, 1, b);
    }

    if (rfcomm.isConnected()) {
        rfcomm.send(pixels);
    }
}


