﻿#include <iostream>
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

void Kalkulator::system(int baza, double wartosc) {

};

void Kalkulator::oblicz(int tryb, double liczba1, double liczba2) {
    switch (tryb) {
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
    case 6:
        system(liczba1, liczba2);
        break;
    default:
        err(2);
        break;
    }
};

//Obsługa błędów
void Kalkulator::err(int code) {
    kasuj();
    switch (code)
    {
    case 1:
        std::cerr << "BLAD: Nie mozna podzielic przez zero.";
        break;
    case 2:
        std::cerr << "BLAD: Zla operacja.";
        break;
    default:
        break;
    }
    //std::cout << endl;
    error_occured = 1;
};

//Czyszczenie akumulatora
void Kalkulator::kasuj() {
    mem = 0;
    mem_used = 0;
};

double Kalkulator::get() {
    return mem;
};

void Kalkulator::set(double a) {
    mem = a;
};
