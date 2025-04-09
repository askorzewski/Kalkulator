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
    wyswietlona_liczba = (wyswietlona_liczba * 10) + n;
    ui->wyswietlacz->display(wyswietlona_liczba);
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
    wyswietlona_liczba = wyswietlona_liczba / 10;
    ui->wyswietlacz->display(wyswietlona_liczba);
}

void MainWindow::on_pClear_clicked()
{
    wyswietlona_liczba = 0;
    kalkulator.kasuj();
    ui->wyswietlacz->display(wyswietlona_liczba);
}


