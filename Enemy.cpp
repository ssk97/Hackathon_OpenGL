#include <math.h>
#include "Enemy.h"

const double PLAYER_COLLISION_RADIUS = 12;
void Enemy::possibleCollideWithPlayer(double x, double y)
{
    if (sqrt(x*x + y*y) < PLAYER_COLLISION_RADIUS)
        collideWithPlayer();
}

const double FOLLOWER_COLLISION_RADIUS = 8;
void Enemy::possibleCollideWithFollower(double x, double y)
{
    if (sqrt(x*x + y*y) < FOLLOWER_COLLISION_RADIUS)
        collideWithFollower();
}
