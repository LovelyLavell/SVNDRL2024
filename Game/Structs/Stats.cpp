#include "Stats.h"
EntityStats::EntityStats(int level, EntityStatGain gain){
    str = 1 + (gain.str * level);
    fin = 1 + (gain.fin * level);
    con = 1 + (gain.con * level);
    mag = 1 + (gain.mag * level);
    tec = 1 + (gain.tec * level);
}

EntityStatGain::EntityStatGain(float uniformScale){
    str = uniformScale;
    fin = uniformScale;
    con = uniformScale;
    mag = uniformScale;
    tec = uniformScale;
}
