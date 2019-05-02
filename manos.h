#ifndef MANOS_H
#define MANOS_H

#include <QString>
#include <jugador.h>
#include <mesa.h>
class manos
{
public:
    manos();
    QString _mano;
    int rango;
};

#endif // MANOS_H

class pareja: public manos
{
public:
    void espareja(jugador player1, mesa mesa1);

};

