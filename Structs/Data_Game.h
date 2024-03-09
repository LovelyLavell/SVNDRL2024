#ifndef DATA_GAME_H_INCLUDED
#define DATA_GAME_H_INCLUDED
#include <string>
//All of this should be fethched from a file.
struct Data_Game{
    static const int DefaultWidth = 640;
    static const int DefaultHeight = 480;
    int WindowWidth;
    int WindowHeight;
    //The game is built aroun being 640x480, any other size the game must scale to.
    float ScaleWidth;
    float ScaleHeight;
    std::string title;
};
#endif // DATA_GAME_H_INCLUDED
