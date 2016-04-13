// Singleton




class Singleton
{
  public:
    static Singleton* getInstance()
    {
        if (mInstance == 0)
        {
            mInstance = new Singleton();
        }
        return mInstance;
    }

  private:
    Singleton() {}
    // copy/assign
    static Singleton* mInstance;
};

Singleton* Singleton::mInstance = 0;


int main()
{
    Singleton* singleton = Singleton::getInstance();

    // delete singleton
}



// class Singleton2
// {
//     static Singleton2 getInstance()
//     {
//         Singleton2 singleton;
//         return singleton;
//     }
// };
