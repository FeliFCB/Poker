#include "juego.h"
#include "ui_juego.h"
#include "QMessageBox"
#include "mainwindow.h"
using namespace std;

juego::juego(QString nombre1, QString nombre2, QString nombre3, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::juego)
{
    ui->setupUi(this);
    ui->tu_apuesta->setReadOnly(true);
    ui->tu_dinero->setReadOnly(true);
    ui->bote_actual->setReadOnly(true);
    ui->nombre->setReadOnly(true);
    ui->minima->setReadOnly(true);
    jugador1.nombrar(nombre1);
    jugador2.nombrar(nombre2);
    jugador3.nombrar(nombre3);
    turnoinicial();
}

juego::~juego()
{
    delete ui;
}

void juego::turnoinicial(){
    ui->mesa1->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
    ui->mesa2->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
    ui->mesa3->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
    ui->mesa4->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
    ui->mesa5->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
    if (jugador1.devolvereliminado()){
        jugador2.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        jugador3.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador2.cartas[0], jugador2.cartas[1]);
        if (mesa1.jugada == 3){
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador3.devolvernombre());
            jugador3.apostar(25);
            jugador2.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador3.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador3.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador3.cartas[0], jugador3.cartas[1]);
            //mesa1.jugada = 2;
        }
        else {
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador2.devolvernombre());
            jugador2.apostar(25);
            jugador3.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador2.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador2.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador2.cartas[0], jugador2.cartas[1]);
            //mesa1.jugada = 3;
        }
    }
    else if (jugador2.devolvereliminado()){
        jugador1.obtenercartas(jugador2.cartas[0], jugador2.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        jugador3.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador2.cartas[0], jugador2.cartas[1]);
        if (mesa1.jugada == 1){
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador1.devolvernombre());
            jugador1.apostar(25);
            jugador3.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador1.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador1.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador1.cartas[0], jugador1.cartas[1]);
            //mesa1.jugada = 3;
        }
        else {
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador3.devolvernombre());
            jugador3.apostar(25);
            jugador1.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador3.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador3.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador3.cartas[0], jugador3.cartas[1]);
            //mesa1.jugada = 1;
        }
    }
    else if (jugador3.devolvereliminado()){
        jugador1.obtenercartas(jugador2.cartas[0], jugador2.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        jugador2.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        if (mesa1.jugada == 2){
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador2.devolvernombre());
            jugador2.apostar(25);
            jugador1.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador2.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador2.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador2.cartas[0], jugador2.cartas[1]);
            //mesa1.jugada = 1;
        }
        else {
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador1.devolvernombre());
            jugador1.apostar(25);
            jugador2.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador1.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador1.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador1.cartas[0], jugador1.cartas[1]);
            //mesa1.jugada = 2;
        }
    }
    else {
        jugador1.obtenercartas(jugador2.cartas[0], jugador2.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        jugador2.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador3.cartas[0], jugador3.cartas[1]);
        jugador3.obtenercartas(jugador1.cartas[0], jugador1.cartas[1], jugador2.cartas[0], jugador2.cartas[1]);
        if (mesa1.jugada == 3){
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador3.devolvernombre());
            jugador1.apostar(25);
            jugador2.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador3.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador3.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador3.cartas[0], jugador3.cartas[1]);
            //mesa1.jugada = 1;
        }
        else if(mesa1.jugada == 2){
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador2.devolvernombre());
            jugador3.apostar(25);
            jugador1.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador2.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador2.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador2.cartas[0], jugador2.cartas[1]);
            //mesa1.jugada = 3;
        }
        else{
            QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador1.devolvernombre());
            jugador2.apostar(25);
            jugador3.apostar(50);
            mesa1.actualizarbote();
            ui->tu_apuesta->setText(QString::number(jugador1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(jugador1.devolverdinero()));
            ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
            ui->nombre->setText(jugador1.devolvernombre());
            ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
            mostrarmano(jugador1.cartas[0], jugador1.cartas[1]);
            //mesa1.jugada = 2;
        }
    }
}

