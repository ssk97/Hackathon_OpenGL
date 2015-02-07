#include "GenericObject.h"

class Enemy : public GenericObject
{
protected:
    virtual void collideWithPlayer();
    virtual void collideWithFollower();
public:
    void possibleCollideWithPlayer(double x, double y);
    void possibleCollideWithFollower(double x, double y);
};
