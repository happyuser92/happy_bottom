#include "game.h"

const Game::Border Game::BORDERS =
{			// coords of the
	-5.0f,	// left border
	5.0f,	// right border
	0.0f,	// bottom border
	10.0f,	// top border
	10.0f	// This is not a coord, it's a size of the box.
};

Game::Game( QGLWidget *parent ) : QGLWidget( parent )
{
	b2Vec2 gravity( 0.0f, -9.8 );
	m_World = new b2World( gravity );


	m_State = STARTING;
    ContinueStepping = true;
}

void Game::initializeGL()
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void Game::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	glColor3f( 0.0f, 0.0f, 0.0f );

    m_Box->Draw();
    m_Panel->Draw();

//	m_Ball->Draw();
//	m_Wall->Draw();
}

void Game::resizeGL( int width, int height )
{
	if ( width <= height )
		glViewport( 0, ( height - width ) / 2, width, width );
	else
		glViewport( ( width - height ) / 2, 0, height, height );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho( BORDERS.left, BORDERS.right, BORDERS.bottom, BORDERS.top, -1.0f, 1.0f );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Game::Start()
{
    m_Box = new Box( ( BORDERS.right + BORDERS.left ) / 2,	// coord of the center of the box.
                     ( BORDERS.top + BORDERS.bottom ) / 2,	// the same
                                             BORDERS.size,  // size of the box
                                                 *m_World );// reference to the current physical world. It's used for creation of the physical body.

    m_Panel = new Panel( BORDERS.size / 5,    // panel's width
                         BORDERS.size / 50,   // panel's height
                         m_Box->GetBody(),
                         *m_World );          // reference to the current physical world*/


///TODO Add initialization of the other graphical objects.
	this->show();
	m_State = PLAYING;
}

void Game::Loop()
{
    float timeStep = 1.0f / 60.0f;
	int velocityIterations = 8;
	int positionIterations = 3;

    while(ContinueStepping==true)
    {   static int count = 0;
        for(b2Body* bodyList = m_World->GetBodyList(); bodyList; bodyList = bodyList->GetNext())
            if( bodyList->IsAwake() == false  &&  bodyList->GetWorldCenter().y > m_Panel->GetBody()->GetWorldCenter().y )
                count++;

        if(count == 0)
            ContinueStepping = false;

        m_World->Step( timeStep, velocityIterations, positionIterations );
        this->updateGL();

    }

/*    static int count = 0;
    for (;count != 2000; ++count) {
        m_World->Step( timeStep, velocityIterations, positionIterations );
        this->updateGL();
    }

   bool finished = false;
    while ( !finished )
	{
		m_World->Step( timeStep, velocityIterations, positionIterations );
		this->updateGL();

		///XXX DEBUG
		static int count = 0;
		for (; count != 10; ++count ) { }
		finished = true;
		///XXX DEBUG

    } */
}

void Game::Stop()
{
	m_State = FINISHING;
/// TODO Add some cool ending of the game.
}
