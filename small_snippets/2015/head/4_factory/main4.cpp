// Factory method!
// decoules the client code (who use the factory method)  in the superclass from the
// object creation code in the subclass

#include <string>
#include <iostream>

// Product
class Pizza
{
  public:
   void prepare() {}
   void bake() {}
   void cut() {}
  private:
};


// Concrete Product
// the only differences between concrete pizzas is the different ingredients!
// the pizzas are made just the same (name, dough, sauce)
class ChichagoCheesePizza : public Pizza
{
    // name = "Chichago style pizza with cheese";
    // dough = "Thick Crust Dough";
    // sauce = "Plum Tomato Sauce";
};

class ChichagoGreekPizza : public Pizza
{
    // name =
    // dough =
    // sauce =
};

class NyCheesePizza : public Pizza
{
    // name = "Ny style pizza with cheese";
    // dough = "Thin Crust Dough";
    // sauce = "Mariana Sauce";
};

class NyGreekPizza : public Pizza
{
    // name =
    // dough =
    // sauce =
};


// abstract creator class
class PizzaShop
{
  public:
   PizzaShop() {}
    // orderPizza does a lot of things with Pizza, but it is abstract, so this function
    // doesnt know the exact type -> so they are decoupled
   Pizza* orderPizza(std::string type)
   {
      // client code in the super class should knows only the abstract type
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


// Let the sub-classes to decide about the style of the pizza!!!!
class NewYorkPizzaShop : public PizzaShop
{
  public:
    // Abstract Factory Method
    Pizza* createPizza(std::string type)
    {
        Pizza* pizza = NULL;
        if (type == "cheese")
        {
            pizza = new NyCheesePizza();
        }
        else if (type == "greek")
        {
            pizza = new NyGreekPizza();
        }

        return pizza;
    }
};

class ChichagoPizzaShop : public PizzaShop
{
  public:
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza = NULL;
      if (type == "cheese")
      {
         pizza = new ChichagoCheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new ChichagoGreekPizza();
      }

      return pizza;
   }
};


int main()
{
   PizzaShop* chichagoShop = new ChichagoPizzaShop();

   Pizza *pizza = chichagoShop->orderPizza("cheese");
}