void juego::mostrarmano(int carta1, int carta2){
    switch (carta1) {
    case 1: ui->mano1->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mano1->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mano1->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mano1->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mano1->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mano1->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mano1->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mano1->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mano1->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mano1->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mano1->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mano1->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mano1->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mano1->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mano1->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mano1->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mano1->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mano1->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mano1->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mano1->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mano1->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mano1->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mano1->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mano1->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mano1->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mano1->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mano1->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mano1->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mano1->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mano1->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mano1->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mano1->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mano1->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mano1->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mano1->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mano1->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mano1->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mano1->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mano1->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mano1->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mano1->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mano1->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mano1->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mano1->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mano1->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mano1->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mano1->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mano1->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mano1->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mano1->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mano1->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mano1->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mano1->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }


    switch (carta2) {
    case 1: ui->mano2->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mano2->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mano2->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mano2->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mano2->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mano2->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mano2->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mano2->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mano2->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mano2->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mano2->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mano2->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mano2->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mano2->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mano2->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mano2->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mano2->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mano2->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mano2->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mano2->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mano2->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mano2->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mano2->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mano2->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mano2->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mano2->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mano2->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mano2->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mano2->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mano2->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mano2->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mano2->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mano2->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mano2->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mano2->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mano2->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mano2->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mano2->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mano2->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mano2->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mano2->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mano2->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mano2->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mano2->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mano2->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mano2->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mano2->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mano2->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mano2->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mano2->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mano2->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mano2->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mano2->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }
}

void juego::mostrar123(int carta1, int carta2, int carta3){
    switch (carta1) {
    case 1: ui->mesa1->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mesa1->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mesa1->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mesa1->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mesa1->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mesa1->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mesa1->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mesa1->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mesa1->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mesa1->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mesa1->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mesa1->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mesa1->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mesa1->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mesa1->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mesa1->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mesa1->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mesa1->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mesa1->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mesa1->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mesa1->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mesa1->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mesa1->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mesa1->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mesa1->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mesa1->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mesa1->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mesa1->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mesa1->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mesa1->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mesa1->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mesa1->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mesa1->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mesa1->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mesa1->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mesa1->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mesa1->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mesa1->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mesa1->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mesa1->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mesa1->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mesa1->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mesa1->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mesa1->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mesa1->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mesa1->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mesa1->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mesa1->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mesa1->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mesa1->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mesa1->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mesa1->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mesa1->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }


    switch (carta2) {
    case 1: ui->mesa2->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mesa2->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mesa2->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mesa2->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mesa2->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mesa2->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mesa2->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mesa2->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mesa2->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mesa2->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mesa2->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mesa2->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mesa2->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mesa2->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mesa2->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mesa2->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mesa2->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mesa2->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mesa2->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mesa2->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mesa2->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mesa2->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mesa2->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mesa2->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mesa2->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mesa2->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mesa2->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mesa2->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mesa2->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mesa2->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mesa2->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mesa2->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mesa2->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mesa2->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mesa2->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mesa2->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mesa2->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mesa2->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mesa2->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mesa2->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mesa2->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mesa2->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mesa2->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mesa2->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mesa2->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mesa2->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mesa2->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mesa2->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mesa2->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mesa2->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mesa2->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mesa2->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mesa2->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }


    switch (carta3) {
    case 1: ui->mesa3->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mesa3->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mesa3->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mesa3->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mesa3->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mesa3->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mesa3->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mesa3->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mesa3->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mesa3->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mesa3->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mesa3->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mesa3->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mesa3->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mesa3->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mesa3->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mesa3->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mesa3->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mesa3->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mesa3->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mesa3->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mesa3->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mesa3->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mesa3->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mesa3->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mesa3->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mesa3->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mesa3->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mesa3->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mesa3->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mesa3->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mesa3->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mesa3->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mesa3->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mesa3->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mesa3->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mesa3->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mesa3->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mesa3->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mesa3->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mesa3->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mesa3->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mesa3->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mesa3->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mesa3->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mesa3->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mesa3->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mesa3->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mesa3->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mesa3->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mesa3->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mesa3->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mesa3->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }
}


void juego::mostrar4(int carta){
    switch (carta) {
    case 1: ui->mesa4->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mesa4->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mesa4->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mesa4->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mesa4->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mesa4->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mesa4->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mesa4->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mesa4->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mesa4->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mesa4->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mesa4->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mesa4->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mesa4->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mesa4->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mesa4->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mesa4->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mesa4->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mesa4->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mesa4->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mesa4->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mesa4->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mesa4->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mesa4->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mesa4->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mesa4->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mesa4->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mesa4->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mesa4->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mesa4->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mesa4->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mesa4->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mesa4->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mesa4->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mesa4->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mesa4->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mesa4->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mesa4->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mesa4->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mesa4->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mesa4->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mesa4->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mesa4->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mesa4->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mesa4->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mesa4->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mesa4->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mesa4->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mesa4->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mesa4->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mesa4->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mesa4->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mesa4->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }
}


