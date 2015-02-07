#include "PlayerHolder.h"


// Shader sources
const GLchar* vertexSource =
"#version 330 core\n"
"in vec2 position;"
"uniform mat4 trans;"
"uniform mat4 view;"
"void main() {"
"   gl_Position = view*trans*vec4(position, 0.0, 1.0);"//xyzw
"}";
const GLchar* fragmentSource =
"#version 330 core\n"
"out vec4 outColor;"
"void main() {"
"   outColor = vec4(1.0, 0.0, 0.0, 1.0);"//RGBA
"}";


PlayerHolder::PlayerHolder()
{
	objs.push_back(Player());

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices[] = {
		0.0f, 0.0f, // Vertex 1 (X, Y)
		100.0f, 0.0f, // Vertex 2 (X, Y)
		0.0f, 100.0f  // Vertex 3 (X, Y)
	};
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//test
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	checkShader(vertexShader);


	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);


	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);


	uniTrans = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(view));
}


PlayerHolder::~PlayerHolder()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
}
