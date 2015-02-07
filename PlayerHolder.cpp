#include "PlayerHolder.h"





PlayerHolder::PlayerHolder()
{
	objs.push_back(new Player());

    setupGlForRedTriangle();
}


PlayerHolder::~PlayerHolder()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
}