void juego::mostrar5(int carta){
    switch (carta) {
    case 1: ui->mesa5->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mesa5->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mesa5->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mesa5->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mesa5->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mesa5->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mesa5->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mesa5->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mesa5->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mesa5->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mesa5->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mesa5->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mesa5->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mesa5->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mesa5->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mesa5->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mesa5->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mesa5->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mesa5->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mesa5->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mesa5->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mesa5->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mesa5->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mesa5->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mesa5->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mesa5->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mesa5->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mesa5->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mesa5->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mesa5->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mesa5->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mesa5->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mesa5->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mesa5->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mesa5->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mesa5->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mesa5->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mesa5->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mesa5->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mesa5->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mesa5->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mesa5->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mesa5->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mesa5->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mesa5->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mesa5->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mesa5->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mesa5->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mesa5->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mesa5->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mesa5->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mesa5->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mesa5->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }
}


void juego::turnosiguiente(){
    if ((jugador1.devolvereliminado() || jugador1.devolverretirado()) && (jugador2.devolvereliminado() || jugador2.devolverretirado())){
        QMessageBox::information(this,"Mensaje",jugador3.devolvernombre() + " gana los " + QString::number(mesa1.devolverbote()) + "€");
        jugador3.sumardinero(mesa1.devolverbote());
        jugador1.reset_variables();
        jugador2.reset_variables();
        jugador3.reset_variables();
        mesa1.reset_variables();
        turnoinicial();
    }
    else if ((jugador1.devolvereliminado() || jugador1.devolverretirado()) && (jugador3.devolvereliminado() || jugador3.devolverretirado())){
        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " gana los " + QString::number(mesa1.devolverbote()) + "€");
        jugador2.sumardinero(mesa1.devolverbote());
        jugador1.reset_variables();
        jugador2.reset_variables();
        jugador3.reset_variables();
        mesa1.reset_variables();
        turnoinicial();
    }
    else if ((jugador3.devolvereliminado() || jugador3.devolverretirado()) && (jugador2.devolvereliminado() || jugador2.devolverretirado())){
        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " gana los " + QString::number(mesa1.devolverbote()) + "€");
        jugador1.sumardinero(mesa1.devolverbote());
        jugador1.reset_variables();
        jugador2.reset_variables();
        jugador3.reset_variables();
        mesa1.reset_variables();
        turnoinicial();
    }
    else{
        int turno = mesa1.sumarturno();
        ui->apuesta->clear();
        ui->mano1->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        ui->mano2->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        if (mesa1.fase < 5){
            switch (turno) {
            case 1:
                QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador1.devolvernombre());
                ui->tu_apuesta->setText(QString::number(jugador1.devolverapuesta()));
                ui->tu_dinero->setText(QString::number(jugador1.devolverdinero()));
                ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
                ui->nombre->setText(jugador1.devolvernombre());
                ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
                mostrarmano(jugador1.cartas[0], jugador1.cartas[1]);
                break;
            case 2:
                QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador2.devolvernombre());
                ui->tu_apuesta->setText(QString::number(jugador2.devolverapuesta()));
                ui->tu_dinero->setText(QString::number(jugador2.devolverdinero()));
                ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
                ui->nombre->setText(jugador2.devolvernombre());
                ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
                mostrarmano(jugador2.cartas[0], jugador2.cartas[1]);
                break;
            default:
                QMessageBox::information(this,"Mensaje","Pasadle el ordenador a " + jugador3.devolvernombre());
                ui->tu_apuesta->setText(QString::number(jugador3.devolverapuesta()));
                ui->tu_dinero->setText(QString::number(jugador3.devolverdinero()));
                ui->bote_actual->setText(QString::number(mesa1.devolverbote()));
                ui->nombre->setText(jugador3.devolvernombre());
                ui->minima->setText(QString::number(max(max(jugador1.devolverapuesta(), jugador2.devolverapuesta()), jugador3.devolverapuesta())));
                mostrarmano(jugador3.cartas[0], jugador3.cartas[1]);
                break;
            }

        }
        if (mesa1.nuevafase){
            switch (mesa1.fase) {
            case 2:
                mesa1.repartir123();
                mostrar123(mesa1.cartas[0], mesa1.cartas[1], mesa1.cartas[2]);
                break;
            case 3:
                mesa1.repartir4();
                mostrar4(mesa1.cartas[3]);
                break;
            case 4:
                mesa1.repartir5();
                mostrar5(mesa1.cartas[4]);
                break;
            case 5:
                jugador1.numeroytipocartas();
                jugador2.numeroytipocartas();
                jugador3.numeroytipocartas();
                mesa1.numeroytipocartas();
                pareja pareja1;
                doblepareja doblepareja1;
                trio trio1;
                escalera escalera1;
                full full1;
                poker poker1;
                pareja1.comprobarmano();
                doblepareja1.comprobarmano();
                trio1.comprobarmano();
                escalera1.comprobarmano();
                full1.comprobarmano();
                poker1.comprobarmano();

                if (jugador1.devolvereliminado() || jugador1.devolverretirado()){
                    if (jugador2.valor_mano > jugador3.valor_mano || (jugador2.valor_mano == jugador3.valor_mano && jugador2.cartaalta > jugador3.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " tiene " + jugador2.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador3.devolvernombre() + " tenia " + jugador1.nombremano);
                        jugador2.sumardinero(mesa1.devolverbote());
                    }
                    else if(jugador2.valor_mano == jugador3.valor_mano && jugador2.cartaalta == jugador3.cartaalta){
                        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " y " + jugador3.devolvernombre() + " tienen " + jugador2.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno");
                        jugador2.sumardinero(mesa1.devolverbote()/2);
                        jugador3.sumardinero(mesa1.devolverbote()/2);
                    }
                    else{
                        QMessageBox::information(this,"Mensaje",jugador3.devolvernombre() + " tiene " + jugador3.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador2.devolvernombre() + " tenia " + jugador2.nombremano);
                        jugador3.sumardinero(mesa1.devolverbote());
                    }
                }
                else if(jugador2.devolvereliminado() || jugador2.devolverretirado()){
                    if (jugador1.valor_mano > jugador3.valor_mano || (jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta > jugador3.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " tiene " + jugador1.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador3.devolvernombre() + " tenia " + jugador3.nombremano);
                        jugador1.sumardinero(mesa1.devolverbote());
                    }
                    else if(jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta == jugador3.cartaalta){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " y " + jugador3.devolvernombre() + " tienen " + jugador1.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno");
                        jugador1.sumardinero(mesa1.devolverbote()/2);
                        jugador3.sumardinero(mesa1.devolverbote()/2);
                    }
                    else{
                        QMessageBox::information(this,"Mensaje",jugador3.devolvernombre() + " tiene " + jugador3.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador1.devolvernombre() + " tenia " + jugador1.nombremano);
                        jugador3.sumardinero(mesa1.devolverbote());
                    }
                }
                else if (jugador3.devolvereliminado() || jugador3.devolverretirado()){
                    if (jugador1.valor_mano > jugador2.valor_mano || (jugador1.valor_mano == jugador2.valor_mano && jugador1.cartaalta > jugador2.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " tiene " + jugador1.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador2.devolvernombre() + " tenia " + jugador2.nombremano);
                        jugador1.sumardinero(mesa1.devolverbote());
                    }
                    else if(jugador2.valor_mano == jugador1.valor_mano && jugador1.cartaalta == jugador3.cartaalta){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " y " + jugador2.devolvernombre() + " tienen " + jugador2.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno");
                        jugador2.sumardinero(mesa1.devolverbote()/2);
                        jugador1.sumardinero(mesa1.devolverbote()/2);
                    }
                    else{
                        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " tiene " + jugador2.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador1.devolvernombre() + " tenia " + jugador1.nombremano);
                        jugador2.sumardinero(mesa1.devolverbote());
                    }
                }
                else {
                    if ((jugador1.valor_mano > jugador2.valor_mano && jugador1.valor_mano > jugador3.valor_mano) || (jugador1.valor_mano == jugador2.valor_mano && jugador1.cartaalta > jugador2.cartaalta && jugador1.valor_mano > jugador3.valor_mano) || (jugador1.valor_mano > jugador2.valor_mano && jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta > jugador3.cartaalta) || (jugador1.valor_mano == jugador2.valor_mano && jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta > jugador2.cartaalta && jugador1.cartaalta > jugador3.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " tiene " + jugador1.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador2.devolvernombre() + " tenia " + jugador2.nombremano + "\n" + jugador3.devolvernombre() + " tenia " + jugador3.nombremano);
                        jugador1.sumardinero(mesa1.devolverbote());
                    }
                    else if ((jugador2.valor_mano > jugador1.valor_mano && jugador2.valor_mano > jugador3.valor_mano) || (jugador2.valor_mano == jugador1.valor_mano && jugador2.cartaalta > jugador1.cartaalta && jugador2.valor_mano > jugador3.valor_mano) || (jugador2.valor_mano > jugador1.valor_mano && jugador2.valor_mano == jugador3.valor_mano && jugador2.cartaalta > jugador3.cartaalta) || (jugador2.valor_mano == jugador1.valor_mano && jugador2.valor_mano == jugador3.valor_mano && jugador2.cartaalta > jugador1.cartaalta && jugador2.cartaalta > jugador3.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " tiene " + jugador2.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador1.devolvernombre() + " tenia " + jugador1.nombremano + "\n" + jugador3.devolvernombre() + " tenia " + jugador3.nombremano);
                        jugador2.sumardinero(mesa1.devolverbote());
                    }
                    else if ((jugador3.valor_mano > jugador2.valor_mano && jugador3.valor_mano > jugador1.valor_mano) || (jugador3.valor_mano == jugador2.valor_mano && jugador3.cartaalta > jugador2.cartaalta && jugador3.valor_mano > jugador1.valor_mano) || (jugador3.valor_mano > jugador2.valor_mano && jugador3.valor_mano == jugador1.valor_mano && jugador3.cartaalta > jugador1.cartaalta) || (jugador3.valor_mano == jugador2.valor_mano && jugador3.valor_mano == jugador1.valor_mano && jugador3.cartaalta > jugador2.cartaalta && jugador3.cartaalta > jugador1.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador3.devolvernombre() + " tiene " + jugador3.nombremano + " y gana los " + QString::number(mesa1.devolverbote()) + "€.\n" + jugador1.devolvernombre() + " tenia " + jugador1.nombremano + "\n" + jugador2.devolvernombre() + " tenia " + jugador2.nombremano);
                        jugador3.sumardinero(mesa1.devolverbote());
                    }
                    else if ((jugador1.valor_mano == jugador2.valor_mano && jugador1.cartaalta == jugador2.cartaalta && jugador1.valor_mano > jugador3.valor_mano) || (jugador1.valor_mano == jugador2.valor_mano && jugador1.cartaalta == jugador2.cartaalta && jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta > jugador3.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " y " + jugador2.devolvernombre() + " tienen " + jugador2.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno\n" + jugador3.devolvernombre() + " tenia " + jugador3.nombremano);
                        jugador2.sumardinero(mesa1.devolverbote()/2);
                        jugador1.sumardinero(mesa1.devolverbote()/2);
                    }
                    else if ((jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta == jugador3.cartaalta && jugador1.valor_mano > jugador2.valor_mano) || (jugador1.valor_mano == jugador3.valor_mano && jugador1.cartaalta == jugador3.cartaalta && jugador1.valor_mano == jugador2.valor_mano && jugador1.cartaalta > jugador2.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + " y " + jugador3.devolvernombre() + " tienen " + jugador1.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno\n" + jugador2.devolvernombre() + " tenia " + jugador2.nombremano);
                        jugador3.sumardinero(mesa1.devolverbote()/2);
                        jugador1.sumardinero(mesa1.devolverbote()/2);
                    }
                    else if ((jugador3.valor_mano == jugador2.valor_mano && jugador3.cartaalta == jugador2.cartaalta && jugador3.valor_mano > jugador1.valor_mano) || (jugador3.valor_mano == jugador2.valor_mano && jugador3.cartaalta == jugador2.cartaalta && jugador3.valor_mano == jugador1.valor_mano && jugador3.cartaalta > jugador1.cartaalta)){
                        QMessageBox::information(this,"Mensaje",jugador2.devolvernombre() + " y " + jugador3.devolvernombre() + " tienen " + jugador2.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/2)) + "€ cada uno\n" + jugador1.devolvernombre() + " tenia " + jugador1.nombremano);
                        jugador2.sumardinero(mesa1.devolverbote()/2);
                        jugador3.sumardinero(mesa1.devolverbote()/2);
                    }
                    else{
                        QMessageBox::information(this,"Mensaje",jugador1.devolvernombre() + ", " + jugador2.devolvernombre() + " y " + jugador3.devolvernombre() + " tienen " + jugador2.nombremano + " y ganan " + QString::number(floor(mesa1.devolverbote()/3)) + "€ cada uno");
                        jugador1.sumardinero(mesa1.devolverbote()/3);
                        jugador2.sumardinero(mesa1.devolverbote()/3);
                        jugador3.sumardinero(mesa1.devolverbote()/3);
                    }
                }
    //            qDebug("El jugador1 tiene de valor de mano %d", jugador1.devolvervalor_mano());
    //            qDebug("El jugador2 tiene de valor de mano %d", jugador2.devolvervalor_mano());
    //            qDebug("El jugador3 tiene de valor de mano %d", jugador3.devolvervalor_mano());

                qDebug("La carta alta del jugador 1 es %d", jugador1.cartaalta);
                qDebug("La carta alta del jugador 2 es %d", jugador2.cartaalta);
                qDebug("La carta alta del jugador 3 es %d", jugador3.cartaalta);
                jugador1.reset_variables();
                jugador2.reset_variables();
                jugador3.reset_variables();
                mesa1.reset_variables();
                turnoinicial();
            }
        }
    }

}


