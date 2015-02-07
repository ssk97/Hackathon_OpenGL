#include "PlayerHolder.h"

Player* ThePlayer;

PlayerHolder::PlayerHolder()
{
	ThePlayer = new Player();
	addObj(ThePlayer);
}


PlayerHolder::~PlayerHolder()
{

}
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

GLuint PlayerHolder::setupGeometry(){
	GLuint vbo;
	const int count = 9,count2=36;
	float vertices[count * 2+count2*2];
	int vertexNum = 0;
	//triangles
	for (int i = 0; i < 6; i++){
		if (i % 2 == 0){
			vertices[vertexNum++] = 0.0f; vertices[vertexNum++] = 0.0f;
		}
		vertices[vertexNum++] = Dcos(i * 360 / (6))*30;
		vertices[vertexNum++] = Dsin(i * 360 / (6))*30;
	}
	//circle
	for (int i = 0; i < count2; i++){
		vertices[vertexNum++] = Dcos(i * 360 / (count2)) * 20;
		vertices[vertexNum++] = Dsin(i * 360 / (count2)) * 20;
	}
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}


void PlayerHolder::draw(GenericObject *obj)
{
	glDrawArrays(GL_TRIANGLES, 0, 9);
	glDrawArrays(GL_LINE_LOOP, 9, 36);
}