#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <cmath>
#include "kalkulator.h"
#include "./ui_bazy.h"


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

    void on_actionO_Autorze_triggered();

    void error(std::string msg);

    void on_actionKonwersje_baz_triggered();

    void system();

private:
    //enum Tryb {plus, minus, iloraz, iloczyn, modulo};
    //Tryb tryb;

    double wyswietlona_liczba = 0;
    int tryb = 0;
    int miejsce_kropki = 1;

    bool blokuj_liczenie = 0;
    bool blokuj_cofnij = 0;
    bool czy_kropka = 0;

    QMessageBox Popup;
    Kalkulator kalkulator;
    Ui::MainWindow *ui;
    Ui::Form ui_bazy;
};
#endif // MAINWINDOW_H
