#include "Spawner.h"


Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::tick()
{
	time++;
	if (time % 240 == 0){
		wave++;
		for (int i = 0; i < wave; i++){
			((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
		}
	}
}



