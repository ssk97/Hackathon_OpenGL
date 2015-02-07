#include <cstdlib>
#include "LineTripperHolder.h"
#include "LineTripper.h"


LineTripperHolder::LineTripperHolder()
{
}

LineTripperHolder::~LineTripperHolder()
{
}

void LineTripperHolder::AddLineTripper()
{
	addObj(new LineTripper());
}

GLuint LineTripperHolder::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		"   outColor = vec4(0.0, .2, 1.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}
GLuint LineTripperHolder::setupGeometry(){
	GLuint vbo;
	float vertices[] = {
		-5.0f, -5.0f,
		5.0f, -5.0f,
		-5.0f, 5.0f,
		5.0f, 5.0f,
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
void LineTripperHolder::draw(GenericObject *obj)
{
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDrawArrays(GL_LINES, 4, 4);
}

