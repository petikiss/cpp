// Simple Factory - this is NOT a Design Pattern but az idom

#include <string>
#include <iostream>


class Pizza
{
  public:
   void prepare() {}
   void bake() {}
   void cut() {}
  private:
};


class CheesePizza : public Pizza
{
};

class GreekPizza : public Pizza
{
};


// Not only the PizzaShop could use this class!
// Now the changing code is here!
class SimplePizzaFactory
{
  public:
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza = NULL;
      if (type == "cheese")
      {
         pizza = new CheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new GreekPizza();
      }

      return pizza;
   }
};


// CLIENT CODE, which use the SimplePizzaFactory
// PizzaShop will NOT changed if new pizza is introduced!
class PizzaShop
{
  public:
   PizzaShop(SimplePizzaFactory* factory) : mFactory(factory) {}
   Pizza* orderPizza(std::string type)
   {

      Pizza* pizza = mFactory->createPizza(type);

      pizza->prepare();
      pizza->bake();
      pizza->cut();

      return pizza;
   }
  private:
   SimplePizzaFactory* mFactory;  // composition!!!!
};



int main()
{
    SimplePizzaFactory* factory = new SimplePizzaFactory();
    PizzaShop shop(factory);

    shop.orderPizza("cheese");
}
