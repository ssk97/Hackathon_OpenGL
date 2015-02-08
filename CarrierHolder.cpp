#include <cstdlib>
#include "CarrierHolder.h"
#include "Carrier.h"


CarrierHolder::CarrierHolder()
{
}

CarrierHolder::~CarrierHolder()
{
}

void CarrierHolder::AddCarrier()
{
	addObj(new Carrier());
}

GLuint CarrierHolder::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		"   outColor = vec4(1.0, .1, 0.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}
GLuint CarrierHolder::setupGeometry(){
	GLuint vbo;
	float vertices[] = {
		-8, 6,
		-8, -6,
		8, 6,

		8, -6,
		8, 6,
		-8, -6,

		8, 6,
		14, 2,
		8, 2,

		8, -6,
		14, -2,
		8, -2
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}
void CarrierHolder::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 12);
}