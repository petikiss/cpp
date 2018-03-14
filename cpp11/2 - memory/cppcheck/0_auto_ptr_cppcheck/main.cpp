#include <iostream>
#include <vector>
#include <list>

#include <algorithm> // copy
#include <memory> // auto_ptr
#include <iterator> // back_inserter


// http://www.gotw.ca/gotw/042.htm


int main()
{
    // ------- OWNERSHIP TEST -------
    {
        std::cout << "------------ OWNERSHIP test ------------" << std::endl;
        std::auto_ptr<int> b(new int);
        std::auto_ptr<int> c;

        *b = 6;
        c = b;

        // std::cout << "Original value: " << *b << std::endl;  // NOK: b lost ownership and get NULL pointer inside!
        std::cout << "Copied value: " << *c << std::endl;  // OK
    }


    // ------- ARRAY TEST -------
    {
        std::cout << "------------ array test ------------" << std::endl;
        static int c = 0;
        struct X
        {
            X() { a = new int[6]; c++;}
            ~X() { delete a; c--;}

            int* a;
        };

        for (int i = 0; i < 3; i++)
        {
            std::auto_ptr<X> v(new X[6]);  // c != 1 NOK
            // std::auto_ptr<X> v(new X); // c == 1 OK
            std::cout << "Value of c: " << c << std::endl;
        }
     }




    // ------- STL TEST ---------------
    {
        std::cout << "------------ STL test ------------" << std::endl;
        struct Employee
        {
        };

        std::vector< std::auto_ptr<Employee> > payroll;
        std::list< std::auto_ptr<Employee> > temp;

        // std::copy( payroll.begin(), payroll.end(), std::back_inserter(temp) );
        std::copy( payroll.begin(), payroll.end(), temp.begin() );
    }

    return 0;
}
