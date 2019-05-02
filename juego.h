#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <manos.h>
#include <QTextEdit>

namespace Ui {
class juego;
}

class juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit juego(QString nombre1, QString nombre2, QString nombre3, QWidget *parent = nullptr);
    ~juego();
    void turnoinicial();
    void mostrarmano(int carta1, int carta2);
    void mostrar123(int carta1, int carta2, int carta3);
    void mostrar4(int carta);
    void mostrar5(int carta);
    void turnosiguiente();

private slots:
    void on_apostar_clicked();

    void on_pasar_clicked();

    void on_retirarse_clicked();

private:
    Ui::juego *ui;
};

#endif // JUEGO_H
