#include <math.h>
#include "Follower.h"

Follower::Follower(){}

Follower::~Follower(){}

const double SPRING_CONSTANT_SLOW = 0.005;
const double FRICTION = .985;
const double SPRING_LENGTH = 25;
void Follower::update()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    int buttonDown = glfwGetMouseButton(window, 0);

    double delta_y = mouseY - y;
    double delta_x = mouseX - x;

    double springConstant = buttonDown ? SPRING_CONSTANT_SLOW * 2 : SPRING_CONSTANT_SLOW;

    double angleToTarget = atan2(delta_y, delta_x);
    double equilibrium_y = SPRING_LENGTH * sin(angleToTarget) + mouseY;
    double equilibrium_x = SPRING_LENGTH * cos(angleToTarget) + mouseX;

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

void Follower::draw()
{
	glDrawArrays(GL_TRIANGLE_FAN, 0, 182);
}
