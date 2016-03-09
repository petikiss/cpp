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




int main()
{
}






