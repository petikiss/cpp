#include <iostream>

class Test
{
    public:
	// ENNEK CONST FUGGVENYNEK KELL LENNIE!!
	int getMember() {std::cout << "OK\n"; return m_member;}
    private:
	int m_member;
};



bool f(const Test& t)
{
    t.getMember();
}




int main()
{
    Test t;
    f(t);


return 0;
}