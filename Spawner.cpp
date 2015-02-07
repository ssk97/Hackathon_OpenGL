#include "Spawner.h"


Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::tick()
{
	if (time++ % 240 == 0){
		wave++;
		int remainingCount = wave;
		if (wave >= 3){
			int motherShipCount = (rand() % (wave / 2));
			for (int i = 0; i < motherShipCount; i++)
			{
				((MothershipHolder*)(holderArray[MOTHERSHIP]))->addMothership();
			}
			remainingCount -= motherShipCount * 2;
		}
		for (int i = 0; i < remainingCount; i++){
			((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
		}
	}
}



