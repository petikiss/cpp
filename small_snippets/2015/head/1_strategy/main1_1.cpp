
class Duck
{
  public:
   void quack() {}
   void swim()  {};
   virtual void display() = 0;
};


class MallardDuck : public Duck
{
   void display() {}
};


class RedHeadDuck : public Duck
{
   void display() {}
};


int main()
{
   RedHeadDuck duck;
}
