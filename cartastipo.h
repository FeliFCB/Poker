#ifndef CARTASTIPO_H
#define CARTASTIPO_H
#include <iostream>
#include <QString>
#include <vector>

using namespace std;

class cartastipo{
public:
    cartastipo();
    void numeroytipocartas(int a, int b);
    vector <int> numerocartas{2};
    vector <QString> tipocartas{2};
    int numero;
    QString tipo;
    void infodecarta(int a);

};

#endif // CARTASTIPO_H
