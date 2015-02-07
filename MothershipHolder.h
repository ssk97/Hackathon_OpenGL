#include "GenericHolder.h"

class MothershipHolder : public GenericHolder
{
public:
    MothershipHolder();
    ~MothershipHolder();
	void potentiallyAddMothership();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);

};
