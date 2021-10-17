#include <iostream>
#include"Pacjent.h"
using namespace std;

int main()
{
    Pacjent *michal=new Pacjent(1233,223,333);

   wyswietl(*michal);



 wyswietl(*michal);
   delete michal;
    return 0;
}
