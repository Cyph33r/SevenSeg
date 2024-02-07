#include "SevenSeg.h"


SevenSeg::SevenSeg(byte digit_pins[5], byte segment_pins[8], bool common_anode)
{
    Serial.begin(115200);
	this->common_anode = common_anode;
	for (int i = 0; i < 8; ++i)
		this->segment_pins[i] = segment_pins[i];
	for (int i = 0; i < 5; ++i)
		this->digit_pins[i] = digit_pins[i];
	for (int i = 0; i < 5; ++i)
	{
		pinMode(this->digit_pins[i], OUTPUT);
		digitalWrite(this->digit_pins[i], this->common_anode);
	}
		for (int i = 0; i < 8; ++i)
		{
			pinMode(this->segment_pins[i], OUTPUT);
			digitalWrite(this->segment_pins[i], !(this->common_anode));
		}
    
	_0 = 0xfc;
	_1 = 0x60;
	_2 = 0xda;
	_3 = 0xf2;
	_4 = 0x66;
	_5 = 0xb6;
	_6 = 0xbe;
	_7 = 0xe0;
	_8 = 0xfe;
	_9 = 0xe6;
	space = 0x00;
	A = 0xee;
	a = 0xfa;
	b = 0x3e;
	C = 0xbc;
	c = 0x1a;
	d = 0x7a;
	E = 0xbe;
	e = 0xde;
	f = 0x8e;
	g = 0xf6;
	H = 0x6e;
	h = 0x2e;
	i = 0x20;
	J = 0x78;
	j = 0x70;
	L = 0x1c;
	l = 0x0c;
	m = 0xaa;
	n = 0x2a;
	o = 0x3a;
	p = 0xce;
	q = 0xe6;
	r = 0x0a;
	T = 0x8c;
	t = 0x1e;
	U = 0x7c;
	u = 0x38;
	W = 0x7e;
	w = 0x56;
	x = 0x7a;
	y = 0x76;
	und_score = 0x10;
	dash = 0x02;
  equals = 0x12;
	error = 0x92;
	//The digit pins, MSD first
	//The segment pins, segment a first.
}

String SevenSeg::validate(String word)
{
	String disp = "";
  byte length = word.length();
	if (length > 7)
		word = word.substring(0, 7);
	else if(length < 7)
	{
		int fill = 7 - length;
		for (int i = 0; i < fill; ++i)
			word += '*';
	}

	for (int i = 0; i < length; ++i)
	{
		char chr = word.charAt(i);
		if (i == 1 || i == 4)
		{
			if (chr == ':')
				disp += chr;
			else
				disp += '*';
		}
		else
		{
			if (chr == ':')
				disp += '*';
			else
				disp += chr;
		}
	}
	return disp;
}

byte SevenSeg::get_seg(char character)
{
	switch (character)
	{
	case 'D':
	case 'O':
	case '0':
		return _0;
	case 'I':
	case '1':
		return _1;
	case 'Z':
	case 'z':
	case '2':
		return _2;
	case '3':
		return _3;
  case 'Y':
	case '4':
		return _4;
	case 'S':
	case 's':
	case '5':
		return _5;
	case 'G':
	case '6':
		return _6;
	case '7':
		return _7;
	case 'B':
	case '8':
		return _8;
	case '9':
		return _9;
	case 'A':
  	case 'R':
		return A;
	case 'a':
		return a;
	case 'b':
		return b;
	case 'C':
		return C;
	case 'c':
		return c;
	case 'd':
		return d;
	case 'E':
		return E;
	case 'e':
		return e;
	case 'F':
	case 'f':
		return f;
	case 'g':
		return g;
	case 'K':
	case 'H':
		return H;
	case 'k':
	case 'h':
		return h;
	case 'i':
		return i;
	case 'J':
		return J;
	case 'j':
		return j;
	case 'L':
		return L;
	case 'l':
		return l;
	case 'M':
	case 'm':
		return m;
	case 'N':
	case 'n':
		return n;
	case 'o':
		return o;
	case 'P':
	case 'p':
		return p;
	case 'Q':
	case 'q':
		return q;
	case 'r':
		return r;
	case 'T':
		return T;
  	case 'V':
	case 'U':
		return U;
  	case 'v':
	case 'u':
		return u;
	case 'W':
		return W;
	case 'w':
		return w;
	case 'X':
	case 'x':
		return x;
	case 'y':
		return y;
	case '-':
		return dash;
	case '_':
		return und_score;
  	case '=':
    	return equals;
	default:
		return error;
	}
}
void SevenSeg::show(String word, unsigned int duration)
{
	bool colon;
 Serial.println("validating......");
	word = validate(word);
   Serial.println("Done");
    Serial.println("Loooing");
 begin = millis();
	while (millis() - begin <duration)
		int curr_digit = 0;
		for (int j = 7; j > -1; --j)
		{Serial.println(word.length());
       char charac = word.charAt(j);     
			if (charac == ':')
			{
					colon = true;
					continue;
			}
			byte segments = get_seg(charac) + colon;
			for (int k = 0; k < 8; ++k)
				digitalWrite(segment_pins[k], ((bitRead(segments, k)) ^ !common_anode));
			digitalWrite(digit_pins[j], !common_anode);
			delay(5);
			digitalWrite(digit_pins[j], common_anode);
			colon = false;
       ++curr_digit;
		}
	}
    Serial.println("Done");
}