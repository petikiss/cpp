// First try to report changes towards the display1 and display2 ...

// problems with this implementation:
//
// - we are coding to concrete implementations, not interfaces
// - for every new display element, we need to alter code
// - we have no way to add (or remove) display elements at run time
// - we havent encapsulated part that changes



class Display
{
   public:
   virtual void update(int temp, int humadity, int pressure) = 0; // common interface :)
};


class ConditionsDisplay : Display
{
  public:
   void update(int temp, int humadity, int pressure) {}
};


class StatisticsDisplay: Display
{
  public:
   void update(int temp, int humadity, int pressure) {}

};


class WeatherData
{
  public:
   int getTemperature() {}
   int getHumadity() {}
   int getPressure() {}

   // this is called, when somethig has changed
   void measurementsChanged()
   {
      int temp = getTemperature();
      int humadity = getHumadity();
      int pressure = getPressure();

      mConditionsDisplay.update(temp, humadity, pressure); // coding to concrete implementations :(
      mStatisticsDisplay.update(temp, humadity, pressure);
   }
  private:
   ConditionsDisplay mConditionsDisplay;
   StatisticsDisplay mStatisticsDisplay;
};



int main()
{
   WeatherData weatherData;

}
