#pragma once
//#include "GenericHolder.h"
#include "badDesign.h"
class GenericHolder;
class GenericObject
{
public:
	GenericObject();
	~GenericObject();
	double x=50, y=50, angle=0;
	GenericHolder *parent;
	virtual void update() = 0;
	virtual void draw() = 0;
	void transform(GLuint shaderProgram);
};

