#include<iostream>
#include"Pacjent.h"
using namespace std;

Pacjent::Pacjent(int a , double b, double c){
this->numer_identyfikacyjny=a;
this->wzrost=b;
this->waga=c;
}
void wyswietl(const Pacjent& any){
	cout << "Wypisz" << endl;
cout<<any.numer_identyfikacyjny<<endl;
cout<<any.wzrost<<endl;
cout<<any.waga<<endl;

}

Pacjent::~Pacjent(){
cout<<"usuwam pacjenta o numerze identyfikacyjnym: "<<numer_identyfikacyjny<<endl;


}


