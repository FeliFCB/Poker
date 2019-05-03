#ifndef MANOS_H
#define MANOS_H

#include <QString>
#include <mesa.h>

extern jugador jugador1;
extern jugador jugador2;
extern jugador jugador3;
extern mesa mesa1;
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
    pareja();
    void espareja();
private:
    int valor;

};

class doblepareja: public manos
{
public:
    void esdoblepareja(jugador player1);
private:
    int valor;
};

class trio: public manos
{
public:
    trio();
    void estrio(jugador player1);
private:
    int valor;
};

class escalera: public manos
{
public:
    escalera();
    void esescalera(jugador player1);
private:
    int valor;
};

class color: public manos
{
public:
    void escolor(jugador player1);
private:
    int valor;
};

class full: public pareja, public trio
{
public:
    void esfull(jugador player1);
private:
    int valor;
};

class poker: public manos
{
public:
    poker();
    void espoker(jugador player1);
private:
    int valor;
};

class escaleradecolor: public color, public escalera
{
public:
    void esescaleradecolor(jugador player1);
private:
    int valor;
};
