// RemoteControl with 7 button
// add: undo

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


class Stereo
{
  public:
    void on() {std::cout << "Stereo is ON\n";}
    void off() {std::cout << "Stereo is OFF\n";}
    void setCd() {std::cout << "CD set...\n";}
    void setDvd() {}
    void setRadio() {}
    void setVolume() {std::cout << "Volume: 15\n";}
};


class StereoOnWithCdCommand : public Command
{
  public:
    StereoOnWithCdCommand(Stereo* stereo) : mStereo(stereo) {}

    void execute()
    {
        mStereo->on();
        mStereo->setCd();
        mStereo->setVolume();
    }

    void undo()
    {
        mStereo->off();
    }
  private:
    Stereo* mStereo;
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

    Stereo* stereo = new Stereo();

    StereoOnWithCdCommand* stereoOnWithCdCommand
                                = new StereoOnWithCdCommand(stereo);
    remote.setCommand(1,stereoOnWithCdCommand);
    remote.onButtonWasPressed(1);


    remote.undoButtonWasPressed();
}
