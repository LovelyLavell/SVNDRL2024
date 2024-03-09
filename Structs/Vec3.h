#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED
//Because this is color and location I just used a more generic application. If need be it can be converted to something else
struct Vec3
{
    float a;
    float b;
    float c;
    float w;
    Vec3();
    Vec3(float a, float b, float c = 0, float w = 0);
};

#endif // VEC3_H_INCLUDED
