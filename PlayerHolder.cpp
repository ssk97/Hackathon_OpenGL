#include "PlayerHolder.h"


// Shader sources
GLuint PlayerHolder::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		"   outColor = vec4(1.0, 1.0, 0.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}

PlayerHolder::PlayerHolder()
{
	addObj(new Player());
}


PlayerHolder::~PlayerHolder()
{

}


void PlayerHolder::draw(GenericObject *obj)
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}