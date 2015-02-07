#include <cstdlib>
#include <math.h>
#include "Zombie.h"
#include "Mothership.h"
#include "GenericHolder.h"

Mothership::Mothership()
{
}

Mothership::~Mothership()
{
}

const double MOTHERSHIP_SPEED = 2;
void Mothership::update()
{
    framesAlive++;
    if (framesAlive > 500)
    {
        markedForDeath = true;

        holderArray[ZOMBIE]->addObj(new Zombie(x,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x + 20,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x - 20,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x,y + 20));
        holderArray[ZOMBIE]->addObj(new Zombie(x,y - 20));
    }

	double randomAngle = ((double)rand() / RAND_MAX)*180-90;
    if (x > width)
    {
		angle = 180 + randomAngle;
    }
    else if (x < 0)
    {
		angle = 0 + randomAngle;
    }
    else if (y > height)
    {
		angle = 270 + randomAngle;
    }
    else if (y < 0)
    {
		angle = 90 + randomAngle;
    }

    y += MOTHERSHIP_SPEED * Dsin(angle);
    x += MOTHERSHIP_SPEED * Dcos(angle);

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Mothership::collideWithPlayer()
{

}

void Mothership::collideWithFollower()
{}
