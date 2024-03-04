#include "Timer.h"
Timer :: Timer() // timer initialization
{
    Start_Ticks = time(0);

    Paused_Ticks = time(0);

    Paused = false;

    Started = false;
}
void Timer :: Wait(int Ms)
{
    Start();

    do {}
    while(GetTicks() <= Ms);

    Stop();
}

void Timer :: Start() // timer start funtion
{
    Started = true;

    Paused = false;

    Start_Ticks = time(0);
}
void Timer :: Stop() // timer stop function
{
    Started = false;

    Paused = false;
}
void Timer :: Pause() // function for pausing
{
    if ((Started == true) && (Paused == false))
    {
        Paused = true;

        Paused_Ticks = time(0) - Start_Ticks;
    }
}
void Timer :: Unpause() // function for unpausing
{
    if (Paused == true)
    {
        Paused = false;

        Start_Ticks = time(0) - Paused_Ticks;

        Paused_Ticks = 0;
    }
}
int Timer :: GetTicks() // function for getting the time
{
    if(Started == true)
    {
        if(Paused== true ) return Paused_Ticks;

        else return time(0) - Start_Ticks;
    }
    return 0;
}
bool Timer :: IsStarted() //checking
{
    return Started;
}
bool Timer :: IsPaused() //checking
{
    return Paused;
}
