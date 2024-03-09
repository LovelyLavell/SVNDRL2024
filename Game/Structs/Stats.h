#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED
struct EntityStatGain{
    //Strength
    float str;
    //Basically dex
    float fin;
    //Resistances
    float con;
    //Essentioism
    float mag;
    //Organitrism
    float tec;

    EntityStatGain(float uniformScale);

};
struct EntityStats{
    //Strength
    int str;
    //Basically dex
    int fin;
    //Resistances
    int con;
    //Essentioism
    int mag;
    //Organitrism
    int tec;
    EntityStats(int level, EntityStatGain gain);
};
struct SpecialStats{
    //How you are percieved, influenced by what you wear
    int cha;
    //Chance of getting lucky, influenced by random stuff like objects in your inventory
    int luck;
};
#endif // STATS_H_INCLUDED
