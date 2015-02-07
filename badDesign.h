#pragma once
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.14159265
#define Dsin(_inputVal) sin((_inputVal)*PI/180.0)
#define Dcos(_inputVal) cos((_inputVal)*PI/180.0)

class GenericHolder;

const int numTypes = 2;
extern GenericHolder* holderArray[numTypes];
const int PLAYER = 0, FOLLOWER = 1;

const int width = 1024;
const int height = 768;
extern glm::mat4 view;
extern GLFWwindow* window;

extern void checkShader(GLuint shader);
extern void checkErrors();
