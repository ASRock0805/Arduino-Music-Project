#include "pitches.h"

int melody[] = {
	E5, F5, G5, A5,
	E5, D5, C5,
	F5, G5, A5, C6, B5, A5,
	G5, G4,

	C5, E5, G5, C5,
	B4, E5, G5, 0, G5,
	A5, B5, C6, A5,
	G5, E5, D5,

	C5, C5, C5, E5, D5,
	C5, C5, C5, D5, E5,
	D5, C5, A4, E5,
	D5, G4,
	//1
	C5, E5, G5, C5,
	B4, E5, G5, 0, G5,
	A5, B5, C6, A5,
	G5, E5, D5,

	C5, C5, C5, E5, D5,
	C5, C5, C5, D5, E5,

	D5, A4, B4, C5, D5,
	C5, G5,
	E5, D5, C5, G5,
	B4, A4, B4,

	A4, B4, A4, G4,
	E5, G5,
	E5, D5, C5, G5,
	B4, A4, B4,

	C5, C5, C5, D5, E5,
	D5, G5,
	//2
	C5, E5, G5, C5,
	B4, E5, G5, 0, G5,
	A5, B5, C6, A5,
	G5, E5, D5,

	C5, C5, C5, E5, D5,
	C5, C5, C5, D5, E5,

  D5, A4, B4, C5, D5,
  C5,
  
};

float Durations[] = {
	0.5, 0.5, 1 + 1, 1,
	0.5, 0.5, 1 + 1 + 1,
	0.5, 0.5, 1 + 1, 0.5, 0.5, 0.5,
	1 + 1 + 1, 1,

	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 1 + 1, 0.5, 0.5,
	
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1, 1,
	1 + 1 + 1, 1,
	//1
	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 1 + 1, 0.5, 0.5,
	
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,

	1 + 0.5, 0.5, 1, 0.25, 0.25,
	1 + 1 + 1, 1,
	1 + 0.5, 0.5, 1, 1,
	1 + 1 + 1, 0.5, 0.5,
	
	1 + 0.5, 0.5, 1, 1,
	1 + 1 + 1, 1,
	1 + 0.5, 0.5, 1, 1,
	1 + 1 + 1, 0.5, 0.5,

	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 1 + 1, 1,
	//2
	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1 + 0.5, 0.5,
	1 + 1 + 1, 0.5, 0.5,
	
	1 + 0.5, 0.5, 1, 0.5, 0.5,
	1 + 0.5, 0.5, 1, 0.5, 0.5,

  1 + 0.5, 0.5, 1 + 0.5, 0.25, 0.25,
  1 + 1 + 1 + 1,
	
};

int ledPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

int sp = 13;
int length;
int ledCount; 

void setup() { // 初始設定區塊
	pinMode(sp, OUTPUT); // 將 sp 腳位設為輸出
	length = sizeof(melody) / sizeof(melody[0]); //計算 melody 陣列大小
	ledCount = sizeof(ledPins) / sizeof(ledPins[0]); //計算 ledpins 陣列大小
}

void loop() {  //循環區塊
	for (int thisLed = 0; thisLed < ledCount; thisLed = thisLed + 1) {
		pinMode(ledPins[thisLed], OUTPUT);
	}

	for (int thisNote = 0; thisNote < length; thisNote = thisNote + 1) { //音符迴圈，循環範圍為 length
		tone(sp, melody[thisNote]);   //tone(腳位, 頻率)。  播放該腳位對應之頻率音符		
		
		int i;
		switch (melody[thisNote]) {
			case G4:
				i = 0 ;
				break;
			case A4:
				i = 1 ;
				break;
			case B4:
				i = 2 ;
				break;
			case C5:
				i = 3 ;
				break;
			case D5:
				i = 4 ;
				break;
			case E5:
				i = 5 ;
				break;
			case F5:
				i = 6 ;
				break;
			case G5:
				i = 7 ;
				break;
			case A5:
				i = 8 ;
				break;
			case B5:
				i = 9 ;
				break;
			case C6:
				i = 10 ;
				break;
        }

        digitalWrite(ledPins[i], HIGH);
        delay(Durations[thisNote] * 400);
        digitalWrite(ledPins[i], LOW);
        delay(Durations[thisNote] * 400); // 每個音之持續時間
        noTone(sp); // 停止腳位當前之音符
	}
	delay(3000); // 等待3.0秒
}
