
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int width = 1024;
const int height = 768;

using namespace std;

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

double mouseX, mouseY;
void checkShader(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		std::cout << buffer;
	}
}
void checkErrors()
{
	GLenum err = glGetError();
	if (err != GL_NO_ERROR){
		;
	}
}
GLFWwindow* setupDrawing(){
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL); // Fullscreen
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	return window;
}
int main()
{
	//GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr); // Windowed

	GLFWwindow* window = setupDrawing();

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices[] = {
		0.0f, 0.0f, // Vertex 1 (X, Y)
		100.0f, 0.0f, // Vertex 2 (X, Y)
		0.0f, 100.0f  // Vertex 3 (X, Y)
	};
	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//test
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	checkShader(vertexShader);


	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);


	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);


	glm::mat4 view;
	view = glm::translate(view, glm::vec3(-1,1, 0));
	view = glm::scale(view, glm::vec3( 2.0/width, -2.0/height, 1.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(view));

	auto maxtime = chrono::milliseconds(1000 / 120);

	while (!glfwWindowShouldClose(window))
	{
		
		chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
		
		checkErrors();
		glfwPollEvents();
		glfwGetCursorPos(window, &mouseX, &mouseY);
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);


		glm::mat4 trans;
		trans = glm::translate(trans, glm::vec3((float)mouseX,(float)mouseY, 0.0));
		GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
		glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
		// Clear the screen to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);


		glfwSwapBuffers(window);

		auto time_span = chrono::steady_clock::now() - t1;
		this_thread::sleep_for(maxtime - time_span);
	}

	
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
	
	glfwTerminate();
}