#ifndef KALKULATOR_H
#define KALKULATOR_H

class Kalkulator {

private:
    double mem; //Akumulator
    bool mem_used; //Określa czy akumulator jest aktualnie używany
    bool error_occured; //Czy podczas obliczen wystapil błąd

    double add(double a, double b);

    double sub(double a, double b);

    double mult(double a, double b);

    double div(double a, double b);

    double modulo(double a, double b);

    void system(int baza, double wartosc);

    void err(int code);

public:
    void oblicz(int tryb, double liczba2);

    void kasuj();

    bool is_mem_used();

    double get();

    void set(double a);
};
#endif // KALKULATOR_H
