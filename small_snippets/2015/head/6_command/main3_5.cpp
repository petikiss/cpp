// RemoteControl with 7 button
// add: "tricky" reciver functionality

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


class Stereo
{
  public:
    void on() {std::cout << "Stereo is ON\n";}
    void off() {}
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
  private:
    Stereo* mStereo;
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

    Stereo* stereo = new Stereo();

    StereoOnWithCdCommand* stereoOnWithCdCommand
                                = new StereoOnWithCdCommand(stereo);

    remote.setCommand(1,stereoOnWithCdCommand);
    remote.onButtonWasPressed(1);
}
