#include <cstdlib>
#include <math.h>
#include "Carrier.h"
#include "MissileHolder.h"

Carrier::Carrier()
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
}

Carrier::Carrier(double xin, double yin)
{
    x = xin;
    y = yin;
}

Carrier::~Carrier()
{
}

const double CARRIER_SPEED = 1.5;
const int FRAMES_PER_Missile = 60;
void Carrier::update()
{
    numFramesSinceMissile++;

    if (numFramesSinceMissile > FRAMES_PER_Missile)
    {
        numFramesSinceMissile = 0;
        GenericObject* player = ThePlayer;

        double y_to_player= (player->y) - y;
        double x_to_player = (player->x) - x;
        double angle_to_player = atan2(y_to_player, x_to_player);

        ((MissileHolder*)(holderArray[Missile]))->AddMissile(x, y, angle_to_player);
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

    y += CARRIER_SPEED * Dsin(angle);
    x += CARRIER_SPEED * Dcos(angle);

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void Carrier::collideWithPlayer()
{

}

void Carrier::collideWithFollower()
{}
