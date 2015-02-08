#include <math.h>
#include "Follower.h"

Follower::Follower(){}

Follower::~Follower(){}

const double SPRING_CONSTANT_SLOW = 0.01;
const double FRICTION = .99;
const double EXTRA_FRICTION = .90;
const double SPRING_LENGTH = 100;
void Follower::update()
{
	GenericObject* player = ThePlayer;
    int leftButtonDown = glfwGetMouseButton(window, 0);
    int rightButtonDown = glfwGetMouseButton(window, 1);

	double delta_y = (player->y) - y;
	double delta_x = (player->x) - x;

    double springConstant = leftButtonDown ? SPRING_CONSTANT_SLOW * 5 : SPRING_CONSTANT_SLOW;

    double angleToTarget = atan2(delta_y, delta_x);
	double equilibrium_y = SPRING_LENGTH * -sin(angleToTarget) + (player->y);
	double equilibrium_x = SPRING_LENGTH * -cos(angleToTarget) + (player->x);

    yAcc = springConstant * (equilibrium_y - y);
    xAcc = springConstant * (equilibrium_x - x);

    if (!leftButtonDown)
    {
        xVel *= FRICTION;
        yVel *= FRICTION;
        if (rightButtonDown)
        {
            xVel *= EXTRA_FRICTION;
            yVel *= EXTRA_FRICTION;
        }
    }
    xVel += xAcc;
    yVel += yAcc;

    x += xVel;
    y += yVel;

	angle += 1;
}
