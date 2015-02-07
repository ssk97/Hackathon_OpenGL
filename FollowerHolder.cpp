#include "FollowerHolder.h"

FollowerHolder::FollowerHolder()
{
	objs.push_back(new Follower());

}

FollowerHolder::~FollowerHolder()
{
}


GLuint FollowerHolder::setupGeometry(){
	GLuint vbo;
	float vertices[] = {
		50.0f, 0.0f, // Vertex 1 (X, Y)
		100.0f, 100.0f, // Vertex 2 (X, Y)
		0.0f, 100.0f,  // Vertex 3 (X, Y)

		50.0f, 100.0f, // Vertex 1 (X, Y)
		100.0f, 0.0f, // Vertex 2 (X, Y)
		0.0f, 0.0f  // Vertex 3 (X, Y)
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}