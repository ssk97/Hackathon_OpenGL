#pragma once
//#include "GenericHolder.h"
#include "badDesign.h"
class GenericHolder;
class GenericObject
{
public:
	GenericObject();
	virtual ~GenericObject();
	double x=50, y=50, angle=0;
	double oldx, oldy, oldangle;
	bool markedForDeath = false;
	GenericHolder *parent;
	virtual void update() = 0;
	void updateOldPos();
	double distMoved();
	glm::mat4 translateOld();
	glm::mat4 translate();
	glm::mat4 rotation();
};