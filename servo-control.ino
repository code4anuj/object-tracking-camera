#include<Servo.h>

Servo x, y;
int width = 640, height = 480;
int xpos = 90, ypos = 90;  //for intial position.
void setup() {

  Serial.begin(9600);
  x.attach(9);
  y.attach(10);
  x.write(xpos);
  y.write(ypos);
}
const int theta = 5; 
                                // have to try to blink LED when reach unde r
void loop() {
  if (Serial.available() > 0)
  {
    int fcenterX, fcenterY;
    if (Serial.read() == 'X')
    {
      fcenterX = Serial.parseInt();
      if (Serial.read() == 'Y')
        fcenterY = Serial.parseInt(); 
    }

    if (fcenterX > width / 2 + 30)
      xpos += theta;
    if (fcenterX < width / 2 - 30)
      xpos -= theta;
    if (fcenterY < height / 2 + 30)
      ypos -= theta;
    if (fcenterY > height / 2 - 30)
      ypos += theta;


    // if the servo degree is outside its range...just to handle exception.
    if (xpos >= 180)
      xpos = 180;
    else if (xpos <= 0)
      xpos = 0;
    if (ypos >= 180)
      ypos = 180;
    else if (ypos <= 0)
      ypos = 0;

    x.write(xpos);
    y.write(ypos);

  }
}
