#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kalkulator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void wyswietl_cyfre(int n);

    void on_p1_clicked();

    void on_p0_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_p9_clicked();

    void on_pBack_clicked();

    void on_pClear_clicked();

    void on_pPlus_clicked();

    void on_pKropka_clicked();

    void on_pWynik_clicked();

    void oblicz(int tryb);

    void on_pMinus_clicked();

    void on_pMnozenie_clicked();

    void on_pDziel_clicked();

    void on_pModulo_clicked();

private:
    //enum Tryb {plus, minus, iloraz, iloczyn, modulo};
    //Tryb tryb;
    int tryb = 0;
    bool blokuj_liczenie = 0;
    Kalkulator kalkulator;
    bool czy_kropka = 0;
    int miejsce_kropki = 1;
    double wyswietlona_liczba = 0;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
