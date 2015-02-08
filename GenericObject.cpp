#include "GenericObject.h"


GenericObject::GenericObject()
{
	updateOldPos();
}


GenericObject::~GenericObject()
{
}

void GenericObject::updateOldPos() {
	oldx = x; oldy = y;
	oldangle = angle;
};

double GenericObject::distMoved(){
	return (abs(x - oldx) + abs(y - oldy)) / 4;
}
glm::mat4 GenericObject::rotation()
{
	glm::mat4 trans;
	trans = glm::rotate(trans, (float)angle, glm::vec3(0.0, 0.0, 1.0));
	return trans;
}
glm::mat4 GenericObject::translateOld()//t = motion blur: 0 = old frame, 1 = this frame
{
	/*glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)(oldx), (float)(oldy), 0.0));
	return trans;*/
}
glm::mat4 GenericObject::translate()//t = motion blur: 0 = old frame, 1 = this frame
{
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3((float)x, (float)y, 0.0));
	return trans;
}
