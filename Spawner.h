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
	unsigned long long time = 0; //Want to reach the maximum?  You have a long, long time before that happens.
	enum Mode {NO_MODE, Normal, CTRush, Zombie};
    Mode mode = NO_MODE;
private:
    void wave_normal();
    void wave_CTRush();
    void wave_zombie();
};

