#include <string>
#include <iostream>


enum Base  {BASE_EMPTY,  BASE_CLASSIC, BASE_FITNESS};
enum Sauce {SAUCE_EMPTY, SAUCE_TOMATO, SAUCE_BBQ};

class Pizza
{
  public:
   std::string getName() {return mName;}

  protected:
   Pizza(Base base, std::string name) : mBase(base), mName(name) {}
   Sauce mSauce;
   Base  mBase;
   std::string mName;
};


class Margaritha : public Pizza
{
  public:
   Margaritha(Base base) : Pizza(base, "margaritha") {}
};


class Carbonara : public Pizza
{
  public:
   Carbonara(Base base) : Pizza(base, "carbonara") {}
};



class SimplePizzaFactory
{
  public:
   Pizza* createPizza(std::string type)
   {
      Pizza* p;

      if (type == "margaritha")
      {
         p = new Margaritha(BASE_CLASSIC);
      }
      else if (type == "carbonara")
      {
         p = new Carbonara(BASE_FITNESS);
      }
      return p;
   }
};

class PizzaShop
{
  public:
   PizzaShop(SimplePizzaFactory factory) : mFactory(factory) {}
   Pizza* order(std::string type)
   {

      // TODO: if we introduce a new pizza style, this code change :(
      Pizza* p = mFactory.createPizza(type);

      bake(p);
      boxing(p);
      deliver(p);

      return p;
   }

  private:
   void bake(Pizza* p) {std::cout << "Baking a " << p->getName() << " pizza\n";}
   void boxing(Pizza* p) {std::cout << "Boxing a " << p->getName() << " pizza\n";}
   void deliver(Pizza* p) {std::cout << "Delivering a " << p->getName() << " pizza\n";}

   SimplePizzaFactory mFactory;
};


// here begins the code!
int main()
{
   SimplePizzaFactory factory;
   PizzaShop shop(factory);

   Pizza* p = shop.order("margaritha");

   std::cout << "The " << p->getName() << " pizza is delivered\n";

   delete p;
}
