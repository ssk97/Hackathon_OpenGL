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
    double aimX;
    double aimY;
	int state;//0=shooting, 1=targetting
	double speed;
	double moveAngle;
};
