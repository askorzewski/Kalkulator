#include <iostream>
#include "kalkulator.h"

class Kalkulator {
    double mem; //Akumulator
    bool mem_used; //Określa czy akumulator jest aktualnie używany
    bool error_occured; //Czy podczas obliczen wystapil błąd

    //Funkcje operacji
    double add(double a, double b) {
        return a + b;
    };

    double sub(double a, double b) {
        return a - b;
    };

    double mult(double a, double b) {
        return a * b;
    };

    double div(double a, double b) {
        if (b == 0) {
            err(1);
            return a;
        }
        return a / b;
    };

    double modulo(double a, double b) {
        if (b == 0) {
            err(1);
            return a;
        }
        //return static_cast<int>(a)% static_cast<int>(b);
        return a - static_cast<int>(a / b) * b;
    };

    void system(int baza, double wartosc) {

    };

    void oblicz(int tryb, double liczba1, double liczba2) {
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


    bool menu() { 
        error_occured = 0;
        int tryb;
        double a;
        cout << "Wybierz operacje:" << endl << "1) +" << endl << "2) -" << endl << "3) *" << endl << "4) /" << endl << "5) %" << endl <<"6) Zamiana systemu liczbowego na 10 (wartosc calkowita, baza)"<< endl <<"7) Czyszczenie" <<endl << "Aby wyjsc kliknij 0" << endl;
        cin >> tryb;
        if (tryb == 0) {
            return 0;
        }
        if (tryb == 7) {
            kasuj();
            return 1;
        }
        else if (mem_used == 0) {
            double b;
            cout << "Podaj 2 liczby na ktorych chcesz wykonac operacje: ";
            cin >> a;
            cin >> b;
            oblicz(tryb, a, b);
            mem_used = 1;
        }
        else {
            cout << "Liczba: ";
            cin >> a;
            oblicz(tryb, mem, a);
        }
        if (error_occured == 1) {
            return 0;
        }
        cout << "Wynik: " << mem << endl;
        return 1;
    };

    //Obsługa błędów
    void err(int code) {
        kasuj();
        switch (code)
        {
        case 1:
            cerr << "BLAD: Nie mozna podzielic przez zero.";
            break;
        case 2:
            cerr << "BLAD: Zla operacja.";
            break;
        default:
            break;
        }
        cout << endl;
        error_occured = 1;
    };

    //Czyszczenie akumulatora
    void kasuj() {
        mem = 0;
        mem_used = 0;
    };
public:
    void openOnce() {
        menu();
    };

    void openLoop(){
        bool a;
        do {
            a = menu();
        } while (a == 1);
    };
    
    double get() {
        return mem;
    };

    void set(double a) {
        mem = a;
    };
};
