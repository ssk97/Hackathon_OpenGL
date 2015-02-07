#include <math.h>
#include "Enemy.h"

const double PLAYER_COLLISION_RADIUS = 12;
void Enemy::possibleCollideWithPlayer()
{
    //if (sqrt(x*x + y*y) < PLAYER_COLLISION_RADIUS)
        //collideWithPlayer();
}

const double FOLLOWER_COLLISION_RADIUS = 8;
void Enemy::possibleCollideWithFollower()
{ 
	//source: http://www.openprocessing.org/sketch/65771

	GenericObject* follower = TheFollower;
	// Translate everything so that line segment start point to (0, 0)
	double a = (follower->x) - (follower->oldx); // Line segment end point horizontal coordinate
	double b = (follower->y) - (follower->oldy); // Line segment end point vertical coordinate
	double c = x - (follower->oldx); // Circle center horizontal coordinate
	double d = y - (follower->oldy); // Circle center vertical coordinate
	double r = 40;

	// Collision computation
	bool startInside = false;
	bool endInside = false;
	bool middleInside = false;
	if ((d*a - c*b)*(d*a - c*b) <= r*r*(a*a + b*b)) {
		// Collision is possible
		if (c*c + d*d <= r*r) {
			// Line segment start point is inside the circle
			startInside = true;
		}
		if ((a - c)*(a - c) + (b - d)*(b - d) <= r*r) {
			// Line segment end point is inside the circle
			endInside = true;
		}
		if (!startInside && !endInside && c*a + d*b >= 0 && c*a + d*b <= a*a + b*b) {
			// Middle section only
			middleInside = true;
		}
	}
	if (startInside || endInside || middleInside){
		markedForDeath = true;
	}
}
