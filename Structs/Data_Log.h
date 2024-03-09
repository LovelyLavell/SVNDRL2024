#ifndef DATA_LOG_H_INCLUDED
#define DATA_LOG_H_INCLUDED
#include "Data_Message.h"
struct Data_Log
{
    Data_Message message;
    time_t TimeStamp;
}

#endif // DATA_LOG_H_INCLUDED
