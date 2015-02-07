#include "badDesign.h"
#include "PlayerHolder.h"
#include "FollowerHolder.h"
#include "ZombieHolder.h"

using namespace std;
 glm::mat4 view;
 GLFWwindow* window;
 GenericHolder* holderArray[numTypes];

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

	window = setupDrawing();

	view = glm::translate(view, glm::vec3(-1, 1, 0));
	view = glm::scale(view, glm::vec3(2.0 / width, -2.0 / height, 1.0));

	auto maxtime = chrono::milliseconds(1000 / 120);
	holderArray[PLAYER] = new PlayerHolder();
	holderArray[FOLLOWER] = new FollowerHolder();
	holderArray[ZOMBIE] = new ZombieHolder();

	for (int i = 0; i < numTypes; i++){
		holderArray[i]->setupDrawing();
	}

	while (!glfwWindowShouldClose(window))
	{
		chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

		checkErrors();
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		for (int i = 0; i < numTypes; i++){
			holderArray[i]->updateAll();
		}
		((ZombieHolder*)(holderArray[ZOMBIE]))->potentiallyAddZombie();

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < numTypes; i++){
			holderArray[i]->drawAll();
		}
		glfwSwapBuffers(window);

		auto time_span = chrono::steady_clock::now() - t1;
		this_thread::sleep_for(maxtime - time_span);

	}



	glfwTerminate();
}
