#pragma once
class GenericObject
{
public:
	GenericObject();
	~GenericObject();
	double x, y;
	virtual void update() = 0;
	virtual void draw() = 0;
};

