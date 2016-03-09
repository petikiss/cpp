// Factory


class Dough {};
class Sauce {};
class Cheese {};



class PizzaIngredientFactory
{
  public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() =0;
};


class ThinCrustDough : public Dough {};
class MarianaSauce : public Sauce {};
class ReggianoCheese : public Cheese {};


class NyPizzaIngredientFactory : public PizzaIngredientFactory
{
  public:
    Dough* createDough()
    {
        return new ThinCrustDough();
    }

    Sauce* createSauce()
    {
        return new MarianaSauce();
    }

    Cheese* createCheese()
    {
        return new ReggianoCheese();
    }
};


class ThickCrustDough : public Dough {};
class PlumTomatoSauce : public Sauce {};
class Mozzarella : public Cheese {};

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
};

// ----------------------------------------------------------------------------------------



class Pizza
{
  public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;

//  public:
    Dough mDough;
    Sauce mSauce;
    Cheese mCheese;
};


// we dont need two different cheese pizza (ChichagoCheesePizza, NyCheesePizza)
// the IngredientFactory will handle the regional differencies
class CheesePizza : public Pizza
{
  public:
    CheesePizza(PizzaIngredientFactory* pizzaIngredientFactory) :
                                        mPizzaIngredientFactory(pizzaIngredientFactory) {}

    void prepare()
    {
    }

    void bake() {}
    void cut()  {}
    void box()  {}
  private:
    PizzaIngredientFactory* mPizzaIngredientFactory;
};


// ----------------------------------------------------------------------------------------





int main()
{
}






