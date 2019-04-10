#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <jugador.h>

namespace Ui {
class juego;
}

class juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit juego(QWidget *parent = nullptr);
    ~juego();

private:
    Ui::juego *ui;
};

#endif // JUEGO_H
