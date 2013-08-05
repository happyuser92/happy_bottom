#ifndef BOT_H
#define BOT_H

#include"mainUnit.h"
#include<QtOpenGL>
#include<stdlib.h>
#include<math.h>
#include<time.h>

class bot: public mainUnit
{
    GLint m_deltaX, m_deltaY; // values for adding to coords
    GLint m_vertices[16];  // vertex array
    GLfloat m_radius;
    GLfloat m_angle;  // angle to rotate the unit
    GLfloat m_smallAngle;
    GLint m_speed; // distance for the unit to move each time
    GLfloat m_bColor[3];

  public:
    bot();
    ~bot(){}
    void InitVertices();  // initialize a vertex array for easy drawing
    GLfloat GetRadius();
    GLfloat GetAngle();
    GLfloat GetdeltaX();
    GLfloat GetdeltaY();
    void CompAngle(GLint, GLint);  // computing angle to rotate, deltaX and deltaY
    void NewRandomCoords(); // computing new coords for unit if the player was catched
    GLint Random(GLint);

  public:
    virtual void Draw();
};

#endif // BOT_H
