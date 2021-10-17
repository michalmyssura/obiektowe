#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student {

private:
    double nrind;
    double rokstud;
    double stypend;
public:
    Student(double,double,double);
    ~Student();
    void wypisz();

};
void wypisz(const Student*,int);
 double zmianastypend(const Student *,int);
#endif // STUDENT_H_INCLUDED
