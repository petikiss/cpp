// Different factories

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


class NyStyleCheesePizza : public Pizza
{
};


class NyStyleGreekPizza : public Pizza
{
};


class ChichagoStyleGreekPizza : public Pizza
{
};


class ChichagoStyleCheesePizza : public Pizza
{
};

// Not only the PizzaShop could use this class!
class SimplePizzaFactory
{
  public:
    virtual Pizza* createPizza(std::string type) = 0;
};


class NewYorkPizzaFactory : public SimplePizzaFactory
{
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza = NULL;
      if (type == "cheese")
      {
         pizza = new NyStyleCheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new NyStyleGreekPizza();
      }

      return pizza;
   }
};


class ChichagoPizzaFactory: public SimplePizzaFactory
{
   Pizza* createPizza(std::string type)
   {
      Pizza* pizza = NULL;
      if (type == "cheese")
      {
         pizza = new ChichagoStyleCheesePizza();
      }
      else if (type == "greek")
      {
         pizza = new ChichagoStyleGreekPizza();
      }

      return pizza;
   }
};


class PizzaShop
{
    virtual Pizza* orderPizza(std::string type) = 0;
};

// 1 CLIENT CODE, which use the SimplePizzaFactory
class NyPizzaShop : public PizzaShop
{
  public:
   NyPizzaShop(SimplePizzaFactory* factory) : mFactory(factory) {}
   Pizza* orderPizza(std::string type)
   {

      Pizza* pizza = mFactory->createPizza(type);

      // check NULL ...
      pizza->prepare();
      pizza->bake();
      pizza->cut();

      return pizza;
   }
  private:
   SimplePizzaFactory* mFactory;  // composition!!!!
};


// Problem:
// What happens, if new "ChichagoShop" open, and do the things differently?
// Ex:
class ChichagoPizzaShop : public PizzaShop
{
  public:
   ChichagoPizzaShop(SimplePizzaFactory* factory) : mFactory(factory) {}
   Pizza* orderPizza(std::string type)
   {

      Pizza* pizza = mFactory->createPizza(type);

      // check NULL ...
      pizza->prepare();
      pizza->bake();
      // FORGET TO CUT????? hmmm... We need control! We need to handle "Shop and Pizza" creation together!

      return pizza;
   }
  private:
   SimplePizzaFactory* mFactory;
};


int main()
{
    SimplePizzaFactory* nyFactory = new NewYorkPizzaFactory();
    NyPizzaShop nyShop(nyFactory);
    nyShop.orderPizza("cheese");


    // new shop open
    SimplePizzaFactory* chichagoFactory = new ChichagoPizzaFactory();
    ChichagoPizzaShop chichagoShop(chichagoFactory);
    chichagoShop.orderPizza("cheese");
}
