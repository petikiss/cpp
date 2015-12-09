// When something changed, the measurementsChanged() called,
// we should report this towards the CurrentConditionsDisplays!


class Display
{
   public:
   virtual void update(int temp, int humadity, int pressure) = 0;
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
      /* this should be implemented! */
   }
  private:
};




int main()
{
   WeatherData weatherData;
}
