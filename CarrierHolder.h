#pragma once
#include "GenericHolder.h"

class CarrierHolder : public GenericHolder
{
public:
    CarrierHolder();
    ~CarrierHolder();
	void AddCarrier();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw();
};
