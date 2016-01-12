#include <string>
#include <iostream>

class Beverage
{
  public:
    Beverage() {}
    std::string getDescription();
    virtual int cost() = 0;
  private:
    std::string description;
};


class DarkRoast : public Beverage
{
  public:
    int cost()
    {
        return 14;
    }
};


class Espresso : public Beverage
{
  public:
    int cost()
    {
        return 15;
    }
};


class CondimentDecorator : public Beverage
{
  public:
    int cost() = 0;
  protected:
    Beverage* mBeverage;  // has-a relation!!!!!
};


class Milk : public CondimentDecorator
{
  public:
    Milk(Beverage* b)
    {
        mBeverage = b;
    }
    int cost() {return mBeverage->cost() + 3;}
};


class Soy : public CondimentDecorator
{
  public:
    Soy(Beverage* b)
    {
        mBeverage = b;
    }
    int cost() {return mBeverage->cost() + 2;}
};





int main()
{
    Beverage*  e = new Espresso();
    Beverage* espressoWithMilk = new Milk(e);
    std::cout << "Espresso with milk cost: " << espressoWithMilk->cost() << std::endl;


    Beverage* dr = new DarkRoast();
    Beverage* darkRoastWithSoyAndDoubbleMilk = new Milk(new Milk( new Soy(dr)));
    std::cout << "Dark Roast with Soy and doubble milk cost: " << darkRoastWithSoyAndDoubbleMilk->cost() << std::endl;
}
