//
//  main.cpp
//  po_zaliczenie
//
//  Created by Adrian Celczyński on 21/01/2020.
//  Copyright © 2020 Adrian Celczyński. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pojazd{
protected:
    double wartosc{0.0};
    int rokProdukcji{0};
public:
    Pojazd(double _wartosc, int _rokProdukcji):wartosc{_wartosc}, rokProdukcji{_rokProdukcji}{};
    void ustawWartosc(double wartoscDoUstawienia){
        if(wartoscDoUstawienia > 0) wartosc = wartoscDoUstawienia;
    }
    virtual void wypisz() const {
        cout << "Wartosc: " << wartosc << endl;
        cout << "Rok Produkcji: " << rokProdukcji << endl;
    }
};

class Samochod: public Pojazd{
protected:
    int liczbaKol{0};
    int przebieg{0};
public:
    Samochod(double _wartosc, int _rokProdukcji, int _liczbaKol, int _przebieg): Pojazd{_wartosc, _rokProdukcji}, liczbaKol{_liczbaKol}, przebieg{_przebieg}{};
    void ustawPrzebieg(int przebiegDoUstawienia){
        if(przebiegDoUstawienia > 0) przebieg = przebiegDoUstawienia;
    }
    virtual void wypisz() const override {
        Pojazd::wypisz();
        cout << "Liczba kol: " << liczbaKol << endl;
        cout << "Przebieg: " << przebieg << endl;
    }
};

class SamochodOsobowy: public Samochod{
protected:
    int liczbaOsob{0};
public:
    SamochodOsobowy(double _wartosc, int _rokProdukcji, int _liczbaKol, int _przebieg, int _liczbaOsob): Samochod{_wartosc, _rokProdukcji, _liczbaKol, _przebieg}, liczbaOsob{_liczbaOsob}{};
    virtual void wypisz() const override {
        Samochod::wypisz();
        cout << "Liczba osob: " << liczbaOsob << endl;
    }
};

class SamochodCiezarowy: public Samochod{
protected:
    int ladownosc{0};
public:
    SamochodCiezarowy(double _wartosc, int _rokProdukcji, int _liczbaKol, int _przebieg, int _ladownosc): Samochod{_wartosc, _rokProdukcji, _liczbaKol, _przebieg}, ladownosc{_ladownosc}{};
    virtual void wypisz() const override {
        Samochod::wypisz();
        cout << "Ladownosc: " << ladownosc << endl;
    }
};

double losowaWartosc(){
    return rand() % 52000 + 1980;
}

int losowyRok(){
    return rand() % 2020 + 1970;
}

int losowyPrzebieg(){
    return rand() % 340000 + 100000;
}

int losowaLadownosc(){
    return rand() % 30000 + 10000;
}

int main() {
    cout << "Samochody" << endl;
    
    Samochod *tablica[] = {
        new Samochod(losowaWartosc(), losowyRok(), 4, losowyPrzebieg()),
        new SamochodOsobowy(losowaWartosc(), losowyRok(), 4, losowyPrzebieg(), 5),
        new SamochodCiezarowy(losowaWartosc(), losowyRok(), 6, losowyPrzebieg(), losowaLadownosc())
    };
    
    int rozmiar = sizeof(tablica)/sizeof(*tablica);
    for(int i = 0; i<rozmiar; ++i){
        tablica[i]->wypisz();
        cout << "=====================" << endl;
    }
    
    return 0;
}
