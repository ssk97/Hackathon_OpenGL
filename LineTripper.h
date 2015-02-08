#include "Enemy.h"

class LineTripper : public Enemy //Public Enemy Number 1.
{
public:
	LineTripper();
	LineTripper(double x, double y);
	~LineTripper();
    void update();
    void collideWithPlayer();
    void collideWithFollower();
private:
    double goalX;
    double goalY;
    bool atGoal;
    double targetX;
    double targetY;
	double speed;
	double moveAngle;
};
