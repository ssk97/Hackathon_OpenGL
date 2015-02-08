#include "Spawner.h"


Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::tick()
{
	if (time++ % 250 == 0){
		wave++;
        for (int i = 0; i < wave; i++)
        {
            ((LineTripperHolder*)(holderArray[LINETRIPPER]))->AddLineTripper();
            ((CarrierHolder*)(holderArray[CARRIER]))->AddCarrier();
        }/*
		int remainingCount = wave;

		if (wave >= 3){
			int motherShipCount = (rand() % (remainingCount / 2));
			for (int i = 0; i < motherShipCount; i++)
			{
				((MothershipHolder*)(holderArray[MOTHERSHIP]))->addMothership();
			}
			remainingCount -= motherShipCount * 2;

			if (remainingCount > 0)
			{
                int lineTripperCount = (rand() % remainingCount / 3);
                for (int i = 0; i < lineTripperCount; i++)
                {
                    ((LineTripperHolder*)(holderArray[LINETRIPPER]))->AddLineTripper();
                }
                remainingCount -= lineTripperCount;
			}

			if (remainingCount > 0)
			{
                int carrierCount = (rand() % remainingCount / 3);
                for (int i = 0; i < carrierCount; i++)
                {
                    ((CarrierHolder*)(holderArray[CARRIER]))->AddCarrier();
                }
                remainingCount -= carrierCount * 2;
			}

		}
		for (int i = 0; i < remainingCount; i++){
			((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
		}*/
	}
}



