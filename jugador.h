#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <QString>
#include <time.h>
#include <cartastipo.h>

using namespace std;

class jugador:public cartastipo
{

public:
    jugador();
    void nombrar(QString nuevonombre);
    int apostar(int subida);
    vector <int> cartas{2};
    void obtenercartas(int carta1, int carta2, int carta3, int carta4);
    int devolverdinero();
    int devolverapuesta();
    QString devolvernombre();
    bool devolvereliminado();
    bool devolverretirado();
    void sumardinero(int bote);
    void reset_variables();
    void retirarse();
//    void numeroytipocartas();
//    vector <int> numerocartas{2};
//    vector <QString> tipocartas{2};
    cartastipo cartastipo1;
    QString nombremano;
    int cartaalta;
    int valor_mano;

private:
    QString nombre;
    int dinero;
    int apuesta;
    bool eliminado;
    bool retirado;

};

#endif // JUGADOR_H
