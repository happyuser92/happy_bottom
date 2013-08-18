#include "brick.h"

Brick::Brick( float x, float y, float size, b2World *world ) : GraphicalObject( world )
{
    m_Size = size; // set some proper size!
	m_Density = 2.0f;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
    bodyDef.allowSleep = true;
    bodyDef.awake = false;
	bodyDef.position.Set(x, y);

	b2PolygonShape shape;
	shape.SetAsBox(m_Size/2, m_Size/2);

    m_Body = m_World->CreateBody(&bodyDef);
	m_Body->CreateFixture(&shape, m_Density);

}

Brick::~Brick()
{

}

void Brick::Draw()
{
    float x = m_Body->GetWorldCenter().x;
    float y = m_Body->GetWorldCenter().y;
   glBegin(GL_POLYGON);
     glVertex2f(x - m_Size/2, y - m_Size/2);
     glVertex2f(x - m_Size/2, y + m_Size/2);
     glVertex2f(x + m_Size/2, y + m_Size/2);
     glVertex2f(x + m_Size/2, y - m_Size/2);
   glEnd();
}
