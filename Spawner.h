#pragma once
#include "GenericObject.h"
#include "ZombieHolder.h"
#include "MothershipHolder.h"
#include "LineTripperHolder.h"
#include "CarrierHolder.h"

class Spawner
{
public:
	Spawner();
	~Spawner();
	void tick();
	int wave = 0;
	unsigned long long time = 0;
};

