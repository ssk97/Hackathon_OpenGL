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
	double oldx, oldy, oldangle;
	bool markedForDeath = false;
	GenericHolder *parent;
	virtual void update() = 0;
	void updateOldPos();
	double distMoved();
	void transform(GLuint shaderProgram, double t);
};

