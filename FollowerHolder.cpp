#include "FollowerHolder.h"

FollowerHolder::FollowerHolder()
{
	objs.push_back(new Follower());

    setupGlForRedTriangle();
}

FollowerHolder::~FollowerHolder()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
}
