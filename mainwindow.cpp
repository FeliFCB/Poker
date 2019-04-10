#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jugador.h"
#include "juego.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nombre1_textChanged(const QString &arg1)
{
    nombre1 = arg1;
}

void MainWindow::on_nombre2_textChanged(const QString &arg1)
{
    nombre2 = arg1;
}

void MainWindow::on_nombre3_textChanged(const QString &arg1)
{
    nombre3 = arg1;
}

void MainWindow::openjuego()
{
    juegowindow = new juego();
    juegowindow->show();

}

void MainWindow::on_comenzar_clicked()
{
    jugador jugador1;
    jugador jugador2;
    jugador jugador3;
    jugador1.nombrar(nombre1);
    jugador2.nombrar(nombre2);
    jugador3.nombrar(nombre3);
    openjuego();

}
