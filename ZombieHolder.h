#include "GenericHolder.h"

class ZombieHolder : public GenericHolder
{
public:
    ZombieHolder();
    ~ZombieHolder();
	void potentiallyAddZombie();
	GLuint setupFragmentShader();
	GLuint setupGeometry();
    void draw(GenericObject *obj);
    void removeZombie();
};
