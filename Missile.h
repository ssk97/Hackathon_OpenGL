#include "Enemy.h"

class Missile : public Enemy //Public Enemy Number 1.
{
public:
    Missile();
    Missile(double x, double y, double angle);
    ~Missile();
    void update();
    void collideWithPlayer();
	void collideWithFollower();

};
