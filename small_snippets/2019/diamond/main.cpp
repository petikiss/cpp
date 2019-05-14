


class Base
{
public:
    int get() { return data;}

private:
    int data;
};



class Derived1: public virtual Base
{
};

/*
class Derived2 : public virtual Base
{
};


class Multiple: public Derived1, public Derived2
{
};
*/


int main()
{
//    Multiple m;
    Derived1 d1;
}

