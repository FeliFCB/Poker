#include "manos.h"
#include<QDebug>

manos::manos()
{


}

pareja::pareja(){
    valor = 15;
}
void pareja::espareja(){
//     int carta1=player1.numerocartas[1];
//     int carta2=player1.numerocartas[0];
//     int carta3=mesa1.numerocartas[4];
//     int carta4=mesa1.numerocartas[3];
//     int carta5=mesa1.numerocartas[2];
//     int carta6=mesa1.numerocartas[1];
//     int carta7=mesa1.numerocartas[0];
    vector<int>cartas{7};
    cartas={jugador1.numerocartas[0],jugador1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
    vector<int> cartasaux=cartas;
    qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
//    int pareja = 0;
    int cartaalta = 0;
//     vector<int> comb1={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2]};
//     vector<int> comb2={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3]};
//     vector<int> comb3={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[4]};
//     vector<int> comb4={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//     vector<int> comb5={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//     vector<int> comb6={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb7={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//     vector<int> comb8={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//     vector<int> comb9={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb10={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb11{player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//     vector<int> comb12{player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//     vector<int> comb13={player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb14={player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb15={player1.numerocartas[0], mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb16={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//     vector<int> comb17={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//     vector<int> comb18={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb19={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb20={player1.numerocartas[1], mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//     vector<int> comb21={mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
    int iguales;
    int aux;

    for (unsigned long long i = 0; i < 6; i++) {
        iguales = 0;
        for (unsigned long long j = i + 1; j < 7; j++) {
            if (cartas[i] == cartasaux[j]){
                cartasaux[j] = 0;
                iguales += 1;
                aux = cartas[i];
                if (aux == 1) aux = 14;
                if (cartaalta < aux) cartaalta = aux;
            }
        }
        if (iguales == 1 && jugador1.valor_mano < valor){
            jugador1.cartaalta = cartaalta;
            jugador1.valor_mano = valor;
            jugador1.nombremano = "pareja";
        }
    }



    cartas={jugador2.numerocartas[0],jugador2.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
    cartasaux = cartas;
    cartaalta = 0;
    for (unsigned long long i = 0; i < 6; i++) {
        iguales = 0;
        for (unsigned long long j = i + 1; j < 7; j++) {
            if (cartas[i] == cartasaux[j]){
                cartasaux[j] = 0;
                iguales += 1;
                aux = cartas[i];
                if (aux == 1) aux = 14;
                if (cartaalta < aux) cartaalta = aux;
            }
        }
        if (iguales == 1 && jugador2.valor_mano < valor){
            jugador2.cartaalta = cartaalta;
            jugador2.valor_mano = valor;
            jugador2.nombremano = "pareja";
        }
    }



    cartas={jugador3.numerocartas[0],jugador3.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
    cartasaux = cartas;
    cartaalta = 0;
    for (unsigned long long i = 0; i < 6; i++) {
        iguales = 0;
        for (unsigned long long j = i + 1; j < 7; j++) {
            if (cartas[i] == cartasaux[j]){
                cartasaux[j] = 0;
                iguales += 1;
                aux = cartas[i];
                if (aux == 1) aux = 14;
                if (cartaalta < aux) cartaalta = aux;
            }
        }
        if (iguales == 1 && jugador3.valor_mano < valor){
            jugador3.cartaalta = cartaalta;
            jugador3.valor_mano = valor;
            jugador3.nombremano = "pareja";
        }
    }
    qDebug("La carta alta es %d", cartaalta);
//    qDebug("El valor de mano que se la ha dado al jugador es %d", jugador1.devolvervalor_mano());
//    qDebug("El valor de mano que tiene el jugador 1 es %d", jugador1.devolvervalor_mano());
//    qDebug("El valor de mano que tiene el jugador 2 es %d", jugador2.devolvervalor_mano());
//    qDebug("El valor de mano que tiene el jugador 3 es %d", jugador3.devolvervalor_mano());
//    if(pareja==1){
//        player1.valor_mano=10;
//    }
//    else if (pareja==2) {
//        player1.valor_mano=20;
//    }
//    else if (pareja==3) {
//        player1.valor_mano=30;
//    }
//    QString num1=QString::number(iguales);
//    qDebug(num1.toLatin1());
//    QString num=QString::number(player1.valor_mano);
//    qDebug(num.toLatin1());

}


void trio::estrio(jugador player1){

}
