#pragma once
#include "GenericHolder.h"
#include "Player.h"
class PlayerHolder: public GenericHolder
{
public:
	PlayerHolder();
	~PlayerHolder();
	GLuint setupFragmentShader();
};

