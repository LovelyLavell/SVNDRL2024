#include "TMath.h"
Vec3 TMath::Add(Vec3 a, Vec3 b){
    Vec3 returnVal(
        a.a + b.a,
        a.b + b.b,
        a.c + b.c
    );
    return returnVal;
}

Vec3 TMath::Add(Vec3 a, float b){
    Vec3 returnVal(
        a.a + b,
        a.b + b,
        a.c + b
    );
    return returnVal;

}

Vec3 TMath::Subtract(Vec3 a, Vec3 b){
    Vec3 returnVal(
        a.a - b.a,
        a.b - b.b,
        a.c - b.c
    );
    return returnVal;

}

Vec3 TMath::Subtract(Vec3 a, float b){
    Vec3 returnVal(
        a.a - b,
        a.b - b,
        a.c - b
    );
    return returnVal;

}

Vec3 TMath::Multiply(Vec3 a, Vec3 b){
    Vec3 returnVal(
        a.a * b.a,
        a.b * b.b,
        a.c * b.c
    );
    return returnVal;

}

Vec3 TMath::Multiply(Vec3 a, float b){
    Vec3 returnVal(
        a.a * b,
        a.b * b,
        a.c * b
    );
    return returnVal;

}

Vec3 TMath::Divide(Vec3 a, Vec3 b){
    Vec3 returnVal(
        a.a / b.a,
        a.b / b.b,
        a.c / b.c
    );
    return returnVal;

}

Vec3 TMath::Divide(Vec3 a, float b){
    Vec3 returnVal(
        a.a / b,
        a.b / b,
        a.c / b
    );
    return returnVal;

}

bool TMath::Equals(Vec3 a, Vec3 b){
    return a.a == b.a && a.b == b.b && a.c == b.c;

}
