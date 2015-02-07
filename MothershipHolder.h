#pragma once
#include "GenericHolder.h"

class MothershipHolder : public GenericHolder
{
public:
    MothershipHolder();
    ~MothershipHolder();
	void addMothership();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);

};
