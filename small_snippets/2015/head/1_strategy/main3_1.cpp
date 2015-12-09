// Principal: Program to an int-erface not an implementation

// wont be Duck classes that will implement the flying behaviour

class Duck
{
  public:
   void quack() {}
   void swim() {}
   virtual void display() = 0;
};


// interface
class FlyBehaviour
{
   virtual void fly() {/* implement default fly behaviour */}
};


class FlyWithWings : public FlyBehaviour
{
   void fly() {/* implement fly*/ }
};

class FlyNoWay : public FlyBehaviour
{
   void fly() {/* no fly */}
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
};

class WoodDuck : public Duck
{
   void display() {}
};

int main()
{
   WoodDuck duck;
}
