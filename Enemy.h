#include "GenericObject.h"

class Enemy : public GenericObject
{
protected:
    virtual void collideWithPlayer() = 0;
    virtual void collideWithFollower() = 0;
public:
    void possibleCollideWithPlayer(double x, double y);
    void possibleCollideWithFollower(double x, double y);
};
