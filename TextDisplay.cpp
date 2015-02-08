#include "TextDisplay.h"

TextDisplay::TextDisplay()
{
	setupDrawing();
}


TextDisplay::~TextDisplay()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
}


void TextDisplay::setupDrawing(){
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);//this is bound to the geometry setup in the next call
	vbo = setupGeometry();

	shaderProgram = glCreateProgram();
	vertexShader = setupVertexShader();
	glAttachShader(shaderProgram, vertexShader);
	fragmentShader = setupFragmentShader();
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);


	uniTrans = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(view));
}

const int numVertex[] = {5, 2, 6, 7, 5, 6, 6, 3, 7, 5, 4, 6 };
const int numPosStart[]={0, 5, 7, 13,20,25,31,36,39,46,51,55};
//						 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, N, R };
const double textWidth = 12;
const double textHeight = 16;
const double textSpacing = 18;
GLuint TextDisplay::setupGeometry(){
	GLuint vbo;

	float vertices[] = {
		-1, -1,//0
		-1, 1,
		1, 1,
		1, -1,
		-1, -1,

		0, -1,//1
		0, 1,

		-1, 1,//2
		1, 1,
		1, .2,
		-1, -.2,
		-1, -1,
		1, -1,

		-1, 1,//3
		1, 1,
		1, 0,
		-1, 0,
		1, 0,
		1, -1,
		-1, -1,

		-1, 1,//4
		-1, 0,
		1, 0,
		1, 1,
		1, -1,

		1, 1,//5
		-1, 1,
		-1, 0,
		1, 0,
		1, -1,
		-1, -1,

		-1, 1,//6
		-1, -1,
		1, -1,
		1, 0,
		-1, 0,

		-1, 1,//7
		1, 1,
		0, -1,

		-1, 1,//8
		-1, -1,
		1, -1,
		1, 1,
		-1, 1,
		-1, 0,
		1, 0,

		1,-1,//9
		1,1,
		-1,1,
		-1,0,
		1,0





		-1,-1,//N
		-1,1,
		1,-1,
		1,1,


		-1,-1,//R
		-1,1,
		1,1,
		1,0,
		-1,0,
		1,-1
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return vbo;
}
GLuint TextDisplay::setupVertexShader(){
	const GLchar* vertexSource =
		"#version 330 core\n"
		"in vec2 position;"
		"uniform mat4 trans;"
		"uniform mat4 view;"
		"void main() {"
		" gl_Position = view*trans*vec4(position, 0.0, 1.0);"//xyzw
		"}";
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	checkShader(vertexShader);
	return vertexShader;
}
GLuint TextDisplay::setupFragmentShader(){
	const GLchar* fragmentSource =
		"#version 330 core\n"
		"out vec4 outColor;"
		"void main() {"
		" outColor = vec4(1.0, 0.0, 0.0, 1.0);"//RGBA
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);
	return fragmentShader;
}
glm::mat4 TextDisplay::initDraw(){

	glUseProgram(shaderProgram);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glm::mat4 scaler;
	scaler = glm::scale(scaler, glm::vec3((float)textWidth / 2, (float)-textHeight, 0.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUseProgram(shaderProgram);
	return scaler;
}
void TextDisplay::endDraw(){
	//glDisableClientState(GL_COLOR_ARRAY);
}
//	~TextDisplay();
void TextDisplay::drawNumber(double x, double y, int num)
{
	glm::mat4 scaler = initDraw();
	int place = 0;
	//std::cout << std::endl;
	int maxdigit;
	if (num == 0) maxdigit = 1;
	else maxdigit = pow(10, floor(log10(num)));
	while (maxdigit > 0){
		glm::mat4 trans;
		trans = glm::translate(trans, glm::vec3((float)x+(place*textSpacing), (float)y, 0.0));
		glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans*scaler));
		int digit = 0;
		//std::cout << num << " " <<maxdigit<< std::endl;
		while (num >= maxdigit){
			digit++;
			num -= maxdigit;
		}
		glDrawArrays(GL_LINE_STRIP, numPosStart[digit], numVertex[digit]);
		place++;
		maxdigit /= 10;
	}
	endDraw();
}
void TextDisplay::drawChar(double x, double y, char chr)
{
	glm::mat4 scaler = initDraw();
	
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x, (float)y, 0.0));
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans*scaler));
	int position;
	switch (chr){
	case 'n':case 'N':
			position = 10; break;
	case 'r':case 'R':
			position = 11; break;
	}
	glDrawArrays(GL_LINE_STRIP, numPosStart[position], numVertex[position]);

	endDraw();
}
