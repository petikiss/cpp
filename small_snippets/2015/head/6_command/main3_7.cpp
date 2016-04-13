// RemoteControl with 7 button
// add: undo 2 with states (CeilingFan)

#include <iostream>



// Abstract Command
class Command
{
  public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class NoCommand : public Command
{
  public:
    void execute() {std::cout << "No functionality!\n";}
    void undo() {}
};

enum Speed {OFF, LOW, MEDIUM, HIGH};

class CeilingFan
{
  public:
    CeilingFan(std::string location) : mSpeed(OFF), mLocation(location) {}
    void off()     {mSpeed = OFF; std::cout << "Fan set to OFF\n";}
    void low()     {mSpeed = LOW;}
    void medium()  {mSpeed = MEDIUM;}
    void high()    {mSpeed = HIGH; std::cout << "Fan set to HIGH\n";}
    int getSpeed() {return mSpeed;}
  private:
    Speed mSpeed;
    std::string mLocation;
};

class CeilingFanHighCommand : public Command
{
  public:
    CeilingFanHighCommand(CeilingFan* ceilingFan) : mCeilingFan(ceilingFan) {}
    void execute()
    {
        prevSpeed = mCeilingFan->getSpeed();
        mCeilingFan->high();
    }

    void undo()
    {
        if (prevSpeed == OFF)
        {
            mCeilingFan->off();
        }
        else if (prevSpeed == LOW)
        {
            mCeilingFan->low();
        }
        //...
    }
  private:
    CeilingFan* mCeilingFan;
    int prevSpeed;
};






// Invoker
class RemoteControlWithUndo
{
  public:
    RemoteControlWithUndo()
    {
        for(int i = 0; i < 7; i++)
        {
            onButtons[i] = new NoCommand();
            offButtons[i] = new NoCommand();
        }

        undoButton = new NoCommand();
    }

    void setCommand(int number, Command* command /*, on/off type*/)
    {
        delete onButtons[number];
        onButtons[number] = command;
    }

    void onButtonWasPressed(int number)
    {
        undoButton = onButtons[number];
        onButtons[number]->execute();
    }

    void undoButtonWasPressed()
    {
        undoButton->undo();
    }
  private:
    Command* onButtons[7]; // we have 7 button
    Command* offButtons[7];
    Command* undoButton;
};


// Client
int main()
{
    RemoteControlWithUndo remote;

    CeilingFan* ceilingFan = new CeilingFan("Living room");

    CeilingFanHighCommand* ceilingFanHighCommand
                                 = new CeilingFanHighCommand(ceilingFan);


    remote.setCommand(1,ceilingFanHighCommand);
    remote.onButtonWasPressed(1);


    remote.undoButtonWasPressed();
}
