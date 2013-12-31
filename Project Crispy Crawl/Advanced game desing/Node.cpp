#include "Node.h"



Node::Node(int xp, int yp, int d, int p) : dir(8)
{xPos=xp; yPos=yp; level=d; priority=p;}

void Node::updatePriority(const int & xDest, const int & yDest)
{
    priority=level+estimate(xDest, yDest)*10; //A*
}

// give better priority to going straight instead of diagonally
void Node::nextLevel(const int & i) // i: direction
{
        level+=(dir==8?(i%2==0?10:14):10);
}

// Estimation function for the remaining distance to the goal.
int & Node::estimate(const int & xDest, const int & yDest)
{
    static int xd, yd, d;
    xd=xDest-xPos;
    yd=yDest-yPos;         

    // Euclidian Distance
    d=static_cast<int>(sqrt(xd*xd+yd*yd));

    // Manehattan distance
    //d=abs(xd)+abs(yd);
            
    // Chebyshev distance
    //d=max(abs(xd), abs(yd));

    return(d);
}