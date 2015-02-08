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
    targetX = rand() % width;
    targetY = rand() % height;
	speed = 0;
}

LineTripper::LineTripper(double xin, double yin)
{
    x = xin;
    y = yin;

    goalX = rand() % width;
	goalY = rand() % height;
	speed = 0;
}

LineTripper::~LineTripper()
{
}

const double LINETRIPPER_SPEED = 6;
void LineTripper::update()
{
	//bounce
	if (speed < 0.5){
		double delta_y = goalY - y;
		double delta_x = goalX - x;
		angle = atan2(delta_y, delta_x);
		angle = angle * 180 / PI;//convert to degrees
		if (speed < 0.2){
			moveAngle = angle;
			speed = LINETRIPPER_SPEED;
		}
	}
	else {
		double randomAngle = ((double)rand() / RAND_MAX) * 180 - 90;
		if (x > width)
		{
			moveAngle = 180 + randomAngle;
		}
		else if (x < 0)
		{
			moveAngle = 0 + randomAngle;
		}
		else if (y > height)
		{
			moveAngle = 270 + randomAngle;
		}
		else if (y < 0)
		{
			moveAngle = 90 + randomAngle;
		}

		angle = moveAngle;
	}
	speed *= .98;
	y += speed * Dsin(moveAngle);
	x += speed * Dcos(moveAngle);
	possibleCollideWithFollower();
	possibleCollideWithPlayer();
}

void LineTripper::collideWithPlayer()
{

}

void LineTripper::collideWithFollower()
{}
