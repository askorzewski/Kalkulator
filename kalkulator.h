#ifndef KALKULATOR_H
#define KALKULATOR_H
#include <string>
#include <cmath>

class Kalkulator {

private:
    double mem; //Akumulator
    bool mem_used;    //Określa czy akumulator jest aktualnie używany

    double add(double a, double b);

    double sub(double a, double b);

    double mult(double a, double b);

    double div(double a, double b);

    double modulo(double a, double b);

    void err(int kod);

public:
    int error_occured = 0;

    void oblicz(int tryb, double liczba2);

    void kasuj();

    void system(int baza1, int baza2, int liczba);

    bool is_mem_used();

    double get();

    void set(double a);

    std::string err_msg;
};
#endif // KALKULATOR_H
