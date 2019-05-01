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
