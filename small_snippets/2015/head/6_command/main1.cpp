#include <string>
#include <iostream>

// buttons...
class Slot
{
  public:
    std::string name;
};

class Light : public Slot
{
public:
    Light()  { name = "light";}
    void on() {std::cout << "Light is on! :(\n";}
    void off() {}
};

class HotTube : public Slot
{
public:
  HotTube()
  {
      name = "hottube";
  }
  void jetsOn() {std::cout << "Jets are on! :(\n";}
  void jetsOff() {}
};


class RemoteControl
{
  public:
    RemoteControl()
    {
        slot1 = new Light();
        //slot1 = new HotTube();
    }

    void slot1Pressed()
    {
      if (slot1->name == "light")
      {
          reinterpret_cast<Light*>(slot1)->on();
      }
      else if (slot1->name == "hottube")
      {
          reinterpret_cast<HotTube*>(slot1)->jetsOn();
      }
      // ....
    }
  private:
    Slot* slot1;
    Slot* slot2;
    // Slot* slots[10] ...
};



int main()
{
    RemoteControl remote;

    remote.slot1Pressed();
}
