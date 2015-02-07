#include <cstdlib>
#include <math.h>
#include "Zombie.h"

Zombie::Zombie()
{
    static int next_ID;
    id = next_ID;
    next_ID++;

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

Zombie::~Zombie()
{
}

void Zombie::update()
{
	GenericObject* player = ThePlayer;

	double delta_y = (player->y) - y;
	double delta_x = (player->x) - x;
    angle = atan2(delta_y, delta_x);

    x += 4 * cos(angle);
    y += 4 * sin(angle);
	angle = angle * 180 / PI;//convert to degrees

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Zombie::collideWithPlayer()
{

}

void Zombie::collideWithFollower()
{}
