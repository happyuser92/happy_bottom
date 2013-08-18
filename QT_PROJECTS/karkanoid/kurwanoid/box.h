#ifndef BOX_H
#define BOX_H

#include "graphicalobject.h"

class Box : public GraphicalObject
{
public:
    Box( float x, float y, const float& size, b2World *world );
	virtual ~Box();

	virtual void Draw();
    b2Body* GetBody();
private:
	const float SIZE;

//	b2PolygonShape m_Shape;
};

#endif // BOX_H
