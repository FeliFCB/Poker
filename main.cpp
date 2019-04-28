#include "mainwindow.h"
#include "juego.h"
#include <QApplication>
#include <QString>
#include "jugador.h"
jugador jugador1;
jugador jugador2;
jugador jugador3;
mesa mesa1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
