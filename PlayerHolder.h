#pragma once
#include "GenericHolder.h"
#include "Player.h"
class PlayerHolder: public GenericHolder
{
public:
	PlayerHolder();
	~PlayerHolder();
	std::vector<Player> objs;
	GLuint vertexShader, fragmentShader, shaderProgram, posAttrib, uniTrans, vbo, vao;
};

