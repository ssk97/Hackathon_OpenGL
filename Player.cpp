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

void Player::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}