#include <iostream>

using namespace std;

class A
{
protected:
    int x;

public:
    A(int);
    virtual ~A();
    void ustaw_x(int);
    virtual void wypisz() const;
};

class B : public A
{
protected:
    float y;

public:
    B(int,float);
    ~B();
    void ustaw_y(float);
    void wypisz() const override;
};

class C: public B
{
protected:
    string z;

public:
    C(int,float,const string&);
    ~C();
    void ustaw_z(const string&);
    void wypisz() const;
};

int main()
{
    A *wsk = new C{5, 75.18, "hello"};
    wsk->wypisz();
    wsk->ustaw_x(678);

    if(B* x = dynamic_cast<B*>(wsk)){
        x->ustaw_y(5.57);
    }
    if(C* x = dynamic_cast<C*>(wsk)){
        x->ustaw_z("hi");
    }
    wsk->wypisz();


    delete wsk;


    //-------------


    A* tablica[] = {new A{10}, new B{20, 20.5}, new C{5, 7.5, "hello2"}};

    int n = sizeof(tablica)/sizeof(A*);

    for(int i=0; i<n; i++){
        tablica[i]->wypisz();
    }


    for(int i=0; i<n; i++)
        delete tablica[i];



    return 0;
}

A::A(int xx): x(xx)
{
    cout<<"konstruktor A"<<endl;
}

A::~A()
{
    cout<<"destruktor A"<<endl;
}

void A::ustaw_x(int arg)
{
    x=arg;
}

void A::wypisz() const
{
    cout<<x<<endl;
}

B::B(int xx,float yy): A(xx),y(yy)
{
    cout<<"konstruktor B"<<endl;
}

B::~B()
{
    cout<<"destruktor B"<<endl;
}

void B::ustaw_y(float arg)
{
    y=arg;
}

void B::wypisz() const
{
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

C::C(int xx,float yy,const string& zz): B(xx,yy),z(zz)
{
    cout<<"konstruktor C"<<endl;
}

C::~C()
{
    cout<<"destruktor C"<<endl;
}

void C::ustaw_z(const string& arg)
{
    z=arg;
}

void C::wypisz() const
{
    cout<<"["<<x<<", "<<y<<", "<<z<<"]"<<endl;
}
