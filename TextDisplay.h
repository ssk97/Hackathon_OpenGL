#pragma once
#include "badDesign.h"
class TextDisplay
{
public:
	TextDisplay();
	~TextDisplay();
	void drawNumber(double x, double y, int num);
	GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;

	void setupDrawing();
	GLuint setupGeometry();
	GLuint setupVertexShader();
	GLuint setupFragmentShader();
};

