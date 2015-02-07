#pragma once
#include <malloc.h>
#include "SOIL.h"
#include "badDesign.h"
class TextDisplay
{
public:
	TextDisplay();
	~TextDisplay();
	void drawText(double x, double y, const char* text);
	GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;
	int img_width, img_height;
};

