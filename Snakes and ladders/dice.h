#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>

class dice{
    public:
        dice();
        int roll();

};

dice::dice()
{
    srand( time(0));
}


int dice::roll()
{
    return  (rand() % 6) + 1;
}