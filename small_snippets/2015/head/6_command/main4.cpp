// The "Meta Command Pattern"
// allows macros of command (execute multiple command at once)
// PARTY TIME !!!!! :)

#include <vector>
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



class MacroCommand : public Command
{
  public:
    MacroCommand(std::vector<Command*> commands) : mCommands(commands) {}
    void execute()
    {
        for(int i = 0; i < mCommands.size();i++)
        {
            mCommands[i]->execute();
        }
    }
  private:
    std::vector<Command*> mCommands;
};


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
    // LightOnCommand* lightOnCommand = ;
    // CeilingFanHighCommand* ceilingFanHighCommand = ;


    // std::vector<Command*> mCommands;
    // commands.push_back(lightOnCommand);
    // commands.push_back(ceilingFanHighCommand);

    // MacroCommand* partyModeCommand = new MacroCommand(commands);

    // RemoteControl remote;
    // remote.setCommand(0, partyModeCommand);

    // remote.onButtonWasPressed(0);
}
