        #include <iostream>

        using namespace std;

        class class0 
        {
           public:
            virtual ~class0(){}

            protected:

            char p;

            public:

            char getChar();
        };

        class class1 : public class0
        {
            public:
            void printChar();
        };

        void class1::printChar()
        {
            cout  << "True" << endl;
        }

        int main() 
        {
           class0 c0;

           c0.getChar();

            class1 c;

            c.printChar();

            return 1;
        }
