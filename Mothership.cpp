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
    angle = fmod(rand(), 2 * PI);

	updateOldPos();
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

    double plusOrMinusPi = fmod(rand(), 2 * PI) - PI;
    if (x > width)
    {
        angle = PI + plusOrMinusPi;
    }
    else if (x < 0)
    {
        angle = 0 + plusOrMinusPi;
    }
    else if (y > height)
    {
        angle = PI / 2 + plusOrMinusPi;
    }
    else if (y < 0)
    {
        y = 0;
        angle = fmod(rand(), 2 * PI);
    }

    y += MOTHERSHIP_SPEED * sin(angle);
    x += MOTHERSHIP_SPEED * cos(angle);

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Mothership::collideWithPlayer()
{

}

void Mothership::collideWithFollower()
{}
