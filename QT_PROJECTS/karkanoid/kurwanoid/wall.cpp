#include "wall.h"
#include<algorithm>

const int Wall::NUMBER_OF_BRICKS = 32;

Wall::Wall(float worldSize, b2World *world)
{
//   b2World *tempWorld = &world;
//    *tempWorld = world;
    m_Bricks.reserve( NUMBER_OF_BRICKS * sizeof( Brick ) );

    float startX = -worldSize / 5;
    float startY = worldSize / 2 + worldSize/20;
    for(int j=0; j<NUMBER_OF_BRICKS / 4; j++)
        for(int i=0; i<NUMBER_OF_BRICKS / 8; i++)
        {
            Brick* oneBrick = new Brick(startX + j*worldSize/18, startY + i*worldSize/15, worldSize/30, world);
            m_Bricks.push_back(*oneBrick);
        }
///TODO Initialize the vector of bricks with the world variable.*/
}

Wall::~Wall()
{

}
void Wall::Draw()
{

    for(std::vector<Brick>::iterator iter = m_Bricks.begin(); iter != m_Bricks.end(); ++iter)
    {
        iter->Draw(); //оце не паше
    }

}
