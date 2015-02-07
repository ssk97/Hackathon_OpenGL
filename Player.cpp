#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
	glfwGetCursorPos(window, &x, &y);
}