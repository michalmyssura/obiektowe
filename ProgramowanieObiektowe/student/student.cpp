#include<iostream>
#include "student.h"
using namespace std;
Student::Student(double a,double b,double c)
{
    this->nrind=a;
    this->rokstud=b;
    this->stypend=c;


}


Student::~Student(){
cout<<"usuwam dane studenta o numerze indeksu "<<nrind<<endl;
}

void Student::wypisz(){
cout<<"oto numer indeksu "<<nrind<<endl;
cout<<"oto rok studiow "<<rokstud<<endl;
cout<<"oto kwota stypendium "<<stypend<<endl;
cout<<"=============================="<<endl;
}

void wypisz(const Student*studenci,int dlugosc){

for(int i=0;i<dlugosc;i++){
    studenci[i].wypisz();

}


}




