class Duck
{
  public:
   void quack();
   void swim();
   virtual void display() = 0;
   void fly();
};


class MallardDuck : public Duck
{
   void display() {}
};


class RedHeadDuck : public Duck
{
   void display() {}
};

class RubberDuck : public Duck
{
   void display() {}
   void fly() { /*no nothing*/ }  // ??? Can a rubber duck fly ???
};

class WoodDuck : public Duck
{
   void display() {}
   void fly() { /*no nothing*/ }  // ??? Can a wood duck fly ???
};

int main()
{
   WoodDuck duck;
}
