#include "mesa.h"
#include <QDebug>
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
    nuevafase = false;
    switch (turno) {
    case 2:
        if (jugador3.devolverretirado()){
            turno = 1;
            if(jugada == 3){
                fase++;
                nuevafase = true;
            }
        }
        else turno = 3;
        break;

    case 3:
        if (jugador1.devolverretirado()){
            turno = 2;
            if (jugada == 1){
                fase++;
                nuevafase = true;
            }
        }
        else turno = 1;
        break;

    default:
        if (jugador2.devolverretirado()){
            turno = 3;
            if (jugada == 2){
                fase++;
                nuevafase = true;
            }
        }
        else turno = 2;
        break;
    }

    if ((turno == jugada) && (jugador1.devolverapuesta() >= max(jugador2.devolverapuesta(), jugador3.devolverapuesta()) || jugador1.devolverretirado()) && (jugador2.devolverapuesta() >= max(jugador1.devolverapuesta(), jugador3.devolverapuesta()) || jugador2.devolverretirado()) && jugador3.devolverapuesta() >= max(jugador1.devolverapuesta(), jugador2.devolverapuesta()) || jugador3.devolverretirado()){
        fase++;
        nuevafase = true;
    }
    return turno;
}




void mesa::numeroytipocartas(){
 qDebug("abierto");
QString num1=QString::number(cartas[4]);
qDebug(num1.toLatin1());
//int aux=cartas[4];

    unsigned int i=0;
    while (i<5) {


    infodecarta(cartas[i]);
    numerocartas[i]=numero;
    tipocartas[i]=tipo;
       QString num=QString::number(numero);
        qDebug(num.toLatin1());
        qDebug(tipo.toLatin1());
        i+=1;
}

//    infodecarta(aux);
//    numerocartas[4]=numero;
//    tipocartas[4]=tipo;
//       QString num=QString::number(numero);
//        qDebug(num.toLatin1());
//        qDebug(tipo.toLatin1());

}
