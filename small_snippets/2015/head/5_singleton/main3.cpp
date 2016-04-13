// ChocolateBoiler with singleton pattern



class ChocolateBoiler
{
  public:
    static ChocolateBoiler* getInstance()
    {
        if (mInstance == 0)
        {
            mInstance =  new ChocolateBoiler();
        }
        return mInstance;
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

    // void boil() {...}
    // void drain() {...}
  private:
    ChocolateBoiler()
    {
        empty = true;
        boiled = false;
    }
    static ChocolateBoiler* mInstance;

    bool empty;
    bool boiled;
};

ChocolateBoiler* ChocolateBoiler::mInstance = 0;


int main()
{
    ChocolateBoiler* boiler = ChocolateBoiler::getInstance();
}

