/*
 *  main.cc   - the client code for class bag
 *  (C) Porkolab Zoltan, ELTE, Budapest, Hungary
 *  (C) 2001
 */

#include <iostream>
#include "bag.h"

using namespace std;

int main()
{
    int yourMark(1);


    bag<long>  your_bag;
    your_bag.put(50);
    your_bag.put(100);
    your_bag.put(50);
    your_bag.put(400);
    yourMark = your_bag.mul(50);



    your_bag.put(50);
    const bag<long>  copy_of_your_bag = your_bag;
    your_bag.remove(50);
    yourMark = copy_of_your_bag.mul(50);


    your_bag = copy_of_your_bag;
    your_bag.put(50);
    if ( your_bag.mul(50) != copy_of_your_bag.mul(50) )
        yourMark = your_bag.mul(50);


//         your_bag.remove_all(50);
//         yourMark = your_bag[50];


     try
     {
         your_bag.remove_all(50);
         yourMark = your_bag[50];
     }
     catch( bad_value<long> bi )
     {
         std::cerr << "A(z) " << bi.value() << " ertek nem szerepel\n";
         yourMark = 5;
     }

    std::cout << "Your mark is " << yourMark << endl;
    return 0;
}
