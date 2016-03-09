// Factory

#include <string>
#include <iostream>


// Abstract Products
class Dough {};
class Sauce {};
class Cheese {};
class Clam {};


// Abstract Factory
// its job to create a set of Products
class PizzaIngredientFactory
{
  public:
    virtual Dough*  createDough() = 0;
    virtual Sauce*  createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    virtual Clam*   createClam() = 0;
};


// Concrete Products
class ThinCrustDough : public Dough {};
class MarianaSauce :   public Sauce {};
class ReggianoCheese : public Cheese {};
class FreshClam :      public Clam {};


// Concrete Factory 1
class NyPizzaIngredientFactory : public PizzaIngredientFactory
{
  public:
    // this is an abstract factory methods!
    // subclass owerride this function, and create an object
    Dough* createDough()
    {
        std::cout << "Thin crust dough." << std::endl;
        return new ThinCrustDough();
    }

    Sauce* createSauce()
    {
        std::cout << "Marina sauce." << std::endl;
        return new MarianaSauce();
    }

    Cheese* createCheese()
    {
        std::cout << "Reggiano cheese" << std::endl;
        return new ReggianoCheese();
    }

    Clam* createClam()
    {
        return new FreshClam();
    }
};

// Concrete Products
class ThickCrustDough : public Dough {};
class PlumTomatoSauce : public Sauce {};
class Mozzarella : public Cheese {};
class FrozenClam : public Clam {};


// Concrete Factory 2
class ChichagoPizzaIngredientFactory : public PizzaIngredientFactory
{
  public:
    Dough* createDough()
    {
        return new ThickCrustDough();
    }

    Sauce* createSauce()
    {
        return new PlumTomatoSauce();
    }

    Cheese* createCheese()
    {
        return new Mozzarella();
    }

    Clam* createClam()
    {
        return new FrozenClam();
    }
};

// ----------------------------------------------------------------------------------------


// Client
class Pizza
{
  public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;

//  public:
    Dough*  mDough;
    Sauce*  mSauce;
    Cheese* mCheese;
    Clam*   mClam;
};


// Concrete client 1
class CheesePizza : public Pizza
{
  public:
    CheesePizza(PizzaIngredientFactory* pizzaIngredientFactory) :
                                        mPizzaIngredientFactory(pizzaIngredientFactory) {}

    void prepare()
    {
        std::cout << "Preparing cheese pizza with: " << std::endl;

        // Concrete Pizza code uses the factory. It has been composed.
        mDough = mPizzaIngredientFactory->createDough();
        mSauce = mPizzaIngredientFactory->createSauce();
        mCheese = mPizzaIngredientFactory->createCheese();
    }

    void bake() {std::cout << "Bake it!" << std::endl;}
    void cut()  {std::cout << "Cut it!" << std::endl;}
    void box()  {std::cout << "Box it!" << std::endl;}
  private:
    PizzaIngredientFactory* mPizzaIngredientFactory;
};

// Concrete client 2
class ClamPizza : public Pizza
{
  public:
    ClamPizza(PizzaIngredientFactory* pizzaIngredientFactory) :
                                      mPizzaIngredientFactory(pizzaIngredientFactory) {}

    void prepare()
    {
        mDough = mPizzaIngredientFactory->createDough();
        mSauce = mPizzaIngredientFactory->createSauce();
        // mCheese = mPizzaIngredientFactory->createCheese();
        mClam = mPizzaIngredientFactory->createClam();
    }

    void bake() {}
    void cut()  {}
    void box()  {}
  private:
    PizzaIngredientFactory* mPizzaIngredientFactory;
};



// ----------------------------------------------------------------------------------------

class PizzaStore
{
  public:
   PizzaStore() {}
    // orderPizza does a lot of things with Pizza, but it is abstract, so this function
    // doesnt know the exact type -> so they are decoupled
   Pizza* orderPizza(std::string type)
   {
      Pizza* pizza = createPizza(type);

      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();

      return pizza;
   }

  protected:
   // this is abstract -> object creation is in the subclass. This decoules the client code
   // in the superclass from the object creation code in the subclass
   virtual Pizza* createPizza(std::string type) = 0;
};


class NyPizzaStore : public PizzaStore
{
  public:

    // Abstract Factory Method
    Pizza* createPizza(std::string type)
    {
        Pizza* pizza = NULL;
        PizzaIngredientFactory* nyIngredientFactory = new NyPizzaIngredientFactory();

        if (type == "cheese")
        {
            pizza = new CheesePizza(nyIngredientFactory);
        }
        else if (type == "clam")
        {
            pizza = new ClamPizza(nyIngredientFactory);
        }

        return pizza;
    }
};



int main()
{
    PizzaStore* nyPizzaStore = new NyPizzaStore();

    Pizza* pizza = nyPizzaStore->orderPizza("cheese");
}






