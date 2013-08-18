#ifndef BRICK_H
#define BRICK_H

#include "graphicalobject.h"

class Brick : public GraphicalObject
{

public:
    Brick( float x, float y, float size, b2World *world );
	~Brick();

    void Draw();

private:
    float m_Size;
};

#endif // BRICK_H
