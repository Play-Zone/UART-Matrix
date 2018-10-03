/*
   Hello World for 32 x 16 Matrices

   2018 D. Puppetti / PLAY-ZONE GmbH

*/
#include <MdLep16X16.h>

MdLep16X16 mdLep(0xFF, 0xFF, 0xFF, 0xFF);// Current 1.3 Boards always init with 0xFF

void showAscii(byte x, byte y, byte ch)
{
  mdLep.showASCII(x, y, ch);
  delay(100);
}

void setup() {
  Serial.begin(9600);
  mdLep.fillGram(0x00);
  delay(100);
  showAscii(0, 8, 'H');
  showAscii(6, 8, 'e');
  showAscii(12, 8, 'l');
  showAscii(16, 8, 'l');
  showAscii(20, 8, 'o');
  showAscii(0, 0, 'W');
  showAscii(6, 0, 'o');
  showAscii(11, 0, 'r');
  showAscii(16, 0, 'l');
  showAscii(21, 0, 'd');
  showAscii(27, 0, '!');
}

void loop() {
}