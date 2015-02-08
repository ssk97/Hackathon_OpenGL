#include <math.h>
#include "Enemy.h"

Enemy::Enemy()
{
	switch (rand() % 4)
	{
	case 0:
		y = 0;
		x = rand() % width;
		break;
	case 1:
		y = height;
		x = rand() % width;
		break;
	case 2:
		y = rand() % height;
		x = 0;
		break;
	case 3:
		y = rand() % height;
		x = width;
		break;
	}
	angle = ((double)rand() / RAND_MAX) * 360;
}



static bool checkCollisionLineCircle(double x0, double y0, double x1, double y1, double x2, double y2, double r)
{//Check collision from line segment (x0,y0),(x1,y1) to circle (x2,y2) with radius r
	//source: http://www.openprocessing.org/sketch/65771

	// Translate everything so that line segment start point to (0, 0)
	double a = x1 - x0; // Line segment end point horizontal coordinate
	double b = y1 - y0; // Line segment end point vertical coordinate
	double c = x2 - x0; // Circle center horizontal coordinate
	double d = y2 - y0; // Circle center vertical coordinate

	// Collision computation
	if ((d*a - c*b)*(d*a - c*b) <= r*r*(a*a + b*b)) {
		// Collision is possible
		if (c*c + d*d <= r*r) {
			// Line segment start point is inside the circle
			return true;
		}
		if ((a - c)*(a - c) + (b - d)*(b - d) <= r*r) {
			// Line segment end point is inside the circle
			return true;
		}
		if ((a != 0 && b != 0) && (c*a + d*b >= 0) && (c*a + d*b <= a*a + b*b)) {
			// Middle section only
			return true;
		}
	}
	return false;
}

//sizes are size of enemy, radius
void Enemy::possibleCollideWithPlayer()
{
	GenericObject* player = ThePlayer;
	if (score > 100 && checkCollisionLineCircle(player->oldx, player->oldy, player->x, player->y, x, y, size+20)){
		gameOver = true;
	}
}

void Enemy::possibleCollideWithFollower()
{ 

	GenericObject* follower = TheFollower;
	if (checkCollisionLineCircle(follower->oldx, follower->oldy, follower->x, follower->y,x,y,size+25)){
		markedForDeath = true;
	}
}

