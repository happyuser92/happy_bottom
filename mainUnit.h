#ifndef MAINUNIT_H
#define MAINUNIT_H

#include<QtOpenGL>

class mainUnit
{
  GLint m_xCoord, m_yCoord, m_size;

  public:
     mainUnit(){}
    ~mainUnit(){}
     void SetX(GLint);
     void SetY(GLint);
     void SetSize(GLint);
     GLint GetX();
     GLint GetY();
     GLint GetSize();
  protected:
     virtual void Draw()=0;
};
#endif // MAINUNIT_H
