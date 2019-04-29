#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
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
    void numeroytipocartas();
    vector <int> numerocartas{2};
    vector <QString> tipocartas{2};


private:
    QString nombre;
    int dinero;
    int apuesta;
    bool eliminado;

};

#endif // JUGADOR_H
