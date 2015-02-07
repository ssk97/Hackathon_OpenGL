#pragma once
#include "GenericObject.h"

class Player: public GenericObject
{
public:
	Player();
	~Player();
	void update();
	void draw(GLuint shaderProgram);
};

