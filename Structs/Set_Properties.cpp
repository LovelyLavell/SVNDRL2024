#include "Set_Properties.h"
Set_Properties::Set_Properties(){
}
Set_Properties::Set_Properties(Vec3 Size, Vec3 Location){
    this->Size = Size;
    this->Location = Location;
}

Set_Properties::Set_Properties(Vec3 Size, Vec3 Location, Vec3 Rotation){

    this->Size = Size;
    this->Location = Location;
    this->Rotation = Rotation;
}
