// task: ChocolateBoiler can boil chocolate and milk mix
// problem1: drain unbolied mixture
// problem2: fill the boiler when it is full

// What happens, if two instance of Chocolate exists?

class ChocolateBoiler
{
  public:
    ChocolateBoiler()
    {
        empty = true;
        boiled = false;
    }

    void fill()
    {
        if (empty)
        {
            empty = false;
            boiled = false;
            // fill the boiler with the mixture
        }
    }

    void boil()
    {
        if(!empty && !boiled)
        {
            boiled = true;
        }
    }

    void drain()
    {
        if (!empty && boiled)
        {
            empty = true;
        }
    }

  private:
    bool empty;
    bool boiled;
};



int main()
{
    ChocolateBoiler boiler;

    boiler.fill();
    boiler.boil();
    boiler.drain();

    ChocolateBoiler boiler1;

    boiler1.fill();
    boiler1.boil();
    boiler1.drain();
}

