#ifndef GAME_H
#define GAME_H

#include <QtOpenGL/QGLWidget>
#include <Box2D/Box2D.h>

#include "ball.h"
#include "panel.h"
#include "wall.h"
#include "box.h"

class Game : public QGLWidget
{
public:
	Game( QGLWidget* parent = NULL );

/// An every graphical object should be initialized in this method.
///TODO Also these three methods should be private.
	void Start();
	void Loop();
	void Stop();

	enum GameState
	{
		STARTING = 0,
		PLAYING = 1,
		FINISHING = 2
	};

	struct Border
	{
		float left;
		float right;
		float bottom;
		float top;
		float size;
	};

private:
// TODO Implement
	void initializeGL();
	void resizeGL( int width, int height );
	void paintGL();

private:

	Ball* m_Ball;
	Panel* m_Panel;
	Wall* m_Wall;
	Box* m_Box;
    Brick* m_Brick;

	b2World* m_World;

	GameState m_State;

    bool ContinueStepping;

	static const Border BORDERS; // You can find the definition at the beginning of the game.cpp
};

#endif // GAME_H
