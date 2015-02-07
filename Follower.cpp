#include <math.h>
#include "Follower.h"

Follower::Follower(){}

Follower::~Follower(){}

const double SPRING_CONSTANT_SLOW = 0.01;
const double FRICTION = .99;
const double SPRING_LENGTH = 100;
void Follower::update()
{
	GenericObject* player = ThePlayer;
    int buttonDown = glfwGetMouseButton(window, 0);

	double delta_y = (player->y) - y;
	double delta_x = (player->x) - x;

    double springConstant = buttonDown ? SPRING_CONSTANT_SLOW * 5 : SPRING_CONSTANT_SLOW;

    double angleToTarget = atan2(delta_y, delta_x);
	double equilibrium_y = SPRING_LENGTH * -sin(angleToTarget) + (player->y);
	double equilibrium_x = SPRING_LENGTH * -cos(angleToTarget) + (player->x);

    yAcc = springConstant * (equilibrium_y - y);
    xAcc = springConstant * (equilibrium_x - x);

    if (!buttonDown)
    {
        xVel *= FRICTION;
        yVel *= FRICTION;
    }
    xVel += xAcc;
    yVel += yAcc;

    x += xVel;
    y += yVel;

	angle += 1;
}