void juego::on_apostar_clicked()
{
    switch (mesa1.devolverturno()) {
    case 2:
        if (jugador2.devolverapuesta()+ui->apuesta->text().toInt() < max(jugador1.devolverapuesta(), jugador3.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador1.devolverapuesta(), jugador3.devolverapuesta())) + "€");
        }
        else if(ui->apuesta->text().toInt() > jugador2.devolverdinero()){
            QMessageBox::information(this,"Mensaje", "Solo te quedan " + QString::number(jugador2.devolverdinero()) + " € para apostar");
        }
        else{
            jugador2.apostar(ui->apuesta->text().toInt());
            mesa1.actualizarbote();
            turnosiguiente();
        }
        break;
    case 3:
        if (jugador3.devolverapuesta()+ui->apuesta->text().toInt() < max(jugador1.devolverapuesta(), jugador2.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador1.devolverapuesta(), jugador2.devolverapuesta())) + "€");
        }
        else if(ui->apuesta->text().toInt() > jugador3.devolverdinero()){
            QMessageBox::information(this,"Mensaje", "Solo te quedan " + QString::number(jugador3.devolverdinero()) + " € para apostar");
        }
        else{

            jugador3.apostar(ui->apuesta->text().toInt());
            mesa1.actualizarbote();
            turnosiguiente();
        }
        break;
    default:
        if (jugador1.devolverapuesta()+ui->apuesta->text().toInt() < max(jugador3.devolverapuesta(), jugador2.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador3.devolverapuesta(), jugador2.devolverapuesta())) + "€");
        }
        else if(ui->apuesta->text().toInt() > jugador1.devolverdinero()){
            QMessageBox::information(this,"Mensaje", "Solo te quedan " + QString::number(jugador1.devolverdinero()) + " € para apostar");
        }
        else{
            jugador1.apostar(ui->apuesta->text().toInt());
            mesa1.actualizarbote();
            turnosiguiente();
        }
        break;
    }
}

