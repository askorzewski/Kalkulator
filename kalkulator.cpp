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

//Zamiana systeów liczbowych
void Kalkulator::system(int baza1, int baza2, int liczba){
    int dec = 0;
    int wynik = 0;
    for(int potega = 10; potega>=0; potega--){ //zamiana baza1->dec
        if(liczba<std::pow(baza1, potega)){
            continue;
        }
        dec += pow(baza1, potega) * static_cast<int>(liczba / std::pow(10, potega));
        liczba -= std::pow(10, potega) * static_cast<int>(liczba / std::pow(10, potega));
    }
    for(int potega = 10; potega>=0; potega--){ //zamiana dec->baza2
        if(dec<std::pow(baza2, potega)){
            continue;
        }
        wynik += static_cast<int>(dec/std::pow(baza2, potega)) * std::pow(10, potega);
        dec -= std::pow(baza2, potega) * static_cast<int>(dec/std::pow(baza2, potega));
    }
    mem = wynik;
}


//Wykorzystanie funkcji liczących (metoda publiczna)
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
        err_msg = "BŁĄD: Nie mozna podzielic przez zero.";
        break;
    case 2:
        err_msg = "BŁĄD: Nieznana operacja.";
        break;
    default:
        err_msg = "BŁĄD: Nieznany błąd.";
        break;
    }
    std::cerr << err_msg;
    error_occured = 1;
};

//Resret kalkulatora do stanu początkowego
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
};

