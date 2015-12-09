class Duck
{
  public:
   void quack() {}
   void swim()  {}
   virtual void display() = 0;
   virtual void fly() {}   // INTRODUCED
};


class MallardDuck : public Duck
{
   void display() {}
};


class RedHeadDuck : public Duck
{
   void display() {}
};

// INTRODUCED
class RubberDuck : public Duck
{
   void display() {}
   void fly() { /*no nothing*/ }  // ??? Can a rubber duck fly ???
};



int main()
{
   RedHeadDuck duck;
}
