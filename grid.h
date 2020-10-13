#ifndef GRID_H
#define GRID_H

int rows[] = {2, 3, 4, 5, 6, 7, 8, 9};
int cols[] = {0b01111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b111111101, 0b11111110 };

class Grid{

private:

    int width;

    int height;

    bool buff[8][8];

public:

    Grid()
    :
    width(8),
    height(8)
    {

      for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){

          buff[y][x] = false;
        }
      }
    }

    void cleanFrame(){

      for (int y = 0; y < height; ++y){

        //digitalWrite(rows[y], LOW);
        
        for (int x = 0; x < width; ++x){

          buff[y][x] = false;
        }
      }
    }
    
    void drawFrame(){

        for (int y = 0; y < height; ++y){

          byte col = 0xFF;

          byte temp = 0b10000000;
  
          for (int x = 0; x < width; ++x){
  
            if (buff[y][x] == true )
              col = col - temp;
              
            temp = temp >> 1;
          }

          digitalWrite(LATCH, LOW);

          digitalWrite(rows[y], HIGH);

          shiftOut(DATA, CLOCK, LSBFIRST, col);
      
          digitalWrite(LATCH, HIGH);

          delay(2);

          digitalWrite(LATCH, LOW);

          digitalWrite(rows[y], LOW);

          shiftOut(DATA, CLOCK, LSBFIRST, 0xFF);
      
          digitalWrite(LATCH, HIGH);
        }
    }

    void printPixel(int x, int y){

        buff[y][x] = true;
      }
};

#endif
