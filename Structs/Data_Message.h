#ifndef DATA_MESSAGE_H_INCLUDED
#define DATA_MESSAGE_H_INCLUDED
#include "Vec3.h"
#include <string>
struct Data_Message{
    //This is the name of the person that sent the message, may not be unique.
    std::string sender;
    std::string message;
    int senderID;
    Data_Message(){};
    Data_Message(std::string sender, std::string message, int senderID){
        this->sender = sender;
        this->message = message;
        this->senderID = senderID;
    }
};

#endif // DATA_MESSAGE_H_INCLUDED
