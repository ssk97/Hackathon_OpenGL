#pragma once
//#include "GenericHolder.h"
#include "badDesign.h"
class GenericObject
{
public:
	GenericObject();
	~GenericObject();
	double x, y;
	//GenericHolder &Parent;
	virtual void update() = 0;
	virtual void draw(GLuint shaderProgram) = 0;
};

