// RemoteControl with 7 button
// add: parametrized command with "reciver"

#include <iostream>


class Light
{
  public:
    void on() {std::cout << "Light is ON\n";}
    void off() {}
};

// Abstract Command
class Command
{
  public:
    virtual void execute() = 0;
};

class LightOnCommand : public Command
{
  public:
    LightOnCommand(Light* light) : mLight(light) {}
    void execute()
    {
        mLight->on();
    }
  private:
    Light* mLight;
};

class NoCommand : public Command
{
  public:
    void execute() {std::cout << "No functionality!\n";}
};


// Invoker
class RemoteControl
{
  public:
    RemoteControl()
    {
        for(int i = 0; i < 7; i++)
        {
            onButtons[i] = new NoCommand();
            offButtons[i] = new NoCommand();
        }
    }

    void setCommand(int number, Command* command /*, on/off type*/)
    {
        delete onButtons[number];
        onButtons[number] = command;
    }

    void onButtonWasPressed(int number)
    {
        onButtons[number]->execute();
    }
  private:
    Command* onButtons[7]; // we have 7 button
    Command* offButtons[7];
};


// Client
int main()
{
    RemoteControl remote;

    Light* light = new Light();

    // Command encapsulates the reciver!!!
    LightOnCommand* lightOnCommand = new LightOnCommand(light);

    remote.setCommand(1,lightOnCommand);
    remote.onButtonWasPressed(1);
}
