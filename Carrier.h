#include "Enemy.h"

class Carrier : public Enemy //Public Enemy Number 1.
{
public:
    Carrier();
    Carrier(double x, double y);
    ~Carrier();
    void update();
    void collideWithPlayer();
    void collideWithFollower();
private:
    int numFramesSinceMissile;
};
