#include "manos.h"
#include<QDebug>

manos::manos()
{


}

pareja::pareja(){
    valor = 15;
}
void pareja::comprobarmano(){
//     int carta1=player1.numerocartas[1];
//     int carta2=player1.numerocartas[0];
//     int carta3=mesa1.numerocartas[4];
//     int carta4=mesa1.numerocartas[3];
//     int carta5=mesa1.numerocartas[2];
//     int carta6=mesa1.numerocartas[1];
//     int carta7=mesa1.numerocartas[0];
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

    vector<int>cartas{7};
    vector<int> cartasaux;
    int cartaalta = 0;
    int iguales;
    int aux;
    if (!jugador1.devolverretirado() && !jugador1.devolvereliminado()){
        cartas={jugador1.numerocartas[0],jugador1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
    //    int pareja = 0;

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
            if (iguales == 1 && jugador1.valor_mano <= valor){
                jugador1.cartaalta = cartaalta;
                jugador1.valor_mano = valor;
                jugador1.nombremano = "pareja";
            }
        }
    }




    if (!jugador2.devolverretirado() && !jugador2.devolvereliminado()){
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
            if (iguales == 1 && jugador2.valor_mano <= valor){
                jugador2.cartaalta = cartaalta;
                jugador2.valor_mano = valor;
                jugador2.nombremano = "pareja";
            }
        }
    }




    if (!jugador3.devolverretirado() && !jugador3.devolvereliminado()){
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
            if (iguales == 1 && jugador3.valor_mano <= valor){
                jugador3.cartaalta = cartaalta;
                jugador3.valor_mano = valor;
                jugador3.nombremano = "pareja";
            }
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

trio::trio(){
    valor=40;
}
void trio::comprobarmano(){
    vector<int>cartas{7};
    vector<int> cartasaux;
    int cartaalta = 0;
    int iguales;
    int aux;
    if (!jugador1.devolverretirado() && !jugador1.devolvereliminado()){
        cartas={jugador1.numerocartas[0],jugador1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);

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
            if (iguales == 2 && jugador1.valor_mano <= valor){
                jugador1.cartaalta = cartaalta;
                jugador1.valor_mano = valor;
                jugador1.nombremano = "trio";
            }
        }
    }




    if (!jugador2.devolverretirado() && !jugador3.devolvereliminado()){
        cartas={jugador2.numerocartas[0],jugador2.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
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
            if (iguales == 2 && jugador2.valor_mano <= valor){
                jugador2.cartaalta = cartaalta;
                jugador2.valor_mano = valor;
                jugador2.nombremano = "trio";
            }
        }
    }




    if (!jugador3.devolverretirado() && !jugador3.devolvereliminado()){
        cartas={jugador3.numerocartas[0],jugador3.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
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
            if (iguales == 2 && jugador3.valor_mano <= valor){
                jugador3.cartaalta = cartaalta;
                jugador3.valor_mano = valor;
                jugador3.nombremano = "trio";
            }
        }
    }

}

poker::poker(){
    valor=60;
}

