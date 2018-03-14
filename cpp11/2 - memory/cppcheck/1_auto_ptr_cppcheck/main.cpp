    #include <iostream>
    #include <memory>
    #include <string>
    using namespace std;

    int c = 0;

    struct X {
        X() : s( "1234567890" ) { ++c; }
       ~X()                     { --c; }
        string s;
    };

    template <class T>
    void f( size_t n ) {
        {
            auto_ptr<T> p1( new T );
            auto_ptr<T> p2( new T[n] );
        }
        cout << c << " ";   // report # of X objects
    }                       // that currently exist

    int main() {
        while( true ) {
            f<X>(100);
        }
    }

