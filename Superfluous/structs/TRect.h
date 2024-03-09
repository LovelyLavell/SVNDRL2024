#ifndef TRECT_H_INCLUDED
#define TRECT_H_INCLUDED
#include "../../Structs/Set_Properties.h"
/*
 * This is also uneeded but I have gotten used to doing this and if I need to add functions
 * I can just cahange this to a class later. Additionally, there can be a property for original and scaled
 */
struct TRect{
    Set_Properties properties;
    TRect();
    TRect(Set_Properties properties);
    TRect(Vec3 location);
    TRect(Vec3 location, Vec3 scale);
    TRect(Vec3 location, Vec3 scale, Vec3 rotation);
};


#endif // TRECT_H_INCLUDED
