#include <cstdlib>
#include "MissileHolder.h"
#include "Missile.h"


MissileHolder::MissileHolder()
{
}

MissileHolder::~MissileHolder()
{
}

void MissileHolder::AddMissile()
{
	addObj(new Missile());
}

void MissileHolder::AddMissile(double x, double y, double angle)
{
	addObj(new Missile(x, y, angle));
}

GLuint MissileHolder::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		"   outColor = vec4(1.0, 0.0, 0.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}
GLuint MissileHolder::setupGeometry(){
	GLuint vbo;
	float vertices[] = {
		-4, 3,
		-4, -3,
		0, 3,
		-0, -3,
		10, 0
			};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}
void MissileHolder::draw(GenericObject *obj)
{
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);
}

