#include "mesa.h"
extern jugador jugador1;
extern jugador jugador2;
extern jugador jugador3;
extern mesa mesa1;

mesa::mesa()
{
    bote = 0;
    turno = 0;
    fase = 1;
    jugada = 1;
    nuevafase = false;
}

void mesa::actualizarbote(){
    bote = jugador1.devolverapuesta() + jugador2.devolverapuesta() + jugador3.devolverapuesta();
}

void mesa::repartir123(){
    bool comprobacion = true;
    int aux;
    while (comprobacion){
        aux = 1+rand()%52;
        if (jugador1.cartas[0] != aux && jugador1.cartas[1] != aux && jugador2.cartas[0] != aux && jugador2.cartas[1] != aux && jugador3.cartas[0] != aux && jugador3.cartas[1] != aux){
            comprobacion = false;
        }
    }
    cartas[0] = aux;
    comprobacion = true;
    while (comprobacion){
        aux = 1+rand()%52;
        if (jugador1.cartas[0] != aux && jugador1.cartas[1] != aux && jugador2.cartas[0] != aux && jugador2.cartas[1] != aux && jugador3.cartas[0] != aux && jugador3.cartas[1] != aux && cartas[0] != aux){
            comprobacion = false;
        }
    }
    cartas[1] = aux;
    comprobacion = true;
    while (comprobacion){
        aux = 1+rand()%52;
        if (jugador1.cartas[0] != aux && jugador1.cartas[1] != aux && jugador2.cartas[0] != aux && jugador2.cartas[1] != aux && jugador3.cartas[0] != aux && jugador3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux){
            comprobacion = false;
        }
    }
    cartas[2] = aux;
}

void mesa::repartir4(){
    bool comprobacion = true;
    int aux;
    while (comprobacion){
        aux = 1+rand()%52;
        if (jugador1.cartas[0] != aux && jugador1.cartas[1] != aux && jugador2.cartas[0] != aux && jugador2.cartas[1] != aux && jugador3.cartas[0] != aux && jugador3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux && cartas[2] != aux){
            comprobacion = false;
        }
    }
    cartas[3] = aux;
}

void mesa::repartir5(){
    bool comprobacion = true;
    int aux;
    while (comprobacion){
        aux = 1+rand()%52;
        if (jugador1.cartas[0] != aux && jugador1.cartas[1] != aux && jugador2.cartas[0] != aux && jugador2.cartas[1] != aux && jugador3.cartas[0] != aux && jugador3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux && cartas[2] != aux && cartas[3] != aux){
            comprobacion = false;
        }
    }
    cartas[4] = aux;
}

int mesa::devolverbote(){
    return bote;
}

int mesa::devolverturno(){
    return turno;
}

int mesa::sumarturno(){
    switch (turno) {
    case 2:
        if (jugador3.devolvereliminado()) turno = 1;
        else turno = 3;
        break;

    case 3:
        if (jugador1.devolvereliminado()) turno = 2;
        else turno = 1;
        break;

    default:
        if (jugador2.devolvereliminado()) turno = 3;
        else turno = 2;
        break;
    }

    if (turno == jugada){
        fase++;
        nuevafase = true;
    }
    else nuevafase = false;
    return turno;
}
