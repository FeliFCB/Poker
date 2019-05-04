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
class cartaalta: public manos
{
public:
    void comprobarmano();
};

class pareja: public manos
{
public:
    pareja();
    void comprobarmano();
    bool parejaj1;
    bool parejaj2;
    bool parejaj3;
private:
    int valor;

};

class doblepareja: public manos
{
public:
    doblepareja();
    void comprobarmano();
private:
    int valor;
};

class trio: public manos
{
public:
    trio();
    void comprobarmano();
    bool trioj1;
    bool trioj2;
    bool trioj3;
private:
    int valor;
};

class escalera: public manos
{
public:
    escalera();
    void comprobarmano();
private:
    int valor;
};

class color: public manos
{
public:
    color();
    void comprobarmano();
private:
    int valor;
};

class full: public pareja, public trio
{
public:
    full();
    void comprobarmano();
private:
    int valor;
};

class poker: public manos
{
public:
    poker();
    void comprobarmano();
private:
    int valor;
};

class escaleradecolor: public color, public escalera
{
public:
    void comprobarmano();
private:
    int valor;
};
