#include "Enemy.h"

class Zombie : public Enemy //Public Enemy Number 1.
{
public:
    Zombie();
    ~Zombie();
    void update();
    void collideWithPlayer();
    void collideWithFollower();
    int id;
};
