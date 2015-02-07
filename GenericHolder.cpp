#include "GenericHolder.h"


GenericHolder::GenericHolder()
{
}


GenericHolder::~GenericHolder()
{
}


void GenericHolder::updateAll()
{
	for (std::vector<GenericObject>::iterator it = objs.begin(); it != objs.end(); ++it)
		(*it).update();
}
void GenericHolder::drawAll()
{
	for (std::vector<GenericObject>::iterator it = objs.begin(); it != objs.end(); ++it)
		(*it).draw(shaderProgram);
}