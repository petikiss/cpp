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
    Singleton();
    static Singleton* mInstance;
};




int main()
{
    Singleton* singleton = Singleton::getInstance();
}
