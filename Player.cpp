#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
	glfwGetCursorPos(window, &x, &y);
}
void Player::draw(GLuint shaderProgram)
{
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x,(float)y, 0.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
	

	glDrawArrays(GL_TRIANGLES, 0, 3);

}
