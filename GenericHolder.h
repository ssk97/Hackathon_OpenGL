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
	virtual void draw() = 0;//draws one copy of the object with currently setup transitions
	void drawOne(double x, double y);//draws once
	void addObj(GenericObject *obj);
	virtual GLuint setupDrawing();
	virtual GLuint setupVertexShader();
	virtual GLuint setupFragmentShader();
	virtual GLuint setupGeometry();
	std::vector<GenericObject *> objs;
	GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;
};

