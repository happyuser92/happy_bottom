#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include <Box2D/Box2D.h>
#include <GL/gl.h>

/**
  * This is an abstract class. All classes which object will be displayed should inherit this class
  * and implement the Draw() method.
  */
class GraphicalObject
{
public:
    //TODO Add really informative commentary.
    GraphicalObject( b2World *world );
	virtual ~GraphicalObject()=0;

	virtual void Draw()=0;

protected:
    float32 m_Density;

//It doesn't need to be deleted in destructor. m_World will delete every object that it has created.
	b2Body* m_Body;
    b2World* m_World;

};

#endif // GRAPHICALOBJECT_H
