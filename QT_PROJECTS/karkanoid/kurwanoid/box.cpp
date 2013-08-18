#include "box.h"

Box::Box( float x, float y, const float &size, b2World *world ) :
    GraphicalObject( world ),
	SIZE( size )
{
	m_Density = 5.0f;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set( x, y );
    m_Body = m_World->CreateBody( &bodyDef );

    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(1, 1); //a 2x2 rectangle

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = m_Density;


    polygonShape.SetAsBox( SIZE / 40, SIZE / 2, b2Vec2(-SIZE/2, 0), 0 ); //left
    m_Body->CreateFixture( &myFixtureDef);
    polygonShape.SetAsBox( SIZE / 40, SIZE / 2, b2Vec2(SIZE/2, 0), 0 ); //right
    m_Body->CreateFixture( &myFixtureDef);
    polygonShape.SetAsBox( SIZE / 2, SIZE / 40, b2Vec2(0, SIZE/2), 0 ); //top
    m_Body->CreateFixture( &myFixtureDef);
    polygonShape.SetAsBox( SIZE / 2, SIZE / 40, b2Vec2(0, -SIZE/2), 0 ); //bottom
    m_Body->CreateFixture( &myFixtureDef);

}

Box::~Box()
{
}

void Box::Draw()
{
	float x = m_Body->GetWorldCenter().x;
	float y = m_Body->GetWorldCenter().y;
    glBegin( GL_POLYGON ); //left
        glVertex2f( x - SIZE / 2, y - SIZE / 2 ); //bottom-left
        glVertex2f( x - SIZE / 2, y + SIZE / 2 ); //top-left
        glVertex2f( x - SIZE / 2 + SIZE / 40, y + SIZE / 2 ); //top-right
        glVertex2f( x - SIZE / 2 + SIZE / 40, y - SIZE / 2 ); //bottom-right
	glEnd();
    glBegin( GL_POLYGON ); //right
        glVertex2f( x + SIZE / 2 - SIZE / 40, y - SIZE / 2 ); // bottom-left
        glVertex2f( x + SIZE / 2 - SIZE / 40, y + SIZE / 2 ); // top-left
        glVertex2f( x + SIZE / 2, y + SIZE / 2 ); //top-right
        glVertex2f( x + SIZE / 2, y - SIZE / 2 ); // bottom-right
    glEnd();
    glBegin( GL_POLYGON ); //top
        glVertex2f( x - SIZE / 2, y + SIZE / 2 - SIZE / 40 ); //bottom-left
        glVertex2f( x - SIZE / 2, y + SIZE / 2 ); //top-left
        glVertex2f( x + SIZE / 2, y + SIZE / 2 ); //top-right
        glVertex2f( x + SIZE / 2, y + SIZE / 2 - SIZE / 40); //bottom-right
    glEnd();
    glBegin( GL_POLYGON ); //bottom
        glVertex2f( x - SIZE / 2, y - SIZE / 2 ); //bottom-left
        glVertex2f( x - SIZE / 2, y - SIZE / 2 + SIZE / 40 ); //top-left
        glVertex2f( x + SIZE / 2, y - SIZE / 2 + SIZE / 40); //top-right
        glVertex2f( x + SIZE / 2, y - SIZE / 2 ); //bottom-right
    glEnd();
}

b2Body* Box::GetBody()
{
   return m_Body;
}
