#include <cstdlib>
#include <math.h>
#include "Zombie.h"

Zombie::Zombie()
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

Zombie::Zombie(double xin, double yin)
{
    x = xin;
    y = yin;
}

Zombie::~Zombie()
{
}

const double ZOMBIE_SPEED = 3.5;
void Zombie::update()
{
	GenericObject* player = ThePlayer;

	double delta_y = (player->y) - y;
	double delta_x = (player->x) - x;
    angle = atan2(delta_y, delta_x);

    x += ZOMBIE_SPEED * cos(angle);
    y += ZOMBIE_SPEED * sin(angle);
	angle = angle * 180 / PI;//convert to degrees

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Zombie::collideWithPlayer()
{

}

void Zombie::collideWithFollower()
{}
