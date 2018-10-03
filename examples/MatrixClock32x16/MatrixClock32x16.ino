/*
 * Simple Clock for 32x16 Matrices
 * 
 * 2018 D. Puppetti / PLAY-ZONE GmbH
 *
 * info@play-zone.ch / https://www.play-zone.ch
 * 
 */

#include <MdLep16X16.h>
 
MdLep16X16 mdLep(0xFF, 0xFF, 0xFF, 0xFF);// Current 1.3 Boards always init with 0xFF
 
const byte yPos = 4;

void showAscii(byte x, byte y, byte ch)
{
  mdLep.showASCII(x, y, ch);
  delay(100);
}

char ch;
byte h;
byte m;
void setup() {
  h = 12;
  m = 0;
  Serial.begin(9600);
  mdLep.fillGram(0x00);
  delay(100);
}
 
void showClock(void)
{
  if(h < 10) 
  {
    showAscii(0,yPos,' ');
  }
  else 
  {
    showAscii(0,yPos,'1');
  }
  
  showAscii(6,yPos, (h%10) + '0');
  
  showAscii(14,yPos,':');
  showAscii(20,yPos,(m/10)+'0');
  showAscii(26,yPos,(m%10)+'0');
 
  m++;
  if(m > 59)
  {
    m = 0;
    h++;
    if(h > 12) h = 1; 
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  showClock();
  delay(1000);
}
