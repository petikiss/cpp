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
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza;
      if (type == "cheese")
      {
         pizza = new CheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new GreekPizza();
      }
   }
};


// CLIENT CODE, which use the SimplePizzaFactory
// PizzaShop will NOT changed if new pizza is introduced!
class PizzaShop
{
  public:
   PizzaShop(std::string factory) : mFactory(factory) {}
   Pizza* orderPizza(std::string type)
   {

      mFactory.createPizza(type);

      pizza->prepare();
      pizza->bake();
      pizza->cut();
   }
  private:
   SimplePizzaFactory mFactory;  // composition!!!!
};



int main()
{
   SimplePizzaFactory factory;
   PizzaShop shop(factory);

   shop.orderPizza("cheese");
}
