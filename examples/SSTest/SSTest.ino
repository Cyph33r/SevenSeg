#include <SevenSeg.h>
byte digits[5] = {2, 3, 4, 5, 6};
byte segments[8] = {7, 8, 9, 10, 11, 12, 13, A0};
SevenSeg screen(digits, segments, true);
int reading = 0; 
void setup(){
	Serial.begin(9600);
}

void loop(){
   reading = analogRead(A5);
	 Serial.println(reading);
   screen.show( ("R:" + String(reading)), 2500);
   delay(1);
   screen.show("Read", 800);
   delay(1);
 
}
