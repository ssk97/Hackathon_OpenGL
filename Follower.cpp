#include "Follower.h"
#include "badDesign.h"

const double SPRING_CONSTANT = .001;
void Follower::update()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    xAcc = mouseX - x;
    yAcc = mouseY - y;

    xVel += xAcc;
    yVel += yAcc;

    x += xVel;
    y += yVel;
}

void Follower::draw()
{
    //Lol.
}
