#include <cstdlib>
#include "MothershipHolder.h"
#include "Mothership.h"


MothershipHolder::MothershipHolder()
{
}

MothershipHolder::~MothershipHolder()
{
}

void MothershipHolder::addMothership()
{
    addObj(new Mothership());
}
GLuint MothershipHolder::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		"   outColor = vec4(1.0, 0.1, 1.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}
GLuint MothershipHolder::setupGeometry(){
	GLuint vbo;
	float vertices[] = {
		-5.0f, -0.0f,
		5.0f, -8.0f,
		5.0f, 8.0f,
		//end triangles, on to lines
		5.0f, 8.0f,
		-5.0f, 15.0f,

		5.0f, -8.0f,
		-5.0f, -15.0f
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}
void MothershipHolder::draw(GenericObject *obj)
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_LINES, 3, 4);
}

