#pragma once
#include "GenericHolder.h"

class LineTripperHolder : public GenericHolder
{
public:
	LineTripperHolder();
	~LineTripperHolder();
	void AddLineTripper();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);
};
