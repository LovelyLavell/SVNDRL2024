#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <ctime>

class Timer{
private:
    bool Paused;
    bool Started;

    time_t Start_Ticks;
    time_t Paused_Ticks;
public:
    Timer();

    bool IsStarted();
    bool IsPaused();

    int GetTicks();

    void Start();
    void Stop();
    void Pause();
    void Unpause();
    void Wait(int Ms);
};

#endif // TIMER_H_INCLUDED
