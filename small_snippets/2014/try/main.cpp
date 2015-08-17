#include <string>
#include <stdexcept>

using namespace std;

struct A
{
 A(int n)
 {
    if (n>10)
	throw range_error("out of range");
 }
};

struct B: A
{
private:
 string s;
public:

B(int v, const string str) :
 A(v), s(str) {}
};



int main()
{
    B b(11, "test"); //construction will fail due to an exception
}
