#pragma once
#include "GenericObject.h"
#include "ZombieHolder.h"

class Spawner
{
public:
	Spawner();
	~Spawner();
	void tick();
	int wave = 0;
	int time = 0;
};

