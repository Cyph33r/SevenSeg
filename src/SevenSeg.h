#ifndef seven_h
#define seven_h
#include <Arduino.h>
class SevenSeg
{
  public:
    
	SevenSeg(byte digit_pins[5], byte segment_pins[8], bool common_anode = true);
	void show(String word, unsigned int duration = 1);

  private:
    
  //Variables
	byte _0;
	byte _1;
	byte _2;
	byte _3;
	byte _4;
	byte _5;
	byte _6;
	byte _7;
	byte _8;
	byte _9;
	byte A;
	byte a;
	byte b;
	byte C;
	byte c;
	byte d;
	byte E;
	byte e;
	byte f;
	byte g;
	byte H;
	byte h;
	byte i;
	byte J;
	byte j;
	byte L;
	byte l;
	byte m;
	byte n;
	byte o;
	byte p;
	byte q;
	byte r;
	byte T;
	byte t;
	byte U;
	byte u;
	byte W;
	byte w;
	byte x;
	byte y;
	byte und_score;
	byte dash;
	byte error;
 byte space;
 byte equals;
	bool common_anode;
 int begin;
    
    
	//Arrays
	byte segment_pins[8];
	byte digit_pins[5];
  
  //Functions
	String validate(String word);
	byte get_seg(char character);
};
#endif