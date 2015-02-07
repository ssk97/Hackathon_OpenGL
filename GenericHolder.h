#pragma once
#include <vector>
#include "GenericObject.h"
class GenericHolder
{
public:
	GenericHolder();
	~GenericHolder();
	void updateAll();
	void drawAll();
	virtual GLuint setupDrawing();
	virtual GLuint setupVertexShader();
	virtual GLuint setupFragmentShader();
	GLuint vbo, vao, shaderProgram, fragmentShader, vertexShader;
	//virtual void loadDraw() = 0;
	//virtual void unloadDraw() = 0;
	std::vector<GenericObject *> objs;
};

