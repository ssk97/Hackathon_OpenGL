#include <math.h>
#include "Follower.h"

Follower::Follower(){}

Follower::~Follower(){}

const double SPRING_CONSTANT = 0.001;
const double FRICTION = .99;
const double SPRING_LENGTH = 20;
void Follower::update()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    double delta_y = mouseY - y;
    double delta_x = mouseX - x;

    double angleToTarget = atan2(delta_y, delta_x);
    double equilibrium_y = SPRING_LENGTH * sin(angleToTarget) + mouseY;
    double equilibrium_x = SPRING_LENGTH * cos(angleToTarget) + mouseX;

    yAcc = SPRING_CONSTANT * (equilibrium_y - y);
    xAcc = SPRING_CONSTANT * (equilibrium_x - x);

    xVel *= FRICTION;
    yVel *= FRICTION;
    xVel += xAcc;
    yVel += yAcc;

    x += xVel;
    y += yVel;
}

void Follower::draw(GLuint shaderProgram)
{
    glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x,(float)y, 0.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));


	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
}
