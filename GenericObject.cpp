#include "GenericObject.h"


GenericObject::GenericObject()
{
}


GenericObject::~GenericObject()
{
}

void GenericObject::transform(GLuint shaderProgram)
{
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x, (float)y, 0.0));
	trans = glm::rotate(trans, (float)angle, glm::vec3(0.0, 0.0, 1.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}
