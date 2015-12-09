// Use Observer design pattern


class Observer
{
  public:
   // what happens if we introduce a new parameter? :( -> change!
   virtual void update(int temp, int humadity, int pressure) = 0;
};

class Subject
{
  public:
   virtual void registerObserver(Observer* o) = 0;
   virtual void deregisterObserver(Observer* o) = 0;
  protected:
   virtual void notifyObservers() = 0;
};

class Display
{
   public:
   virtual void display() {}
};


class ConditionsDisplay : public Display, public Observer
{
  public:
   ConditionsDisplay(Subject* weatherData)
   {
      mWeatherData = weatherData; // this is needed for deregister!
      weatherData->registerObserver(this);
   }

   void update(int temp, int humadity, int pressure)
   {
      display();
   }
  private:
   Subject* mWeatherData;
};


class StatisticsDisplay: public Display, public Observer
{
  public:
   StatisticsDisplay(Subject* weatherData)
   {
      mWeatherData = weatherData;
      weatherData->registerObserver(this);
   }

   void update(int temp, int humadity, int pressure)
   {
      // this is not the best place to call display! MVC pattern!
      display();
   }
  private:
   Subject* mWeatherData;
};


class WeatherData : public Subject
{
  public:
   void registerObserver(Observer* o) {}
   void deregisterObserver(Observer* o) {}

   int getTemperature() {}
   int getHumadity() {}
   int getPressure() {}

   // this is called, when somethig has changed
   void measurementsChanged()
   {
      notifyObservers();
   }
  protected:
   void notifyObservers()
   {
      int temp = getTemperature();
      int humadity = getHumadity();
      int pressure = getPressure();

      // foreach observer->update(temp, humadity, pressure);
   }
};



int main()
{
   WeatherData weatherData;

   ConditionsDisplay display1(&weatherData);
   StatisticsDisplay display2(&weatherData);
}
