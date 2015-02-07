#include "GenericHolder.h"

class ZombieHolder : public GenericHolder
{
public:
    ZombieHolder();
    ~ZombieHolder();
	void AddZombie();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);
};
