#ifndef PANEL_H
#define PANEL_H

#include "graphicalobject.h"

class Panel : public GraphicalObject
{
     float m_Width;
     float m_Height;

public:
     Panel( float w, float h, b2Body* boxBody, b2World &world);
     virtual ~Panel();
     b2Body* GetBody();
     float GetWidth();
     float GetHeight();

     virtual void Draw();
};

#endif // PANEL_H
