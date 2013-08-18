#include "panel.h"

Panel::Panel( float w, float h, b2Body *boxBody, b2World *world ) : GraphicalObject( world )
{
   m_Height = h;
   m_Width = w;

   m_Density = 1.0f;

   b2BodyDef m_BodyDef;
   m_BodyDef.type = b2_dynamicBody;
   m_BodyDef.position.Set(0.0f, 2*m_Height);

   b2PolygonShape shape;
   shape.SetAsBox(m_Width/2, m_Height/2);

   m_Body = m_World->CreateBody(&m_BodyDef);
   m_Body->CreateFixture(&shape, m_Density);

   b2PrismaticJointDef panelJointDef;
   panelJointDef.bodyA = boxBody; // box body
   panelJointDef.bodyB = m_Body;
   panelJointDef.collideConnected = false;
   panelJointDef.localAxisA.Set(1, 0);  // move along x-axis only
   panelJointDef.localAnchorA.Set(0, -1); // link one end of the joint to the box center
   panelJointDef.localAnchorB.Set(0, m_Width*1.4); // set point on the panel which is sliding along x_axis

   b2PrismaticJoint* panelJoint = (b2PrismaticJoint*)m_World->CreateJoint(&panelJointDef);
}

Panel::~Panel()
{

}

b2Body* Panel::GetBody()
{
    return m_Body;
}

void Panel::Draw()
{
    float x = m_Body->GetWorldCenter().x;
    float y = m_Body->GetWorldCenter().y;
   glBegin(GL_POLYGON);
     glVertex2f(x - m_Width/2, y - m_Height/2);
     glVertex2f(x - m_Width/2, y + m_Height/2);
     glVertex2f(x + m_Width/2, y + m_Height/2);
     glVertex2f(x + m_Width/2, y - m_Height/2);
   glEnd();
}

float Panel::GetWidth()
{
   return m_Width;
}

float Panel::GetHeight()
{
   return m_Height;
}
