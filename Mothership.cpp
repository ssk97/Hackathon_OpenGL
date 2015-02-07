#include <cstdlib>
#include <math.h>
#include "Zombie.h"
#include "Mothership.h"
#include "GenericHolder.h"

Mothership::Mothership()
{
    switch (rand() % 4)
    {
    case 0:
        y = 0;
        x = rand() % width;
        break;
    case 1:
        y = height;
        x = rand() % width;
        break;
    case 2:
        y = rand() % height;
        x = 0;
        break;
    case 3:
        y = rand() % height;
        x = width;
        break;
    }
	updateOldPos();
}

Mothership::~Mothership()
{
}

const double MOTHERSHIP_SPEED = 0.9;
void Mothership::update()
{
    if (framesAlive > 500)
    {
        markedForDeath = true;

        holderArray[ZOMBIE]->addObj(new Zombie(x,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x + 20,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x - 20,y));
        holderArray[ZOMBIE]->addObj(new Zombie(x,y + 20));
        holderArray[ZOMBIE]->addObj(new Zombie(x,y - 20));
    }



	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Mothership::collideWithPlayer()
{

}

void Mothership::collideWithFollower()
{}
