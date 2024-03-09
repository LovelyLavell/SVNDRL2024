#include "TRect.h"
TRect::TRect(){
}
TRect::TRect(Set_Properties properties){
    this->properties = properties;
}
TRect::TRect(Vec3 location){
    properties = Set_Properties(Vec3(1,1),location);
}
TRect::TRect(Vec3 location, Vec3 scale){
    properties = Set_Properties(scale, location);
}
TRect::TRect(Vec3 location, Vec3 scale, Vec3 rotation){
    properties = Set_Properties(scale, location, rotation);
}
