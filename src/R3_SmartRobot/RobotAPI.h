/*******************************************************/
/*  移動関数                                            */
/*    <引数>                                           */
/*      dir    : 移動方向                               */
/*      carspd : 移動速度 (0~255)                       */
/*              ※旋回時は、150以上推奨                   */
/*    <戻り値>　　なし                                   */
/*******************************************************/
/*　移動方向定義 */
#define FORWARD 0x00 /* 前進 */
#define BACK    0x01 /* 後退 */
#define LEFT    0x02 /* 左旋回 */
#define RIGHT   0x03 /* 右旋回 */
#define STOP    0x04 /* 停止 */

void robot_drive(unsigned char dir,unsigned char carspd){
  switch(dir){
    case FORWARD:
      analogWrite(ENA, carspd);
      analogWrite(ENB, carspd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
//      Serial.println("go forward!");
      break;
    case BACK:
      analogWrite(ENA, carspd);
      analogWrite(ENB, carspd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
//      Serial.println("go back!");
      break;    
    case LEFT:
      analogWrite(ENA, carspd);
      analogWrite(ENB, carspd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
//      Serial.println("go left!");
      break;
    case RIGHT:
      analogWrite(ENA, carspd);
      analogWrite(ENB, carspd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW); 
//      Serial.println("go right!");
      break;
    case STOP:
    default:
       digitalWrite(ENA, LOW);
       digitalWrite(ENB, LOW);
//       Serial.println("Stop!");
       break;
  }
}

/**********************/
/* 超音波センサ 取得    */
/**********************/
//Ultrasonic distance measurement Sub function
int Echo = A4;  
int Trig = A5;
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}

/**********************/
/* ラインセンサ 取得    */
/**********************/
#define LT_R !digitalRead(10)
#define LT_M !digitalRead(4)
#define LT_L !digitalRead(2)
