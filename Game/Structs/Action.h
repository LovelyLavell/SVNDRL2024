#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED
#include <string>
struct Action{
    std::string Message;
    //Interpret info
    int type; //Broad type, attack, heal, status
    int mod; //Any more granular depth I might want to add, like what kind of status.
    //Result
    int value;
};

#endif // ACTION_H_INCLUDED
