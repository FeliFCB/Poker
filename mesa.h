#ifndef MESA_H
#define MESA_H
#include <vector>
#include <jugador.h>
#include <stdlib.h>

using namespace std;

class mesa
{
public:
    mesa();
    void actualizarbote();
    void repartir123();
    void repartir4();
    void repartir5();
    int devolverbote();
    int devolverturno();
    int sumarturno();
    bool nuevafase;
    int fase;
    int jugada;
    vector <int> cartas{5};
private:
    int turno;
    int bote;
};

#endif // MESA_H
