#include "GenericObject.h"

class Follower : public GenericObject
{
public:
    Follower();
    ~Follower();
    void update();
    void draw(GLuint shaderProgram);
private:
    double xVel = 0;
    double yVel = 0;
    double xAcc = 0;
    double yAcc = 0;
};
