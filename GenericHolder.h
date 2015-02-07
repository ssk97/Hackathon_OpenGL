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
	virtual void draw(GenericObject *obj) = 0;//draws one object based on the object's transformations
	void addObj(GenericObject *obj);
	virtual GLuint setupDrawing();
	virtual GLuint setupVertexShader();
	virtual GLuint setupFragmentShader();
	virtual GLuint setupGeometry();
	//virtual void loadDraw() = 0;
	//virtual void unloadDraw() = 0;
	std::vector<GenericObject *> objs;
	GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;
};

