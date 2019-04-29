#include "jugador.h"
#include <vector>
#include <string>
#include <mesa.h>
#include "mesa.h"
using namespace std;

jugador::jugador(){
    nombre = "Jugador";
    dinero = 5000;
    apuesta = 0;
    eliminado = false;
    cartas[0] = 0;
    cartas[1] = 0;
}


void jugador::nombrar(QString nuevonombre){
    nombre = nuevonombre;
}

int jugador::apostar(int subida){
    dinero = dinero - subida;
    apuesta = apuesta + subida;
    return subida;
}

void jugador::obtenercartas(int carta1, int carta2, int carta3, int carta4){
    qDebug("LOS OTROS 2 JUGADORES:");
    qDebug("Primer jugador: %d    %d", carta1, carta2);
    qDebug("Segundo jugador: %d    %d", carta3, carta4);
    srand(time(NULL));
    vector <char[30]> imagenes{2};
    bool comprobacion = true;
    int aux;
    while (comprobacion){
        aux = 1+rand()%52;

        if (carta1 != aux && carta2 != aux && carta3 != aux && carta4 != aux){
            comprobacion = false;
        }
    }
    cartas[0] = aux;
    comprobacion = true;
    while (comprobacion){
        aux = 1+rand()%52;
        if (carta1 != aux && carta2 != aux && carta3 != aux && carta4 != aux && cartas[0] != aux){
            comprobacion = false;
        }
    }
    cartas[1] = aux;
    qDebug("EL JUGADOR RECIBE: %d    %d", cartas[0], cartas[1]);
    qDebug("------------------");
}

int jugador::devolverdinero(){
    return dinero;
}

int jugador::devolverapuesta(){
    return apuesta;
}

QString jugador::devolvernombre(){
    return nombre;
}

bool jugador::devolvereliminado(){
    return eliminado;
}



void jugador::numeroytipocartas(){
 int aux=cartas[1];

    infodecarta(cartas[0]);
    numerocartas[0]=numero;
    tipocartas[0]=tipo;
       QString num=QString::number(numero);
        qDebug(num.toLatin1());
        qDebug(tipo.toLatin1());


    infodecarta(aux);
    numerocartas[1]=numero;
    tipocartas[1]=tipo;
        num=QString::number(numero);
        qDebug(num.toLatin1());
        qDebug(tipo.toLatin1());

}
