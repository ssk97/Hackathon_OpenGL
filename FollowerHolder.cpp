#include "FollowerHolder.h"

Follower* TheFollower;
FollowerHolder::FollowerHolder()
{
	TheFollower = new Follower();
	addObj(TheFollower);
}

FollowerHolder::~FollowerHolder()
{
}


GLuint FollowerHolder::setupGeometry(){
	GLuint vbo;
	const int count = 40;
	float vertices[count * 2];
	vertices[0] = 0.0f; vertices[1] = 0.0f;
	int vertexNum = 2;
	for (int i = 0; i < count-1; i += 1){
		vertices[vertexNum++] = Dcos(i * 360 / (count-2))*((i % 2) * 20 + 10);
		vertices[vertexNum++] = Dsin(i * 360 / (count-2))*((i % 2) * 20 + 10);
	}
	assert(vertexNum == count * 2);
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}

void FollowerHolder::draw(GenericObject *obj)
{
	glDrawArrays(GL_TRIANGLE_FAN, 0, 40);
}
