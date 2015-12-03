
#include <algorithm>
#include <vector>
#include <iostream>


class A
{
  public:
   A(int a) : mId(a) {std::cout << "ctor\n";}
   ~A() {std::cout << "dtor\n";}
   A(const A& a) { std::cout << "copy\n"; mId = a.mId;}
   A& operator=(const A& a)
      {
         std::cout << "op=\n";
         if ( &a == this)
         {
            return *this;
         }
         std::cout << "mId: " << mId << std::endl;
         mId = a.mId;
         return *this;
      }
   int getId() const {return mId;}
  private:
   int mId;
};


bool isBigger(const A* a)
{
//   return true;
//   std::cout << "isBigger: " << a->getId() << std::endl;

   if (a->getId() > 1)
   {
//      std::cout << "true\n";
      return true;
   }
   return false;
}

class Helper
{
  public:
   bool operator()(const A* a)
      {
         if (a->getId() > 1)
         {
            return true;
         }
         return false;
      }
};


void deleteA(A* a)
{
   delete a;
}


int main()
{
   std::vector<A*> v;
   v.reserve(5);
   for(int i = 0; i < 5; ++i)
   {
      v.push_back(new A(i));
      std::cout << std::endl;
   }

   std::cout << "remove_if\n";

   std::vector<A*>::iterator it = std::remove_if(v.begin(), v.end(), Helper());

   for_each(it, v.end(), deleteA);
   v.erase(it,v.end());


   std::cout << "----" <<std::endl;
   std::cout << "Size: " << v.size() << std::endl;
   for (std::vector<A*>::const_iterator it = v.begin();
        it != v.end();
        ++it)
   {
      std::cout << (*it)->getId() << std::endl;
   }
}
