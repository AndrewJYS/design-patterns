#include <iostream>
#include <string>
using namespace std;

class PopcornPopper;
class TheaterLights;
class Screen;
class Projector;
class StreamingPlayer;
class Amplifier;
class Tuner;

class PopcornPopper
{
public:
    void on() { cout << "Popcorn Popper on" << endl; }
    void off() { cout << "Popcorn Popper off" << endl; }
    void pop() { cout << "Popcorn Popper works" << endl; }
    void toString() { cout << "Popcorn Popper" << endl; }
};

class TheaterLights
{
public:
    void on() { cout << "theater lights on" << endl; }
    void off() { cout << "theater lights off" << endl; }
    void dim(int percent) { cout << "theater lights dimming to " << percent << "%" << endl; }
    void toString() { cout << "theater lights" << endl; }
};

class Screen
{
public:
    void up() { cout << "screen is going up" << endl; }
    void down() { cout << "screen is going down" << endl; }
    void toString() { cout << "screen" << endl; }
};

class Projector
{
public:
    StreamingPlayer* player;

    void on() { cout << "projector on" << endl; }
    void off() { cout << "projector off" << endl; }
    void setInput(StreamingPlayer* player) { this->player = player; cout << "projector has inputted streaming player" << endl; }
    void tvMode() { cout << "projector in tv mode" << endl; }
    void wideScreenMode() { cout << "projector in wide screen mode" << endl; }
    void toString() { cout << "projector" << endl; }
};

class StreamingPlayer
{
public:
    Amplifier* amplifier;

    void on() { cout << "streaming player on" << endl; }
    void off() { cout << "streaming player off" << endl; }
    void pause() { cout << "streaming player paused" << endl; }
    void play(string movie) { cout << "streaming player plays " << movie << endl; }
    void setSurroundAudio() { this->amplifier = amplifier;  cout << "streaming player set surround audio" << endl; }
    void setTwoChannelAudio() { this->amplifier = amplifier;  cout << "streaming player set two channel audio" << endl; }
    void stop() { cout << "streaming player stops" << endl; }
    void toString() { cout << "streaming player" << endl; }
};

class Amplifier
{
public:
    Tuner* tuner;
    StreamingPlayer* player;

    void on() { cout << "amplifier on" << endl; }
    void off() { cout << "amplifier off" << endl; }
    void setStreamingPlayer(StreamingPlayer* player) { this->player = player; cout << "amplifier set streaming player" << endl; }
    void setStereoSound() { cout << "amplifier set stereo sound" << endl; }
    void setSurroundSound() { cout << "amplifier set surround sound" << endl; }
    void setTuner(Tuner* tuner) { this->tuner = tuner; cout << "amplifier set tuner" << endl; }
    void setVolume(int v) { cout << "amplifier set volume " << v << endl; }
    void toString() { cout << "amplifier" << endl; }
};

class Tuner
{
public:
    Amplifier* amplifier;

    void on() { cout << "tuner on" << endl; }
    void off() { cout << "tuner off" << endl; }
    void setAm() { cout << "tuner set am" << endl; }
    void setFm() { cout << "tuner set fm" << endl; }
    void setFrequency(int f) { cout << "tuner set frequency " << f << endl; }
    void toString() { cout << "tuner" << endl; }
};

class HomeTheaterFacade
{
public:
    Amplifier* amplifier;
    Tuner* tuner;
    StreamingPlayer* player;
    Projector* projector;
    TheaterLights* lights;
    Screen* screen;
    PopcornPopper* popper;

    HomeTheaterFacade()
    {
        this->amplifier = new Amplifier;
        this->tuner = new Tuner;
        this->player = new StreamingPlayer;
        this->projector = new Projector;
        this->lights = new TheaterLights;
        this->screen = new Screen;
        this->popper = new PopcornPopper;
    }

    HomeTheaterFacade(Amplifier* amplifier,
                      Tuner* tuner,
                      StreamingPlayer* player,
                      Projector* projector,
                      TheaterLights* lights,
                      Screen* screen,
                      PopcornPopper* popper)
    {
        this->amplifier = amplifier;
        this->tuner = tuner;
        this->player = player;
        this->projector = projector;
        this->lights = lights;
        this->screen = screen;
        this->popper = popper;
    }

    ~HomeTheaterFacade()
    {
        delete this->amplifier;
        delete this->tuner;
        delete this->player;
        delete this->projector;
        delete this->lights;
        delete this->screen;
        delete this->popper;

        this->amplifier = nullptr;
        this->tuner     = nullptr;
        this->player    = nullptr;
        this->projector = nullptr;
        this->lights    = nullptr;
        this->screen    = nullptr;
        this->popper    = nullptr;
    }

    void watchMovie(string movie)
    {
        cout << "get ready to watch a movie..." << endl;
        popper->on();
        popper->pop();
        lights->dim(10);
        screen->down();
        projector->on();
        projector->wideScreenMode();
        amplifier->on();
        amplifier->setStreamingPlayer(this->player);
        amplifier->setSurroundSound();
        amplifier->setVolume(5);
        player->on();
        player->play(movie);
        cout << endl;
    }

    void endMovie()
    {
        cout << "shutting movie theater down" << endl;
        popper->off();
        lights->on();
        screen->up();
        projector->off();
        amplifier->off();
        player->stop();
        player->off();
        cout << endl;
    }
};

void test()
{
    HomeTheaterFacade* theater = new HomeTheaterFacade();
    theater->watchMovie("Tom and Jerry");
    theater->endMovie();

    delete theater;
}

int main()
{
    test();

    return 0;
}
