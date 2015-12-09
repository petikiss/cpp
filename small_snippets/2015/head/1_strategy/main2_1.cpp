class Duck
{
  public:
   virtual void quack();
   virtual void swim() = 0;
   virtual void display() = 0;
};


class Flyable
{
   virtual void fly() = 0;
};


class MallardDuck : public Duck , public Flyable
{
   void quack() {}
   void swim() {}
   void display() {}
   void fly() {} // have to implement this -> DUPLICATE CODE
};


class RedHeadDuck : public Duck, public Flyable
{
   void quack() {}
   void swim() {}
   void display() {}
   void fly() {} // have to implement this -> DUPLICATE CODE
};

class RubberDuck : public Duck
{
   void quack() {}
   void swim() {}
   void display() {}
};

class WoodDuck : public Duck
{
   void quack() {}
   void swim() {}
   void display() {}
};

int main()
{
   WoodDuck duck;
}
