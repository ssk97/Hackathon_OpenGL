#include "GenericObject.h"
#include "Player.h"
#include "Follower.h"

class Enemy : public GenericObject
{
protected:
    virtual void collideWithPlayer() = 0;
    virtual void collideWithFollower() = 0;
public:
    void possibleCollideWithPlayer();
    void possibleCollideWithFollower();
};
