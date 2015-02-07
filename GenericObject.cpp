#include "GenericObject.h"


GenericObject::GenericObject()
{
	updateOldPos();
}


GenericObject::~GenericObject()
{
}

void GenericObject::updateOldPos(){
	oldx = x; oldy = y;
	oldangle = angle;
}
double GenericObject::distMoved(){
	return (abs(x - oldx) + abs(y - oldy)) / 4;
}
void GenericObject::transform(GLuint shaderProgram, double t)//t = motion blur: 0 = old frame, 1 = this frame
{
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)(oldx + (x - oldx)*t), (float)(oldy + (y - oldy)*t), 0.0));
	trans = glm::rotate(trans, (float)angle, glm::vec3(0.0, 0.0, 1.0));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}
