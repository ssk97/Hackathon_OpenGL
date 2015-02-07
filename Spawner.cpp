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
		for (int i = 0; i < wave; i++){
			((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
		}
		for (int i = 0; i < wave / 5; i++)
		{
            ((MothershipHolder*)(holderArray[MOTHERSHIP]))->addMothership();
		}
	}
}



