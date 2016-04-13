// RemoteControl with 7 button - simple beginning

#include <iostream>


// Abstract Command
class Command
{
  public:
    virtual void execute() = 0;
};

// Invoker
class RemoteControl
{
  public:
    RemoteControl()
    {
        for(int i = 0; i < 7; i++)
        {
            onButtons[i] = NULL;
            offButtons[i] = NULL;
        }
    }

    void onButtonWasPressed(int number)
    {
        if (onButtons[number] != NULL)
        {
            onButtons[number]->execute();
        }
        else
        {
            std::cout << "On button " << number << " has no functionality!\n";
        }
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
