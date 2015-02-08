#include "Enemy.h"

class Mothership : public Enemy //Public Enemy Number 2.
{
public:
    Mothership() ;
    ~Mothership();
    void update();
    void collideWithPlayer();
	void collideWithFollower();

private:
    int framesAlive;
};
