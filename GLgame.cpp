#include "GLgame.h"

GLgame::GLgame(QWidget *parent):QGLWidget(parent)
{
    winWidth = 1000;
    winHeight = 800;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;

    cursor.setShape(Qt::BlankCursor);
    cursor.setPos(mapToGlobal(QPoint(winWidth/2, winHeight/2)).x(), mapToGlobal(QPoint(winWidth/2, winHeight/2)).y());
    this->setCursor(cursor);
    this->setMouseTracking(true);
    GLint tempX = (GLint)mapFromGlobal(cursor.pos()).x();
    GLint tempY = (GLint)mapFromGlobal(cursor.pos()).y();
    m_player.SetX(tempX);
    m_player.SetY(tempY);
    m_player.InitVertices();

    QTimer *m_timer = new QTimer(this);
    m_timer->start(20);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(Catched())); //emit takeMyCoords() from this every 20 ms

    glDepthFunc(GL_LEQUAL);
    setFormat(QGLFormat(QGL::DoubleBuffer));
}

GLgame::~GLgame()
{
}

void GLgame::mouseMoveEvent(QMouseEvent *event)
{
    m_player.SetX(event->x());  // change player's coordinates every time mouse moves
    m_player.SetY(event->y());
    m_player.InitVertices();
//    updateGL();  // redraw scene
}


void GLgame::initializeGL()
{
//    glDisable(GL_DEPTH_TEST);
//    glEnable(GL_POLYGON_SMOOTH);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(color[0], color[1], color[2], 0);
}

void GLgame::resizeGL(GLint width, GLint height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    winWidth = width;
    winHeight = height;
}

void GLgame::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,winWidth,winHeight,0,1,0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    qglColor(Qt::white);
    renderText(10, 10 , 0, QString::fromUtf8("bot's X coord %1   :").arg(m_bot.GetdeltaX()), QFont() , 2000);
    renderText(10, 20 , 0, QString::fromUtf8("bot's Y coord %1   :").arg(m_bot.GetdeltaY()), QFont() , 2000);
    renderText(10, 30 , 0, QString::fromUtf8("bot's angle to rotate %1   :").arg(m_bot.GetAngle()), QFont() , 2000);

    m_player.Draw();
    m_bot.Draw();
    swapBuffers();
}

void GLgame::Catched()
{
    GLint cxb = m_bot.GetX();
    GLint cyb = m_bot.GetY();  // getting player's parameters

    for(GLint i=0; i<m_player.GetVerticesNumb(); i+=2)  // revision if one of player's vertices are in bot's space
    {
      if( ((m_player.GetVertex(i)+cxb)*(m_player.GetVertex(i)+cxb) +
           (m_player.GetVertex(i+1)+cyb)*(m_player.GetVertex(i+1)+cyb)) <= m_bot.GetRadius() )
      {
        m_bot.NewRandomCoords();  //if true  -  comp new unit coordinates
        break;
      }

        m_bot.CompAngle(m_player.GetX(), m_player.GetY());  //if false  -  compute angle, deltaX and deltaY
    }
    updateGL();  //  redraw scene
}
