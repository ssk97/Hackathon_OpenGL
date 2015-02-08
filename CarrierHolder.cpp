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
		-6.0f, -6.0f,
		6.0f, -6.0f,
		-6.0f, 6.0f,
		6.0f, 6.0f,
		//end triangles, on to lines
		5.0f, 5.0f,
		10.0f, 7.0f,

		5.0f, -5.0f,
		10.0f, -7.0f
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}
void CarrierHolder::draw(GenericObject *obj)
{
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDrawArrays(GL_LINES, 4, 4);
}

