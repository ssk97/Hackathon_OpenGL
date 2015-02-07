#include <cstdlib>
#include <math.h>
#include "LineTripper.h"

LineTripper::LineTripper()
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

LineTripper::LineTripper(double xin, double yin)
{
    x = xin;
    y = yin;
}

LineTripper::~LineTripper()
{
}

const double LINETRIPPER_SPEED = 3.5;
void LineTripper::update()
{
	GenericObject* player = ThePlayer;

	double delta_y = (player->y) - y;
	double delta_x = (player->x) - x;
    angle = atan2(delta_y, delta_x);

	x += LINETRIPPER_SPEED * cos(angle);
	y += LINETRIPPER_SPEED * sin(angle);
	angle = angle * 180 / PI;//convert to degrees

	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void LineTripper::collideWithPlayer()
{

}

void LineTripper::collideWithFollower()
{}
