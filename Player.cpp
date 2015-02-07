#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
	std::cout << "ub" << std::endl;
	glfwGetCursorPos(window, &x, &y);
}
void Player::draw(GLuint shaderProgram)
{
	std::cout << "boom" << std::endl;
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x,(float)y, 0.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
	// Clear the screen to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);


}