void poker::comprobarmano(){
    vector<int>cartas{7};
    vector<int> cartasaux;
    int cartaalta = 0;
    int iguales;
    int aux;
    if (!jugador1.devolverretirado() && !jugador1.devolvereliminado()){
        cartas={jugador1.numerocartas[0],jugador1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);

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
            if (iguales == 3 && jugador1.valor_mano <= valor){
                jugador1.cartaalta = cartaalta;
                jugador1.valor_mano = valor;
                jugador1.nombremano = "poker";
            }
        }
    }




    if (!jugador2.devolverretirado() && !jugador3.devolvereliminado()){
        cartas={jugador2.numerocartas[0],jugador2.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
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
            if (iguales == 3 && jugador2.valor_mano <= valor){
                jugador2.cartaalta = cartaalta;
                jugador2.valor_mano = valor;
                jugador2.nombremano = "poker";
            }
        }
    }




    if (!jugador3.devolverretirado() && !jugador3.devolvereliminado()){
        cartas={jugador3.numerocartas[0],jugador3.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        cartasaux=cartas;
        qDebug("Las cartas a comparar son %d %d %d %d %d %d %d",cartas[0],cartas[1],cartas[2],cartas[3],cartas[4],cartas[5],cartas[6]);
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
            if (iguales == 3 && jugador3.valor_mano <= valor){
                jugador3.cartaalta = cartaalta;
                jugador3.valor_mano = valor;
                jugador3.nombremano = "poker";
            }
        }
    }

}
escalera::escalera(){
    valor = 45;
}
void escalera::comprobarmano(){
    vector<int>cartas{7};
    vector<int>escaleramasalta{5};
    vector<int>escalera{5};
    int s;
    unsigned long long pos;
    int cartaalta=0;
    int hay_escalera=0;
    if (!jugador1.devolverretirado() && !jugador1.devolvereliminado()){
        cartas={jugador1.numerocartas[0],jugador1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        for (unsigned long long k = 0; k < 6; k++){
            if (cartas[k]==1){
                cartas[k]=14;
            }
        }
        for (unsigned long long i = 0; i < 6; i++){
            s=1;
            escalera={0,0,0,0,0};
            escalera[1]=cartas[i];
            for (unsigned long long j = 0; j < 6; j++){
                if((cartas[i]==cartas[j]-1) || (cartas[i]==cartas[j]-2)||(cartas[i]==cartas[j]-3) || (cartas[i]==cartas[j]-4)){
                    pos=cartas[j]-cartas[i];
                    if(escalera[pos+1]==0){
                        escalera[pos+1]=cartas[j];
                        s+=1;
                    }
                }
            }

            if(s>=5 && escalera[4]>cartaalta){
                escaleramasalta=escalera;
                cartaalta=escalera[4];
                hay_escalera=1;

            }
        }
        if ( hay_escalera== 1 && jugador1.valor_mano < valor){
            jugador1.cartaalta = cartaalta;
            jugador1.valor_mano = valor;
            jugador1.nombremano = "escalera";
        }
    }




    if (!jugador2.devolverretirado() && !jugador2.devolvereliminado()){
        cartas={jugador2.numerocartas[0],jugador2.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        for (unsigned long long k = 0; k < 6; k++){
            if (cartas[k]==1){
                cartas[k]=14;
            }
        }
        cartaalta=0;
        hay_escalera=0;
        for (unsigned long long i = 0; i < 6; i++){
            s=1;
            escalera={0,0,0,0,0};
            escalera[1]=cartas[i];
            for (unsigned long long j = 0; j < 6; j++){
                if((cartas[i]==cartas[j]-1) || (cartas[i]==cartas[j]-2)||(cartas[i]==cartas[j]-3) || (cartas[i]==cartas[j]-4)){
                    pos=cartas[j]-cartas[i];
                    if(escalera[pos+1]==0){
                        escalera[pos+1]=cartas[j];
                        s+=1;
                    }
                }
            }

            if(s>=5 && escalera[4]>cartaalta){
                escaleramasalta=escalera;
                cartaalta=escalera[4];
                hay_escalera=1;

            }
        }
        if ( hay_escalera== 1 && jugador2.valor_mano < valor){
            jugador2.cartaalta = cartaalta;
            jugador2.valor_mano = valor;
            jugador2.nombremano = "escalera";
        }
    }



    if (!jugador3.devolverretirado() && !jugador3.devolvereliminado()){
        cartas={jugador3.numerocartas[0],jugador3.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
        for (unsigned long long k = 0; k < 6; k++){
            if (cartas[k]==1){
                cartas[k]=14;
            }
        }
        cartaalta=0;
        hay_escalera=0;
        for (unsigned long long i = 0; i < 6; i++){
            s=1;
            escalera={0,0,0,0,0};
            escalera[1]=cartas[i];
            for (unsigned long long j = 0; j < 6; j++){
                if((cartas[i]==cartas[j]-1) || (cartas[i]==cartas[j]-2)||(cartas[i]==cartas[j]-3) || (cartas[i]==cartas[j]-4)){
                    pos=cartas[j]-cartas[i];
                    if(escalera[pos+1]==0){
                        escalera[pos+1]=cartas[j];
                        s+=1;
                    }
                }
            }

            if(s>=5 && escalera[4]>cartaalta){
                escaleramasalta=escalera;
                cartaalta=escalera[4];
                hay_escalera=1;

            }
        }
        if ( hay_escalera== 1 && jugador3.valor_mano < valor){
            jugador3.cartaalta = cartaalta;
            jugador3.valor_mano = valor;
            jugador3.nombremano = "escalera";
        }
    }

}
