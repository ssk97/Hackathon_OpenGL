#pragma once
#include <vector>
#include "GenericObject.h"
class GenericHolder
{
protected:
    void setupGlForRedTriangle();
    GLuint vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;
public:
	GenericHolder();
	~GenericHolder();
	void updateAll();
	void drawAll();
	//virtual void loadDraw() = 0;
	//virtual void unloadDraw() = 0;
	std::vector<GenericObject *> objs;
	GLuint shaderProgram;
};

