#pragma once
#include "GenericHolder.h"
#include "Follower.h"

class FollowerHolder: public GenericHolder
{
public:
	FollowerHolder();
	~FollowerHolder();
	GLuint setupGeometry();
};

