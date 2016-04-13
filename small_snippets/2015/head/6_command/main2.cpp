#include <iostream>


// Reciever : knows how to perform an action
class Light
{
  public:
    // action ...
    void on() {std::cout << "Light is on! :)\n";};
};


// Abstract command : interface
class Command
{
  public:
    virtual void execute() = 0;
};


// Concrete command : defines a binding between an action and a Reciver
class LightOnCommand : public Command
{
  public:
    LightOnCommand(Light* light) : mLight(light) {}
    void execute()
    {
        mLight->on();
    }
  private:
    Light* mLight; // reciever
};


// Invoker : holds command, and ask the command to carry out a request
// this has only one slot (this is quite simple!)
class SimpleRemoteControl
{
  public:
    SimpleRemoteControl() {}
    void setCommand(Command* command)
    {
        slot1 = command;
    }

    void buttonWasPressed()
    {
        slot1->execute();
    }
  private:
    Command* slot1; // button1
};


// Client!
int main()
{
    SimpleRemoteControl remote;


    Light* light = new Light();
    LightOnCommand* lightOn = new LightOnCommand(light);

    remote.setCommand(lightOn);
    remote.buttonWasPressed();
}
