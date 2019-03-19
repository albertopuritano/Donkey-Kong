#include "Matrix.hpp"
#include <iostream>
using namespace std;
class Entity
{
private:
    int x;
    int y;
    int matX;
    int matY;
public:
    Entity(int a, int b):x(a),y(b){}
    int getX(){return x;}
    int getY(){return y;}
    void MoveUp()
    {
        if (griglia[(x/20)-1][y/20]==1)
        {
            x-=10;
            return;
        }
        else if (griglia[(x/20)-1][y/20]==2)
        {
            x/=20;
            x-=2;
            x*=20;
        }
    }
    void MoveDown()
    {
        if (griglia[(x/20)+1][y/20]==1)
        {
            x+=10;
            return;
        }
        else if (griglia[(x/20)+1][y/20]==2 and griglia[(x/20)+2][y/20]==1)
        {
            x/=20;
            x+=2;
            x*=20;
        }
    }
    void MoveLeft()
    {
        if (griglia[(x/20)+1][y/20]!=1 and griglia[(x/20)+1][(y/20)-1]==2)
            y-=5;
    }
    void MoveRight()
    {
        if (griglia[(x/20)+1][y/20]!=1 and griglia[(x/20)+1][(y/20)+1]==2)
            y+=5;
    }
    void reset(){}
};


class Player: public Entity
{
public:
    Player():Entity(520,180){}
};


class Barrel:public Entity
{
private:
    int init_x;
    int init_y;
public:
    Barrel():Entity(init_x,init_y){}
};