#ifndef WALL_H
#define WALL_H

#include <vector>

#include "brick.h"

class Wall
{
public:
    Wall( float worldSize, b2World *world );
	~Wall();

	void Draw();
private:
	const static int NUMBER_OF_BRICKS;	// Definition is in the beginning of the wall.cpp
    std::vector<Brick> m_Bricks;

};

#endif // WALL_H
