#include <iostream>

// Principal: Program to an int-erface not an implementation



// ----------------------------------------------------------
class FlyBehaviour
{
  public:
   virtual void fly() {/* implement default fly behaviour */}
};


class FlyWithWings : public FlyBehaviour
{
  public:
   void fly() {/* implement fly*/ std::cout << "I am flying!\n";  }
};

class FlyNoWay : public FlyBehaviour
{
  public:
   void fly() {/* no fly */}
};

// ----------------------------------------------------------

class Duck
{
  public:
   void quack() {}
   void swim() {}
   virtual void display() = 0;
   void performFly() { flyBehaviour->fly(); /*delegate the behaviour*/ }
   void setFlyBehaviour(FlyBehaviour* f) { flyBehaviour = f; /* change the behaviour at runtime*/}
  protected:
   FlyBehaviour * flyBehaviour; // DELEGATE the flying behaviour (interface type, not a concrete class implementation)
};


class MallardDuck : public Duck
{
  public:
   MallardDuck()
   {
      flyBehaviour = new FlyWithWings(); // NOT program to an implementation: this is concrete implementation :(
   }
   void display() {}
};


class RedHeadDuck : public Duck
{
  public:
   void display() {}
};

class RubberDuck : public Duck
{
  public:
   void display() {}
};

class WoodDuck : public Duck
{
  public:
   void display() {}
};

// ----------------------------------------------------------

int main()
{
   MallardDuck duck;
   duck.performFly();
}
