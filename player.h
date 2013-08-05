#ifndef PLAYER_H
#define PLAYER_H

#include"mainUnit.h"
#include<QtGui>
#include<QtOpenGL>

class player : public mainUnit
{
    GLfloat m_pColor[3];
    GLfloat m_vertices[8];  // vertex array

  public:
    player();
    ~player(){}
    void InitVertices();
    GLint GetVertex(GLint);
    GLint GetVerticesNumb();

  public:
    virtual void Draw();
};
#endif // PLAYER_H
