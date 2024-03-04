#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
//For the event log, nothing more, could be a tuple honestly but I added timestamps and
//a function
struct Event{
    std::string Message;
    std::string Timestamp;
};

#endif // EVENT_H_INCLUDED
