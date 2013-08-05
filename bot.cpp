#include"bot.h"

bot::bot()
{
  SetX(450);
  SetY(450);
  SetSize(30);
  m_radius = GetSize()*GetSize()/4;
  m_speed = 10;
  m_angle = 0;
  m_smallAngle = 0;
  m_deltaX = 0;
  m_deltaY = 0;
  m_bColor[0] = 1;
  m_bColor[1] = 1;
  m_bColor[2] = 1;
  InitVertices();
}
/****************************************************************************************************************/
void bot::InitVertices()
{
     m_vertices[0] = (-1)*GetSize()/2;
     m_vertices[1] = (-1)*GetSize()/2;

     m_vertices[2] = (-1)*GetSize()/2;
     m_vertices[3] = 0.0;

     m_vertices[4] = (-1)*GetSize()/2;
     m_vertices[5] =  GetSize()/2;

     m_vertices[6] = 0.0;
     m_vertices[7] = GetSize()/2;

     m_vertices[8] = GetSize()/2;
     m_vertices[9] = GetSize()/2;

    m_vertices[10] = GetSize()/2;
    m_vertices[11] = 0.0;

    m_vertices[12] =  GetSize()/2;
    m_vertices[13] = (-1)*GetSize()/2;

    m_vertices[14] = 0.0;
    m_vertices[15] = (-1)*GetSize()/2;
}

GLfloat bot::GetRadius()
{
    return m_radius;
}
/****************************************************************************************************************/
void bot::CompAngle(GLint xp, GLint yp)
{
    if(xp == GetX())
    {
        if(yp < GetY())
        {
          m_angle = 270;
          m_deltaX = -m_speed;
          m_deltaY = 0;
        }
        else if(yp < GetY())
        {
          m_angle = 90;
          m_deltaX = m_speed;
          m_deltaY = 0;
        }
    }
    if(yp == GetY())
    {
        if(xp < GetX())
        {
          m_angle = 180;
          m_deltaX = -m_speed;
          m_deltaY = 0;
        }
        else if(xp > GetX())
        {
          m_angle = 0;
          m_deltaX = m_speed;
          m_deltaY = 0;
        }
    }

    if(xp > GetX() && yp < GetY())
    {

       m_angle = 270 + atan((xp-GetX())/(GetY()-yp)) * (180/3.1416);
       m_smallAngle  = m_angle - 270;
       m_deltaX =  m_speed * sin(m_smallAngle);
       m_deltaY = -m_speed * cos(m_smallAngle);
    }

    if(xp > GetX() && yp > GetY())
    {
       m_angle = atan((yp-GetY())/(xp-GetX())) * (180/3.1416);
       m_smallAngle = m_angle;
       m_deltaX = m_speed * cos(m_smallAngle);
       m_deltaY = m_speed * sin(m_smallAngle);
    }

    if(xp < GetX() && yp > GetY())
    {
       m_angle = 90 + atan((GetX()-xp)/(yp-GetY())) * (180/3.1416);
       m_smallAngle = m_angle - 90;
       m_deltaX = -m_speed * sin(m_smallAngle);
       m_deltaY =  m_speed * cos(m_smallAngle);
    }

    if(xp < GetX() && yp < GetY())
    {
       m_angle = 180 + atan((GetY()-yp)/(GetX()-xp)) * (180/3.1416);
       m_smallAngle =  m_angle - 180;
       m_deltaX = -m_speed * cos(m_smallAngle);
       m_deltaY = -m_speed * sin(m_smallAngle);
    }
}
/***********************************************************************************************************************/
void bot::NewRandomCoords()
{
    SetX(Random(1600));
    SetY(Random(1600));
}
/***********************************************************************************************************************/
GLint bot::Random(GLint value)
{
   srand(time(NULL));
   return rand()%value;
}
/***********************************************************************************************************************/
void bot::Draw()
{
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(GetX(), GetY(), 0.0);
   glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(m_speed, 0, 0);
   glColor3f(m_bColor[0], m_bColor[1], m_bColor[2]);
   glBegin(GL_POLYGON);
   glVertex2i(m_vertices[0], m_vertices[1]);
   glVertex2i(m_vertices[2], m_vertices[3]);
   glVertex2i(m_vertices[4], m_vertices[5]);
   glVertex2i(m_vertices[6], m_vertices[7]);
   glVertex2i(m_vertices[8], m_vertices[9]);
   glVertex2i(m_vertices[10], m_vertices[11]);
   glVertex2i(m_vertices[12], m_vertices[13]);
   glVertex2i(m_vertices[14], m_vertices[15]);
   glEnd();
/*   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2, GL_INT, 0, m_vertices);
   glDrawArrays(GL_LINE_LOOP, 0, 16);
   glDisableClientState(GL_VERTEX_ARRAY);*/
   glPopMatrix();
   SetX(GetX()+(GLint)m_deltaX);
   SetY(GetY()+(GLint)m_deltaY);
}
 GLfloat bot::GetAngle()
 {
    return m_smallAngle;
 }
GLfloat bot::GetdeltaX()
{
   return m_deltaX;
}
GLfloat bot::GetdeltaY()
{
   return m_deltaY;
}
