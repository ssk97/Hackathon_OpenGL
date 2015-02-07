#include <cstdlib>
#include "ZombieHolder.h"
#include "Zombie.h"


ZombieHolder::ZombieHolder()
{
}

ZombieHolder::~ZombieHolder()
{
}

void ZombieHolder::potentiallyAddZombie()
{
    if (rand() % 50 == 0)
    {
        addObj(new Zombie());
    }
}

void ZombieHolder::draw(GenericObject *obj)
{
    glDrawArrays(GL_TRIANGLES, 0, 9);
}

void ZombieHolder::removeZombie()
{
}
