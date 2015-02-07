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
		#ifndef NO_ZOMBIES
		for (int i = 0; i < wave; i++){
			((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
		}
		#endif // NO_ZOMBIES
		for (int i = 0; i < wave / 5 ; i++)
		{
            ((MothershipHolder*)(holderArray[MOTHERSHIP]))->addMothership();
		}
	}
}



