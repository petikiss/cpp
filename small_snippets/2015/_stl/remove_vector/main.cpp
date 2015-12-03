
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isFive(int num)
{
   return num==6 ? true : false;
}


class A
{
  public:
   A(int a) : ma(a) {cout << "A: " << ma << "\n";}
   ~A() {cout << "~A\n";}
   A(const A& a) { ma = a.getNumber(); cout << "copyA:"<< ma << "\n";}
   const A& operator=(const A& a) { cout << "op=\n";}
   int getNumber() const {return ma;}
  private:
   A();
   int ma;
};


// function object
class isTen
{
  public:
   bool operator()(const A& num)
      {
         cout << "Is equal?:" << num.getNumber() << endl;
         return num.getNumber()==3 ? true : false;
      }
};


int main()
{
   vector<A> v;
   for(int i = 0; i < 5; ++i)
   {
      cout << i << endl;
      A a(i);
      v.push_back(a);
   }

   cout << "remove if:" << endl;
   vector<A>::iterator it2 = remove_if(v.begin(), v.end(), isTen());
//   v.erase(remove_if(v.begin(), v.end(), isTen()));
   cout << "\n---------------------\n" << endl;

   cout << "A vektor:" << endl;
   int i = 0;
   for(vector<A>::iterator it = v.begin();
       it != v.end();
       ++it)
   {
      cout << i << ":";
      std::cout << (*it).getNumber() << endl;
      ++i;
   }
}
