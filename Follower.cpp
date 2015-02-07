#include "Follower.h"
#include "openGL_stuff.h"

const double SPRING_CONSTANT = .001;
void Follower::update()
{
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
