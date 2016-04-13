// ChocolateBoiler multithread compatible - part 1



class ChocolateBoiler
{
  public:
    static ChocolateBoiler* getInstance()
    {
        // pthread_mutex_lock // it is expensive :(
        if (mInstance == 0)
        {
            mInstance =  new ChocolateBoiler();
        }
        return mInstance;
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
