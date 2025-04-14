#include <iostream>
#include "kalkulator.h"

//Kalkulator::Kalkulator(){

//};

//Funkcje operacji
double Kalkulator::add(double a, double b) {
    return a + b;
};

double Kalkulator::sub(double a, double b) {
    return a - b;
};

double Kalkulator::mult(double a, double b) {
    return a * b;
};

double Kalkulator::div(double a, double b) {
    if (b == 0) {
        err(1);
        return a;
    }
    return a / b;
};

double Kalkulator::modulo(double a, double b) {
    if (b == 0) {
        err(1);
        return a;
    }
    //return static_cast<int>(a)% static_cast<int>(b);
    return a - static_cast<int>(a / b) * b;
};

int Kalkulator::system(int baza1, int baza2, double wartosc) {
    return 0;
};


void Kalkulator::oblicz(int tryb, double liczba2) {
    double liczba1 = mem;
    switch (tryb) {
    case 0:
        mem=liczba2;
        break;
    case 1:
        mem = add(liczba1, liczba2);
        break;
    case 2:
        mem = sub(liczba1, liczba2);
        break;
    case 3:
        mem = mult(liczba1, liczba2);
        break;
    case 4:
        mem = div(liczba1, liczba2);
        break;
    case 5:
        mem = modulo(liczba1, liczba2);
        break;
    default:
        err(2);
        break;
    }
};

//Obsługa błędów
void Kalkulator::err(int kod) {
    kasuj();
    switch (kod)
    {
    case 1:
        err_msg = "BŁAD: Nie mozna podzielic przez zero.";
        break;
    case 2:
        err_msg = "BŁAD: Nieznana operacja.";
        break;
    default:
        err_msg = "BŁĄD: Nieznany błąd.";
        break;
    }
    std::cerr << err_msg;
    error_occured = 1;
};

//Czyszczenie akumulatora
void Kalkulator::kasuj() {
    mem = 0;
    mem_used = 0;
    error_occured = 0;
};

double Kalkulator::get() {
    return mem;
};

void Kalkulator::set(double a) {
    mem = a;
    mem_used = 1;
};

bool Kalkulator::is_mem_used(){
    if(mem_used){
        return true;
    }
    return false;
}
