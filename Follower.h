#pragma once
#include "GenericObject.h"

class Follower : public GenericObject
{
public:
    Follower();
    ~Follower();
    void update();
private:
    double xVel = 0;
    double yVel = 0;
    double xAcc = 0;
    double yAcc = 0;
};
