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

	aimX = rand() % width;
	aimY = rand() % height;
	speed = 0;
}

LineTripper::LineTripper(double xin, double yin)
{
    x = xin;
    y = yin;

	aimX = rand() % width;
	aimY = rand() % height;
	speed = 0;
}

LineTripper::~LineTripper()
{
}

const double LINETRIPPER_SPEED = 10;
void LineTripper::update()
{
	//bounce
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


	if (speed < 0.4){
		if (aimX == targetX && aimY == targetX){
			if (rand() % 2 == 1){
				aimX = ThePlayer->x;
				aimY = ThePlayer->y;
			} else {
				aimX = rand() % width;
				aimY = rand() % height;
			}
		}
		double delta_y = aimX - y;
		double delta_x = aimY - x;
		angle = atan2(delta_y, delta_x);
		angle = angle * 180 / PI;//convert to degrees
		if (speed < 0.2){
			moveAngle = angle;
			speed = LINETRIPPER_SPEED;
			targetX = aimX;
			targetY = aimY;
		}
	}
	else {
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
