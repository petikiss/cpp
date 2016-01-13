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

class PizzaShop
{
  public:
   Pizza* orderPizza(std::string type)
   {

      // this part is NOT closed for modification!
      Pizza* pizza;
      if (type == "cheese")
      {
         pizza = new CheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new GreekPizza();
      }


      pizza->prepare();
      pizza->bake();
      pizza->cut();

      return pizza;
   }
  private:
};



int main()
{
   PizzaShop shop;

   shop.orderPizza("cheese");
}