void juego::on_pasar_clicked(){


    switch (mesa1.devolverturno()) {
    case 2:
        if (jugador2.devolverapuesta() < max(jugador1.devolverapuesta(), jugador3.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador1.devolverapuesta(), jugador3.devolverapuesta())) + "€");
        }
        else{
                turnosiguiente();
        }
        break;
    case 3:
        if (jugador3.devolverapuesta() < max(jugador1.devolverapuesta(), jugador2.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador1.devolverapuesta(), jugador2.devolverapuesta())) + "€");
        }
        else{
                turnosiguiente();
        }
        break;
    default:
        if (jugador1.devolverapuesta() < max(jugador3.devolverapuesta(), jugador2.devolverapuesta())){
            QMessageBox::information(this, "Mensaje", "La apuesta minima es " + QString::number(max(jugador3.devolverapuesta(), jugador2.devolverapuesta())) + "€");
        }
        else{
                turnosiguiente();
        }
        break;
    }

}


void juego::on_retirarse_clicked()
{
    switch(mesa1.devolverturno()){
    case 2:
        jugador2.retirarse();
        turnosiguiente();
        break;
    case 3:
        jugador3.retirarse();
        turnosiguiente();
        break;
    default:
        jugador1.retirarse();
        turnosiguiente();
        break;
    }
}

