#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
	angle += 4;
	if (angle > 360) angle -= 360;
	glfwGetCursorPos(window, &x, &y);
}