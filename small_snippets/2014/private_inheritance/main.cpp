class Engine {
public:
  Engine(int numCylinders)
  {
  }

  void start();                 // Starts this Engine
};



// class Car {
// public:
//   Car() : e_(8) { }             // Initializes this Car with 8 cylinders
//   void start() { e_.start(); }  // Start this Car by starting its Engine
// private:
//   Engine e_;                    // Car has-a Engine
// };


class Car : private Engine {    // Car has-a Engine
public:
  Car() : Engine(8) { }         // Initializes this Car with 8 cylinders
    using Engine::start;          // Start this Car by starting its Engine
  private:
    //Engine::Engine();
    //void Engine::start();
};


int main()
{
    Car* c = new Car();
    //Engine* e = new Engine(8);
    //Engine* e = 
    dynamic_cast<Engine*>(c);

}
