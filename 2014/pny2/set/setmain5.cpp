#include <iostream>
#include "set.h"

using namespace std;

int main()
{
    int your_mark = 1;

    set<int> your_set;  // capacity is up on you

    your_set.put(1);    // put to set
    your_set.put(1);    // no effect
    your_set.put(2).put(3).put(4);
    your_set.del(3);    // delete from set
    your_set.del(4);
    your_set.del(5).del(6);	// no effect
    your_mark = your_set.size();

    const set<int> c_set = your_set;
    your_set.del(1);
    if ( c_set.has(1) && ! your_set.has(1) )
         ++your_mark;

    your_set+=2;        // put(2)
    your_set+=3;        // put(3)
    your_set+=4;        // put(4)
    your_set+=5;        // put(5)
    set<double> sd;
    sd+=3.14;           // just check += works on other types too
    if ( sd.has(3.14) )
         your_mark = your_set.size();

    set<int> unio = c_set + your_set;     // A+B  ==  unio(A,B)
    your_mark = unio.size();

    cout << "Your mark is " << your_mark << endl;

    return 0;
}
