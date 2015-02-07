#include "GenericHolder.h"

class ZombieHolder : public GenericHolder
{
public:
    ZombieHolder();
    ~ZombieHolder();
    void potentiallyAddZombie();
    void draw(GenericObject *obj);
    void removeZombie();
};
