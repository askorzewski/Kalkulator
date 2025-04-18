#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wyswietl_cyfre(int n){
    if(wyswietlona_liczba != 0 and std::abs(std::log10(wyswietlona_liczba))+1>=8){ //Jeśli liczba wykracza poza możliwe miejsca
        return;
    }
    if(czy_kropka){ //Wpisywanie liczb niecałkowitych
        if(wyswietlona_liczba == 0 and n == 0){ //Specjalny przypadek: "0.0" - niemożliwe do wyświetlenia przez display(double liczba).
            QString zero = "0.";
            for(int i = 0; i < miejsce_kropki; i++){
                zero.append("0");
            }
            miejsce_kropki++;
            ui->wyswietlacz->display(zero);
            return;
        }
        wyswietlona_liczba = wyswietlona_liczba + (static_cast<double>(n)/(std::pow(10, miejsce_kropki)));
        miejsce_kropki++;
    }
    else { //Wpisywanie liczb całkowitych
        wyswietlona_liczba = (wyswietlona_liczba * 10) + n;
    }
    ui->wyswietlacz->display(wyswietlona_liczba);
    blokuj_liczenie = false;
    blokuj_cofnij = false;
}

void MainWindow::on_p0_clicked()
{
    wyswietl_cyfre(0);
}

void MainWindow::on_p1_clicked()
{
    wyswietl_cyfre(1);
}

void MainWindow::on_p2_clicked()
{
    wyswietl_cyfre(2);
}

void MainWindow::on_p3_clicked()
{
    wyswietl_cyfre(3);
}

void MainWindow::on_p4_clicked()
{
    wyswietl_cyfre(4);
}

void MainWindow::on_p5_clicked()
{
    wyswietl_cyfre(5);
}

void MainWindow::on_p6_clicked()
{
    wyswietl_cyfre(6);
}

void MainWindow::on_p7_clicked()
{
    wyswietl_cyfre(7);
}

void MainWindow::on_p8_clicked()
{
    wyswietl_cyfre(8);
}

void MainWindow::on_p9_clicked()
{
    wyswietl_cyfre(9);
}

void MainWindow::on_pBack_clicked()
{
    if (blokuj_cofnij){
        return;
    }
    if(static_cast<int>(wyswietlona_liczba) == wyswietlona_liczba){
    wyswietlona_liczba = (int)wyswietlona_liczba / 10;
    }
    ui->wyswietlacz->display(wyswietlona_liczba);
}

void MainWindow::on_pClear_clicked()
{
    wyswietlona_liczba = 0;
    czy_kropka = 0;
    miejsce_kropki = 1;
    kalkulator.kasuj();
    ui->wyswietlacz->display(wyswietlona_liczba);
}

void MainWindow::oblicz(int tryb)
{
    if(!blokuj_liczenie){
        kalkulator.oblicz(tryb, wyswietlona_liczba);
    }
    wyswietlona_liczba = 0;
    czy_kropka = false;
    if(kalkulator.get() != 0 and std::abs(std::log10(kalkulator.get()))+1>=8){
        error("BŁĄD: OVERFLOW");
    }
    ui->wyswietlacz->display(kalkulator.get());
    blokuj_liczenie = true;
    blokuj_cofnij = true;

    if(kalkulator.error_occured){
        error(kalkulator.err_msg);
    }
}

void MainWindow::on_pKropka_clicked()
{
    czy_kropka = 1;
}


void MainWindow::on_pWynik_clicked()
{
    oblicz(tryb);
    tryb = 0;
    miejsce_kropki = 1;
    wyswietlona_liczba = kalkulator.get();
    ui->wyswietlacz->display(wyswietlona_liczba);
    wyswietlona_liczba = 0;
}

void MainWindow::on_pPlus_clicked(){
    oblicz(tryb);
    tryb = 1;
}

void MainWindow::on_pMinus_clicked()
{
    oblicz(tryb);
    tryb = 2;
}


void MainWindow::on_pMnozenie_clicked()
{
    oblicz(tryb);
    tryb = 3;
}


void MainWindow::on_pDziel_clicked()
{
    oblicz(tryb);
    tryb = 4;
}


void MainWindow::on_pModulo_clicked()
{
    oblicz(tryb);
    tryb = 5;
}

void MainWindow::on_actionO_Autorze_triggered()
{
    Popup.setWindowTitle("O Autorze");
    Popup.setText("Adam Skórzewski \nNumer Indeksu: 287081");
    Popup.exec();
}

void MainWindow::error(std::string msg){
    on_pClear_clicked();
    Popup.setWindowTitle("BŁĄD");
    Popup.setText(QString::fromStdString(msg));
    Popup.exec();

}


void MainWindow::on_actionKonwersje_baz_triggered()
{
    QWidget *bazy = new QWidget;
    ui_bazy.setupUi(bazy);
    connect (ui_bazy.liczBaza, SIGNAL (clicked()), this, SLOT(system()));
    bazy->show();
}

void MainWindow::system()
{
    QString strStart = ui_bazy.wartoscStart->text();
    int bazaStart = ui_bazy.baza2->value();
    int bazaEnd = ui_bazy.baza1->value();
    kalkulator.system(bazaStart, bazaEnd, strStart.toInt());
    ui->wyswietlacz->display(kalkulator.get());
}

