#include"mainUnit.h"

void mainUnit::SetX(GLint x)
{
   m_xCoord = x;
}

void mainUnit::SetY(GLint y)
{
   m_yCoord = y;
}

void mainUnit::SetSize(GLint s)
{
   m_size = s;
}

GLint mainUnit::GetX()
{
   return m_xCoord;
}

GLint mainUnit::GetY()
{
   return m_yCoord;
}

GLint mainUnit::GetSize()
{
   return m_size;
}

