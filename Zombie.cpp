#include <cstdlib>
#include <math.h>
#include "Zombie.h"

Zombie::Zombie()
{
    static int next_ID;
    id = next_ID;
    next_ID++;

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
	updateOldPos();
}

Zombie::~Zombie()
{
}

const int ZOMBIE_SPEED = 2;
void Zombie::update()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    double delta_y = mouseY - y;
    double delta_x = mouseX - x;
    angle = atan2(delta_y, delta_x);

    x += ZOMBIE_SPEED * cos(angle);
    y += ZOMBIE_SPEED * sin(angle);
	angle = angle * 180 / PI;//convert to degrees

	possibleCollideWithFollower();
}

void Zombie::collideWithPlayer()
{

}

void Zombie::collideWithFollower()
{}
