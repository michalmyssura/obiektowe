#include <iostream>
#include <cstdlib>

using namespace std;
/*
    W ponizszym programie punkty zgromadzone w tablicy przesun o zadany Wektor.
    Program testujacy zostal napisany, zawiera jednak blad, który nalezy poprawic.
    Nastepnie "zdejmujac" komentarze nalezy stopniowo uzupelniac program o brakujace elementy,
    ktore pozwola na skompilowanie i uruchomienie programu.
    W programie dodatkowo:
    - zadbaj o to żeby wspolrzedne wektora AB byly podawane przez uzytkownika.
    - tablica dynamiczna punktow byla uzupelniana roznymi wartosciami
*/

class Wektor{
friend class Punkt;
private:
	double x;
	double y;
public:
	Wektor(double, double);
	void wypisz() const;
};

class Punkt
{
private:
	double x;
	double y;
public:
	Punkt (double,double);
	Punkt();
	~Punkt();
	void wypisz() const;
	void przesun_o_wektor(const Wektor&);
};

void Punkt::przesun_o_wektor(const Wektor& w){
	x += w.x;
	y += w.y;
}

int main()
{
	cout<<"Podaj liczbe punktow ";
	int n;
	cin>>n;
	if (n>0)
	{
    	Wektor AB={static_cast<double>(rand()%12),static_cast<double>(rand()%5)};

    	Punkt *wsk=new Punkt[n];
    	for(int i=0; i<n; ++i)
    	{
        	cout<<"\n-----------------------------------------\n";
        	cout<<i+1<<".\nPunkt ";
        	wsk[i].wypisz();
    	}

    	cout<<"Przesuniecie punktow o wektor ";
    	AB.wypisz();

    	for(int i=0; i<n; ++i)
    	{
        	wsk[i].przesun_o_wektor(AB);
        	cout<<"\n-----------------------------------------\n";
        	cout<<i+1<<".\nPunkt ";
        	wsk[i].wypisz();
    	}


    	cout<<"\n-----------------------------------------\n";
    	delete []wsk;
    	wsk=nullptr;
	}
	cout<<"\n-----------------------------------------\n";
	cout<<"\nKoniec programu\n";
	cout<<"\n-----------------------------------------\n";
	return 0;
}

//defincje metod klasy Punkt

Punkt::Punkt(double xx,double yy)
{
	this->x=xx;
	this->y=yy;
}

Punkt::Punkt(){
	x = rand()%20 - 10;
	y = rand()%20 - 10;
}

Punkt::~Punkt()
{
	cout<<"\nDestruktor punktu ";
	this->wypisz();
}

void Punkt::wypisz() const
{
	cout<<"("<<this->x<<", "<<this->y<<")";
}

Wektor::Wektor(double xx,double yy)
{
	this->x=xx;
	this->y=yy;
}

void Wektor::wypisz() const
{
	cout<<"("<<this->x<<", "<<this->y<<")";
}

//definicje metod klasy Wektor


