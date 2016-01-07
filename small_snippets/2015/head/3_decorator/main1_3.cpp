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
        return 10;
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
  private:
    Beverage b;
};


class Milk : public CondimentDecorator
{
  public:
    int cost() {}
};


class Soy : public CondimentDecorator
{
  public:
    int cost() {}
};





int main()
{
    DarkRoast dr;
    Espresso e;


    // std::cout << "DarkRoast cost: " << dr.cost() << std::endl;
    // std::cout << "Espresso cost: " << e.cost() << std::endl;
}
