// Very depentent PizzaStore


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


class ChichagoStyleGreekPizza : public Pizza
{
};

class ChichagoStyleCheesePizza : public Pizza
{
};

class NyStyleCheesePizza : public Pizza
{
};

class NyStyleGreekPizza : public Pizza
{
};


class DepententPizzaShop
{
  public:

    // This "Creator" creates all concrete objects instead of delegating to a factory
    Pizza* createPizza(std::string style, std::string type)
    {
        Pizza* pizza = NULL;

        if (style == "Chichago")
        {
            if (type == "cheese")
            {
                // if ChichagoStyleCheesePizza  modified (ex: new parameter added)
                // we may  modify the DepententPizzaShop ...
                // reducing depending to concrete classis is "good" -> formal name: DIP
                pizza = new ChichagoStyleCheesePizza();
            }
            else if (type == "greek")
            {
                pizza = new ChichagoStyleGreekPizza();
            }
        }
        else if (style == "NY")
        {
            if (type == "cheese")
            {
                pizza = new NyStyleCheesePizza();
            }
            else if (type == "greek")
            {
                pizza = new NyStyleGreekPizza();
            }
        }
        return pizza;
    }
};




int main()
{
}
