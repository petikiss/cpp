#include <string>
#include <iostream>

class Beverage
{
  public:
    Beverage() : milk(false), soy(false) {}
    std::string getDescription();
    int cost()
    {
        int cost = 0;
        if (hasMilk()) cost += 3;
        if (hasSoy()) cost += 2;

        return cost;
    }
    bool hasMilk() { return milk;}
    bool hasSoy() {return soy;}
    void setMilk() {milk = true;}
    void setSoy() {soy = true;}
  private:
    std::string description;
    bool milk;
    bool soy;
};


class DarkRoast : public Beverage
{
  public:
    int cost()
    {
        int cost = Beverage::cost();
        return cost + 10;
    }
};


class Espresso : public Beverage
{
  public:
    int cost()
    {
        int cost = Beverage::cost();
        return cost + 15;
    }
};



int main()
{
    DarkRoast dr;
    Espresso e;

    e.setMilk();

    dr.setMilk();
    dr.setSoy();

    std::cout << "DarkRoast cost: " << dr.cost() << std::endl;
    std::cout << "Espresso cost: " << e.cost() << std::endl;
}
