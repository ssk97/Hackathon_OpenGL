#pragma once
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

class GenericHolder;

const int numTypes = 10;
extern GenericHolder* holderArray[numTypes];
const int PLAYER = 0, FOLLOWER = 1;

const int width = 1024;
const int height = 768;
extern glm::mat4 view;
extern GLFWwindow* window;

extern void checkShader(GLuint shader);
extern void checkErrors();