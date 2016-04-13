// RemoteControl with 7 button
// add: null object

#include <iostream>


// Abstract Command
class Command
{
  public:
    virtual void execute() = 0;
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

    remote.onButtonWasPressed(1);
}
