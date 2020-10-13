#define DATA 10
#define CLOCK 12
#define LATCH 11

#define BTN 0
#define X A1
#define Y A0

#define SPEED A3

#include "grid.h"
#include "snake.h"
#include "food.h"

Grid g;
Snake snake;
Food food;

float speed = 0.05;

void setup() {

  Serial.begin(115200);

  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  pinMode(BTN, INPUT);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);

  pinMode(SPEED, INPUT);

  digitalWrite(CLOCK, LOW);

  for(int i = 0; i < 8; ++i){

    pinMode(rows[i], OUTPUT);
    //digitalWrite(rows[i], LOW);????????????
  }

 snake.initialize();

 food.spawn();
}

void loop() {

      g.cleanFrame();

      int read =analogRead(SPEED);

      if (read < 350 )
        speed = 0.009;

      else if (read >= 350 && read < 500)
        speed = 0.02;

      else if (read >= 500 && read < 700)
        speed = 0.05;

      else if (read >= 700)
        speed = 0.1;
    
      if ( analogRead(X) > 650){

        snake.turn(1, 0);
      }
    
      else if ( analogRead(X) < 450 ){

        snake.turn(-1, 0);
      }

      else if ( analogRead(Y) > 650){

        snake.turn(0, -1);
      }
    
      else if ( analogRead(Y) < 450 ){

        snake.turn(0, 1);
      }
      
      snake.move(speed);

      if ( snake.eating(food) ){
        
        snake.grow();
        
        food.spawn();
      }

      if (snake.eatingMyself())
        snake.initialize();
      
     snake.draw(g);

     food.draw(g);
      
     g.drawFrame();
}
