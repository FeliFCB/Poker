#include "cartastipo.h"

cartastipo::cartastipo()
{

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

void cartastipo::numeroytipocartas(int a, int b){

    infodecarta(a);
    numerocartas[0]=numero;
    tipocartas[0]=tipo;
    // QString num=QString::number(numero);
    // qDebug(num.toLatin1());
    // qDebug(tipo.toLatin1());


    infodecarta(b);
    numerocartas[1]=numero;
    tipocartas[1]=tipo;
    // num=QString::number(numero);
    // qDebug(num.toLatin1());
    // qDebug(tipo.toLatin1());

}
