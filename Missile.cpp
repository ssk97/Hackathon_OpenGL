#include <cstdlib>
#include <math.h>
#include "Missile.h"

Missile::Missile()
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
    angle = 0;
}

Missile::Missile(double xin, double yin, double angle)
{
    x = xin;
    y = yin;
    this->angle = angle;
}

Missile::~Missile()
{
}

const double Missile_SPEED = 6.0;
void Missile::update()
{
    x += Missile_SPEED * Dcos(angle);
    y += Missile_SPEED * Dsin(angle);

    if (x > width || x < 0 || y > height || y < 0)
        markedForDeath = true;

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Missile::collideWithPlayer()
{

}

void Missile::collideWithFollower()
{}
