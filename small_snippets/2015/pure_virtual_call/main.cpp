#include <iostream>

// http://stackoverflow.com/questions/5481941/c-pure-virtual-function-have-body
// www.programmerinterview.com/index.php/c-cplusplus/pure-virtual-function/

// When a function is declared pure virtual, it simply means that this function cannot get called dynamically,
// through a virtual dispatch mechanism.
// Yet, this very same function can easily be called statically, without virtual dispatch.

class S
{
  virtual void foo() = 0;
   // {
   // function declaration cannot provide both a pure-specifier and a definition
   // }
};

void S::foo()
{
  // body for the pure virtual function `S::foo`
}

struct D : S
{
  void foo()
  {
    S::foo(); // static call to `S::foo` from derived class
  }
};

int main()
{
  D d;
  d.S::foo(); // another static call to `S::foo`
}
