#include "Spawner.h"


Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::tick()
{
	if (mode == NO_MODE)
	{
		if (glfwGetKey(window, GLFW_KEY_N)) mode = Normal;
		if (glfwGetKey(window, GLFW_KEY_R)) mode = CTRush;
		if (glfwGetKey(window, GLFW_KEY_Z)) mode = Zombie;
	}
	else if (time++ % 250 == 0){
		wave++;
		switch (mode)
		{
		case Normal:
			wave_normal();
            break;
		case CTRush:
			wave_CTRush();
			break;
        case Zombie:
            wave_zombie();
            break;
		default:
			break;

		}
	}
}

void Spawner::wave_normal()
{
	int remainingCount = wave;

	if (wave % 10 == 0) //BOSS WAVE!
	{
		for (int i = 0; i < wave / 2; i++) //EAT CARRIERS!
		{
			((CarrierHolder*)(holderArray[CARRIER]))->AddCarrier();
		}
		for (int i = 0; i < wave / 2; i++) //And these, too,
		{
			((LineTripperHolder*)(holderArray[LINETRIPPER]))->AddLineTripper();
		}
		remainingCount = 0; //Nothing else needs to happen.
	}
	if (wave % 10 == 1 && wave > 10) remainingCount = 0; //Reward for stopping a boss.
	if (wave >= 3){
		int motherShipCount = remainingCount > 0 ? (rand() % (remainingCount / 2)) : 0;
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
	}
}

void Spawner::wave_CTRush()
{
	for (int i = 0; i < wave; i++)
	{
		((MothershipHolder*)(holderArray[MOTHERSHIP]))->addMothership();
		((CarrierHolder*)(holderArray[CARRIER]))->AddCarrier();
	}
}

void Spawner::wave_zombie()
{
    for (int i = 0; i < wave * 3; i++)
    {
        ((ZombieHolder*)(holderArray[ZOMBIE]))->AddZombie();
        if (rand() % 10 == 0)
        {
            ((LineTripperHolder*)(holderArray[LINETRIPPER]))->AddLineTripper();
            i--;
        }
    }
}
