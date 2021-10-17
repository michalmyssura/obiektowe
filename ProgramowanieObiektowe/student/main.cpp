#include <iostream>
#include "student.h"

using namespace std;
//nr indeksu rok studiow miesieczna wysokosc
int main()
{
   Student studenci[5]{
        {1.5,2, 5000}, {3.2,2, 3000}, {1.6,2,3044}, {3.3,2, 2444}, {3.2,2, 4555}};

        wypisz(studenci,5);
return 0;
}
