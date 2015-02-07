#include "Follower.h"

const double SPRING_CONSTANT = .001;
void Follower::update()
{
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
