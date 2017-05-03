#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件
#include <Servo.h>  //调用舵机库文件

Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);
//定义彩灯引脚以及数量
Servo myservo;  //定义舵机名称

int sstate; //定义一个整数变量state
int lstate;
int i;

void setup()
{
  ColorLED.begin();
  pinMode(A0, INPUT); //设置光敏传感器引脚为输入状态
  pinMode(A2, INPUT); //设置MIC传感器引脚为输入状态
  myservo.attach(4);  //设置舵机引脚
  Serial.begin(9600); //设置串口波特率为9600
}
void loop() {
  sstate = analogRead(A2);
  lstate = analogRead(A0);


  if (lstate < 50 && sstate > 700) {
    ColorLED.setPixelColor(0, ColorLED.Color(255, 0, 0));  //设置彩灯颜色为红色
    ColorLED.show();  //显示彩灯效果
    delay(4000); //持续4秒
    myservo.write(180);
    delay(1000);  //保持1秒(1000毫秒)
    myservo.write(0);  //将i的值付给舵机
    delay(1000);  //保持1秒(1000毫秒)

  } else { //否则，关灯
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //设置彩灯颜色为红色
    ColorLED.show();  //显示彩灯效果
  }
}
