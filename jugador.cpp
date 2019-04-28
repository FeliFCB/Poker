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
}


void jugador::nombrar(QString nuevonombre){
    nombre = nuevonombre;
}

int jugador::apostar(int subida){
    dinero = dinero - subida;
    apuesta = apuesta + subida;
    return subida;
}

void jugador::obtenercartas(jugador player1, jugador player2){
    srand(time(NULL));
    vector <char[30]> imagenes{2};
    bool comprobacion = true;
    int aux;
    while (comprobacion){
        aux = 1+rand()%52;

        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux){
            comprobacion = false;
        }
    }
    cartas[0] = aux;
    comprobacion = true;
    while (comprobacion){
        aux = 1+rand()%52;
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && cartas[0] != aux){
            comprobacion = false;
        }
    }
    cartas[1] = aux;
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

void cartastipo::infodecarta(int a){
    if(a<14){
        numero=a;
        tipo="corazones";
    }else if (a<27) {
        numero=a-13;
        tipo="picas";
    }else if (a<40) {
        numero=a-26;
        tipo="diamantes";
    }else if (a<53) {
        numero=a-39;
        tipo="treboles";
    }

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
