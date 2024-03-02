#ifndef IOSECTION_H_INCLUDED
#define IOSECTION_H_INCLUDED
#include <string.h>
#include "../Superfluous/TList.h"
struct IOSection{
    std::string Label;
    struct IOPortion{
        std::string key;
        std::string value;
    };
    //I Want to use my own linked list for this particular example
    TList<IOPortion> * PortionList;
};

#endif // IOSECTION_H_INCLUDED
