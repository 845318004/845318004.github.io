#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件


#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
//定义彩灯引脚以及数量

#define Light_PIN A0

#define Light_value1 50
#define Light_value2 600
/*------------音符对应蜂鸣器频率------------*/

#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

#define buzzer_pin 8 //定义蜂鸣器引脚

/*------------定义歌曲音调的数组------------*/

int notes[] = {
  C5, C5, G5, G5, A5, A5, G5, F5, F5, E5, E5, D5, D5, C5, G5, G5, F5, F5, E5, E5, D5, G5, G5, F5, F5, E5, E5, D5, C5, C5, G5, G5, A5, A5, G5, F5, F5, E5, E5, D5, D5, C5
};

int sensorValue;

/*------------定义歌曲节奏的数组------------*/

byte beats[] = {
  100, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 200
};

void setup() {
  pinMode(buzzer_pin, OUTPUT); //定义蜂鸣器引脚为输出状态

  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  sensorValue = analogRead(Light_PIN);
  Serial.println(sensorValue);
  if (sensorValue < Light_value1)
    {colorWipe(strip.Color(0, map(sensorValue, 10, 400, 0, 255), 0));
      for ( int i = 0; i < 42; i++) {

    /*------------设置i在歌曲长度内递增，这样就能逐一执行数组中的数据------------*/

    if (notes[i] != 0)tone(buzzer_pin, notes[i]); //播放音乐
    delay(4 * beats[i]); //播放间隔

    noTone(buzzer_pin);
    delay(10);
  }}
  else if (sensorValue >= Light_value1 && sensorValue < Light_value2)
    colorWipe(strip.Color(0, 0, map(sensorValue, 400, 800, 0, 255)));
  else if (Light_value2 >= 600)
    colorWipe(strip.Color(map(sensorValue, 800, 960, 0, 255), 0, 0));
}

void colorWipe(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}



