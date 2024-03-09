#ifndef TMATH_H_INCLUDED
#define TMATH_H_INCLUDED
#include "../Structs/Vec3.h"
/*
* I am aware of operator overloads but outside of a constructor I don't like to
* add functions to structs. This is one of those things I am stubborn about.
* At this point I refuse to make any of my structs classes
*/
class TMath{
public:
    //Vector math
    static Vec3 Add(Vec3 a, Vec3 b);
    static Vec3 Add(Vec3 a, float b);

    static Vec3 Subtract(Vec3 a, Vec3 b);
    static Vec3 Subtract(Vec3 a, float b);

    static Vec3 Multiply(Vec3 a, Vec3 b);
    static Vec3 Multiply(Vec3 a, float b);

    static Vec3 Divide(Vec3 a, Vec3 b);
    static Vec3 Divide(Vec3 a, float b);

    static bool Equals(Vec3 a, Vec3 b);
};

#endif // TMATH_H_INCLUDED
