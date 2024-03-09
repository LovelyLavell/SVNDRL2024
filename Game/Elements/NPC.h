#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include "../Entity.h"
class NPC : public Entity{
public:
    NPC(int id, Vec3 location);
    void Move() override;
};

#endif // NPC_H_INCLUDED
