#ifndef PACJENT_H_INCLUDED
#define PACJENT_H_INCLUDED
class Pacjent{
    friend void wyswietl(const Pacjent&);
private:
int numer_identyfikacyjny;
double wzrost;
double waga;

public:
    Pacjent(int,double,double);
    ~Pacjent();
    double ustaw_wage();
    Pacjent(const Pacjent&)=delete;

};

#endif // PACJENT_H_INCLUDED
