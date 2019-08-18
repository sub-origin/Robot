//www.elegoo.com
/*****************************/
/* メインプログラム            */
/*****************************/

/*外部ファイル読み込み */
#include <Servo.h>  //servo library
#include "iodefine.h"
#include "RobotAPI.h"

/* グローバル変数 */
int middleDistance=0;
unsigned char main_counter=0;
Servo myservo;      // create servo object to control servo

/* 関数定義 */
void setup() { 
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LT_R,INPUT);
  pinMode(LT_M,INPUT);
  pinMode(LT_L,INPUT);
  myservo.write(90);  //setservo position according to scaled value
} 

void loop() { 
    if(main_counter < 100){
      main_counter++;  
    } else {
      main_counter = 1;
    }
    main_func(main_counter);
    delay(10);  /* 10ms wait */
}

/*** メイン関数 ***/
void main_func(unsigned char cnt){

  unsigned char robodir=STOP;
  unsigned char robospd=0;

  if (cnt == 0){
/***** 初回処理 ******/

/*******************/
  }
  if( cnt%10 == 1 ) {
/***** 100ms毎処理 *****/
  middleDistance = Distance_test();
  Serial.println(middleDistance);
/**********************/    
  }
  if ( cnt == 100 ){
/***** 1000ms毎処理 *****/

/***********************/
  }
/***** 10ms毎処理 *****/
  if( middleDistance < 20 ){ /* 壁がある */
    robodir = STOP;
  } else { /* 壁ないよ */
      if(LT_M){
        robodir = FORWARD;
        robospd = 100;
      } else if(LT_R){
        robodir = RIGHT;
        robospd = 200;
      } else if(LT_L){
        robodir = LEFT;
        robospd = 200;
      } else {
        robodir = BACK;
        robospd = 80;
      }
  }

  robot_drive(robodir,robospd);
/*********************/
}
