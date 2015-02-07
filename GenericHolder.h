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
	virtual void loadDraw() = 0;
	virtual void unloadDraw() = 0;
private:
	std::vector<GenericObject> objs;
};

