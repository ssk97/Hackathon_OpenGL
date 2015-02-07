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

    goalX = rand() % width;
    goalY = rand() % height;
}

LineTripper::LineTripper(double xin, double yin)
{
    x = xin;
    y = yin;

    goalX = rand() % width;
    goalY = rand() % height;
}

LineTripper::~LineTripper()
{
}

const double LINETRIPPER_SPEED = 4.5;
void LineTripper::update()
{
	double delta_y = goalY - y;
	double delta_x = goalX - x;
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
