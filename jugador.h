#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include <QString>

using namespace std;

class jugador{

public:
    jugador();
    void nombrar(QString nuevonombre);
    int apostar(int subida);

private:
    QString nombre;
    int dinero;
    vector <int> cartas;
    int apuesta;
    bool eliminado;

};

#endif // JUGADOR_H
