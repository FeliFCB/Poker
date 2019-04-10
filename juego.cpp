#include "juego.h"
#include "ui_juego.h"
#include "QMessageBox"

juego::juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::juego)
{
    ui->setupUi(this);
    QMessageBox::information(this, "Mensaje", "Pasadle el ordenador al primer jugador");
}

juego::~juego()
{
    delete ui;
}
