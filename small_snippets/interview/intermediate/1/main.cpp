#include <string>
#include <iostream>
#include <vector>


// using the std namespace
using namespace std;


// forward declarations
class Carbonara;
class Margaritha;
class PizzaShop;


// classes
class Pizza
{
  public:
   void bakeAPizza() {std::cout << "Baking a " << getName() << " pizza\n";}
   void boxingAPizza() {std::cout << "Baking a " << getName() << " pizza\n";}
   void deliverAPizza() {std::cout << "Delivering a " << getName() << " pizza\n";}
   std::string eatAPizza() {std::cout << "I ate the pizza!\n"; }

   virtual string getName() { return "";}
   string& getSauce() {return sauce;}
  private:
   string sauce; // Sauce can be "tomato", "sour cream", "bbq"
};


// base = "thin", "medium"
class Margaritha : public Pizza
{
  public:
   Margaritha(string bs)
   {
      base = bs;
      name = "margaritha";
   }

   string getName() {return name;}
  private:
   string base;
   string name;
};


class Carbonara : public Pizza
{
  public:
   Carbonara(string b)
   {
      name = "carbonara";
      base = b;
   }

   string getPizzaName() {return name;}
  private:
   string base;
   string name;
};


// class Bolognese : public Pizza
// {
//   public:
//    Bolognese(string b)
//    {
//    }
// };


class PizzaShop
{
  public:
   Pizza* order(std::string type)
   {
      Pizza* p = new Pizza();

      // TODO: if we introduce a new pizza style, this code change :(

      // order type
      if (type == "margaritha")
      {
         p = new Margaritha("base_thin"); // base is thin
         string sauceOnThePizza = p->getSauce();
         sauceOnThePizza = "tomato";
      }
      else if (type == "Carbonara")
      {
         p = new Carbonara("base_medium"); // base is thick
         string sauceOnThePizza = p->getSauce();
         sauceOnThePizza = "mustard";
      }

      return p;
   }
};



// here begins the code!
int main()
{
   PizzaShop shop;

   Pizza* p = shop.order("Carbonara");

   p->bakeAPizza();
   p->boxingAPizza();
   p->deliverAPizza();

   p->eatAPizza();

   delete p;
}
