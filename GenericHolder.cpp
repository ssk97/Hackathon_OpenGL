#include "GenericHolder.h"


GenericHolder::GenericHolder()
{
	std::vector<GenericObject> objs();
}


GenericHolder::~GenericHolder()
{
}


void GenericHolder::updateAll()
{
	for (std::vector<int>::iterator it = objs.begin(); it != objs.end(); ++it)
		(*it).update();
}