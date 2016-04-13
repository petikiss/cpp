 // ChocolateBoiler multithread compatible - part 2



class ChocolateBoiler
{
  public:
    static ChocolateBoiler* getInstance()
    {
        // Double check locking pattern (DCLP)
        if (mInstance == 0)
        {
            // pthread_mutex_lock // it is expensive :(
            if (mInstance == 0)
            {
                mInstance =  new ChocolateBoiler();
            }
            return mInstance;
        }
    }

    // void fill() {...}
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

