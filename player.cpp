#include"player.h"

player::player()
{
   SetX(800);
   SetY(800);
   SetSize(30);
   m_pColor[0] = 1;
   m_pColor[1] = 1;
   m_pColor[2] = 1;
   InitVertices();
}
/***********************************************************************************************************/
void player::InitVertices()
{
    m_vertices[0] = GetX()-GetSize()/2;
    m_vertices[1] = GetY()-GetSize()/2;

    m_vertices[2] = GetX()+GetSize()/2;
    m_vertices[3] = GetY()-GetSize()/2;

    m_vertices[4] = GetX()+GetSize()/2;
    m_vertices[5] = GetY()+GetSize()/2;

    m_vertices[6] = GetX()-GetSize()/2;
    m_vertices[7] = GetY()+GetSize()/2;
}
/***********************************************************************************************************/
GLint player::GetVertex(GLint i)
{
    return m_vertices[i];
}
/************************************************************************************************************/
GLint player::GetVerticesNumb()
{
    return sizeof(m_vertices);
}
/************************************************************************************************************/
void player::Draw()
{
    glColor3f(m_pColor[0], m_pColor[1], m_pColor[2]);
    glBegin(GL_QUADS);
    glVertex2i(m_vertices[0], m_vertices[1]);
    glVertex2i(m_vertices[2], m_vertices[3]);
    glVertex2i(m_vertices[4], m_vertices[5]);
    glVertex2i(m_vertices[6], m_vertices[7]);
    glEnd();
/*    glEnableClientState(GL_VERTEX_ARRAY);    // drawing using vertex array
    glVertexPointer(2, GL_INT, 0, m_vertices);
    glDrawArrays(GL_LINE_LOOP, 0, 8);
    glDisableClientState(GL_VERTEX_ARRAY);*/
}
