#ifndef FOOD_H
#define FOOD_H

#include "grid.h"

class Food{

  private:

    int x, y;


  public:

    void spawn(){

        x = random(0, 7);
        
        y = random(0, 7);
    }

    int getX(){return x;}

    int getY(){return y;}

    void draw(Grid &g) const{

      g.printPixel(x, y);
    }
  
};

#endif
