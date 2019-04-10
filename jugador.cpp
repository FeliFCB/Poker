#include "jugador.h"
#include <vector>
#include <string>
using namespace std;

jugador::jugador(){
    nombre = "Jugador";
    dinero = 5000;
    apuesta = 0;
    eliminado = false;
}


void jugador::nombrar(QString nuevonombre){
    nombre = nuevonombre;
}

int jugador::apostar(int subida){
    dinero = dinero - subida;
    apuesta = apuesta + subida;
    return subida;
}
