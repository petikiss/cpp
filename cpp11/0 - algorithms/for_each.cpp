// std::for_each function from <algorithm>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class printer
{
public:
    void operator()(int i)
    {
        std::cout << i << endl;
    }
};


void fgv(int i)
{
    cout << i << endl;
}


int main()
{

std::vector<int> v = {1,2,3,4,5};

printer functor;
for_each(v.begin(), v.end(), functor);
functor.operator()(15);
cout << "--------";

for_each(v.begin(), v.end(), fgv);
cout << "--------";

for_each(v.begin(), v.end(), [](int i){cout << i << endl;});
cout << "--------";

}
