#ifndef GLGAME_H
#define GLGAME_H

#include<QtGui/QWidget>
#include<QtGui/QCursor>
#include<QTimer>
#include<QtOpenGL>
#include"bot.h"
#include"player.h"

class GLgame : public QGLWidget
{
    Q_OBJECT

    GLint winWidth, winHeight;
    GLfloat color[3];
    QCursor cursor;

    player m_player;
    bot m_bot;

    public:
      GLgame(QWidget *parent=0);
      ~GLgame();

    public slots:
      void Catched();

    protected:
      void initializeGL();
      void resizeGL(GLint width, GLint height);
      void paintGL();
      void mouseMoveEvent(QMouseEvent *);
};

#endif // GLGAME_H
