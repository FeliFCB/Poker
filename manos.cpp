#include "manos.h"
#include<QDebug>

manos::manos()
{


}

void pareja::espareja(jugador player1, mesa mesa1){
//  int carta1=player1.numerocartas[1];
//  int carta2=player1.numerocartas[0];
//  int carta3=mesa1.numerocartas[4];
//  int carta4=mesa1.numerocartas[3];
//  int carta5=mesa1.numerocartas[2];
//  int carta6=mesa1.numerocartas[1];
//  int carta7=mesa1.numerocartas[0];
  vector<int>cartas{7};
  cartas={player1.numerocartas[0],player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
 vector<int> cartasaux=cartas;
  int pareja=0;
//vector<int> comb1={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2]};
//vector<int> comb2={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3]};
//vector<int> comb3={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[4]};
//vector<int> comb4={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//vector<int> comb5={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//vector<int> comb6={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[0],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb7={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//vector<int> comb8={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//vector<int> comb9={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb10={player1.numerocartas[0], player1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb11{player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//vector<int> comb12{player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//vector<int> comb13={player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb14={player1.numerocartas[0], mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb15={player1.numerocartas[0], mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb16={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3]};
//vector<int> comb17={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[4]};
//vector<int> comb18={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb19={player1.numerocartas[1], mesa1.numerocartas[0],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb20={player1.numerocartas[1], mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};
//vector<int> comb21={mesa1.numerocartas[0],mesa1.numerocartas[1],mesa1.numerocartas[2],mesa1.numerocartas[3],mesa1.numerocartas[4]};

  int iguales=0;
  for (int i=0;i<6;i++) {
      for (int j=i;j<7;j++) {
          if (cartas[i]==cartasaux[j]){
                      cartasaux[j]=0;
                      iguales+=iguales;
               }
           }
      if (iguales>=1)
      pareja+=1;
       }
  if(pareja==1){
      player1.valor_mano=10;
  }else if (pareja==2) {
      player1.valor_mano=20;

    }else if (pareja==2) {
    player1.valor_mano=30;
}
  QString num1=QString::number(iguales);
   qDebug(num1.toLatin1());
  QString num=QString::number(player1.valor_mano);
   qDebug(num.toLatin1());

  }


