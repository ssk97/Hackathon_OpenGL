#include "Follower.h"
#include "badDesign.h"

Follower::Follower(){}

Follower::~Follower(){}

const double SPRING_CONSTANT = 0.001;
void Follower::update()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    xAcc = SPRING_CONSTANT * (mouseX - x);
    yAcc = SPRING_CONSTANT * (mouseY - y);

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


	glDrawArrays(GL_TRIANGLES, 0, 3);
}
