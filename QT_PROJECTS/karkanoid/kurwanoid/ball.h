#ifndef BALL_H
#define BALL_H

#include "graphicalobject.h"

class Ball : public GraphicalObject
{
public:
    Ball( b2World* world );
	virtual ~Ball();

	virtual void Draw();
};

#endif // BALL_H
