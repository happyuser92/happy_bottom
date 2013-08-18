#include "graphicalobject.h"

GraphicalObject::GraphicalObject ( b2World *world ) :
    m_World( world )
{
}


GraphicalObject::~GraphicalObject()
{
	m_Body = NULL;
}
