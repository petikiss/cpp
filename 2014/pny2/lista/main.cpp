#include "lista.h"




int main(int argc, char* argv[])
{
    Lista<int> l;
    int szam = 4;


    l.push_back(6);
    l.push_back(szam);
    l.print();


    return 0;
}
