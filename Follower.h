#include "GenericObject.h"

class Follower : GenericObject
{
public:
    void update();
    void draw();
private:
    double xVel = 0;
    double yVel = 0;
    double xAcc = 0;
    double yAcc = 0;
};
