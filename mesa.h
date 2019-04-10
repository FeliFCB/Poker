#ifndef MESA_H
#define MESA_H
#include <vector>
#include <juego.h>
#include <jugador.h>
#include <stdlib.h>

using namespace std;

class mesa
{
public:
    mesa();
    void sumarbote(int apuesta, jugador player);
    void repartir3(jugador player1, jugador player2, jugador player3);
    void repartir4(jugador player1, jugador player2, jugador player3);
    void repartir5(jugador player1, jugador player2, jugador player3);

private:
    int bote;
    vector <int> cartas;
};

#endif // MESA_H
