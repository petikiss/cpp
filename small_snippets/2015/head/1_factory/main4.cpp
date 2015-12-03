// Factory method!
// page 129

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


class ChichagoCheesePizza : public Pizza
{
};

class ChichagoGreekPizza : public Pizza
{
};

class NyCheesePizza : public Pizza
{
};

class NyGreekPizza : public Pizza
{
};




class PizzaShop
{
  public:
   PizzaShop() {}
   Pizza* orderPizza(std::string type)
   {

      Pizza* pizza = createPizza(type);

      pizza->prepare();
      pizza->bake();
      pizza->cut();

      return pizza;
   }

  protected:
   // this is abstract -> object creation is in the subclass. This decoules the client code
   // in the superclass from the object creation code in the subclass
   virtual Pizza* createPizza(std::string type) = 0;
};


// Allow the sub-classes to decide about the style of the pizza!
class NewYorkPizzaShop : public PizzaShop
{
  public:
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza;
      if (type == "cheese")
      {
         pizza = new NyCheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new NyGreekPizza();
      }
   }
};

class ChichagoPizzaShop : public PizzaShop
{
  public:
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza;
      if (type == "cheese")
      {
         pizza = new ChichagoCheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new ChichagoGreekPizza();
      }
   }
};


int main()
{
   PizzaShop* chichagoShop = new ChichagoPizzaShop();

   chichagoShop->orderPizza("cheese");
}
