#pragma once
#include "badDesign.h"
class TextDisplay
{
public:
	TextDisplay();
	~TextDisplay();
	void drawNumber(double x, double y, int num);
	void drawChar(double x, double y, char chr);
	glm::mat4 initDraw();
	void endDraw();
	GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;

	void setupDrawing();
	GLuint setupGeometry();
	GLuint setupVertexShader();
	GLuint setupFragmentShader();
};

