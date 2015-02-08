#pragma once
#include "GenericHolder.h"

class MissileHolder : public GenericHolder
{
public:
    MissileHolder();
    ~MissileHolder();
	void AddMissile();
	void AddMissile(double x, double y, double angle);
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);
};
