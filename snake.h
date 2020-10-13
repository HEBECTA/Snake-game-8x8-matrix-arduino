#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"
#include "food.h"

class Snake{

  private:

      class Segment{

         private:

            float x;
            float y;
            
         public:

            bool operator==(Segment &s){

              if ( this->x == s.x && this->y == s.y )
                return true;

              return false;
            }

            float getX()const {return x;}

            float getY() const {return y;}

            void draw(Grid &g) const{

              g.printPixel(x, y);
            }

           void set(int x_, int y_){

            x = x_;
            y= y_;
           }

           void move(int x_d, int y_d){

              if ( x_d > 0 )
                ++x;
    
              else if ( x_d < 0 )
                --x;

              else if ( y_d > 0 )
                ++y;

              else if ( y_d < 0 )
                --y;

              if ( x > 7 )
                x = 0;
                  
              else if ( x < 0)
                x = 7;
                   
              if ( y > 7 )
                 y = 0;
                  
              else if ( y < 0 )
                 y = 7;   
          }
      };

      Segment segments[64];

      int size;

      float time_to_move;

      int x_d;
      int y_d;

  public:

      void initialize(){
        
        size = 3;

        segments[0].set(3, 3);
        segments[1].set(3, 2);
        segments[2].set(3, 1);

        x_d = 0;
        y_d = 1;

        time_to_move = 0;
        }

      void draw(Grid &g) const{

        for(int i = 0; i < size; ++i){

          segments[i].draw(g);
        }
     }

     void move(float speed){

          time_to_move += speed;

          if (time_to_move > 0 ){

            for (int i = size - 1; i > 0; --i){
  
              segments[i] = segments[i-1];
            }
  
            segments[0].move(x_d, y_d);

            time_to_move = -1;
          }
     }

     void turn(int x, int y){

        if ( x + x_d != 0 || y + y_d != 0){
          
          x_d = x;
  
          y_d = y;
        }
     }

     void grow(){

      segments[size] = segments[size - 1]; 

      ++size;
     }

     bool eating(Food &f) const {

      if (f.getX() == (int)segments[0].getX() && f.getY() == (int)segments[0].getY())
        return true;

      else
        return false;
     }

     bool eatingMyself(){

      for (int i = 1; i < size; ++i){

        if (segments[0] == segments[i] )
            return true;
      }

      return false;
     }
      
};

#endif
