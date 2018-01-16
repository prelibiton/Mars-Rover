#include <Servo.h>

#define S0 8
#define S1 9
#define S2 11
#define S3 10
#define sensorOut 12

Servo myservo2;  // create servo object to control a servo
Servo myservo3;

Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;

int frequency = 0;
int red = 0;
int green = 0;
int blue = 0;
bool turnLeft = true;
bool leap = true;

void leap_forward(){
  calculate();
      //delay(15);
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
   stop();
  }
    for(int i = 0; i < 2; i++){
      myservo2.write(110);
      myservo3.write(70);
      delay(50);
     }
     
  turn_around();
}
void turn_around(){
  myservo5.write(135);
  myservo7.write(45);  
  myservo6.write(135);
  myservo4.write(45);
  for(int i = 0; i < 40; i ++){
    calculate();
      //delay(15);
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
    myservo2.write(70);
    myservo3.write(70);
  }
  if(leap){
    leap = false;
    leap_forward();
  }
  else{
    go_straight();
  }
}

void go_left(){
  go_back();
}
void go_straight(){
  calculate();
      //delay(15);
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
  else if((red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
      if(turnLeft){
        //turnLeft = false;
        go_left();
      }
    }
  myservo5.write(90);
  myservo7.write(95);
  myservo6.write(89);
  myservo4.write(90);

  myservo2.write(100);
  myservo3.write(80);
}

void go_back(){
  //calculate();
      //delay(15);
  //if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
  //  stop();
  //}
    for(int i = 0; i < 2; i++){
      myservo2.write(70);
      myservo3.write(110);
      delay(200);
     }
  myservo2.write(70);
  myservo3.write(70);
  delay(250);
  turn_around();
}

void stop(){
  while(1){
     //myservo2.write(90);
     //myservo3.write(90);
     myservo2.detach();
     myservo3.detach();
  }
}

void calculate(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  red = frequency;
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
  else if((red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
      if(turnLeft){
        //turnLeft = false;
        go_left();
      }
    }
  //delay(10);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  green = frequency;
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
  else if((red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
      if(turnLeft){
        //turnLeft = false;
        go_left();
      }
    }
  //delay(10);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  blue = frequency;
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
  else if((red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
      if(turnLeft){
        //turnLeft = false;
        go_left();
      }
    }
  //delay(10);
}
void setup() {
  myservo2.attach(2);
  myservo3.attach(3);

  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6);
  myservo7.attach(7);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
  
  //myservo4.write(8);
}

void loop() {
  calculate();
      //delay(15);
  if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)){
    stop();
  }
  else if((red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
      if(turnLeft){
        //turnLeft = false;
        go_left();
      }
    }

   /*
  for(int i = 0; i <= 20; i++){
      calculate();
      //delay(15);
      if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950){
        stop();
      }
      else if(red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
        turn_around();
      }
      go_straight();
  }*/

  go_straight();
}
    /*for(int j = 0; j <= 20; j++){
      calculate();
      //delay(15);
      if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)  ||
  (red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
        stop();
      }
      turn_around();
  }*/
    
    /*for(int i = 0; i <= 20; i++){
      calculate();
      //delay(15);
      if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)  ||
  (red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
        stop();
      }
      go_straight();
    }
    for(int j = 0; j <= 20; j++){
      calculate();
      //delay(15);
      if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)  ||
  (red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
        stop();
      }
      turn_around();
    }
    for(int i = 0; i <= 20; i++){
      calculate();
      //delay(15);
      if((red >= 250 && red <= 390) && (green >= 900 && green <= 1400) && (blue >= 550 && blue <= 950)  ||
  (red >= 600 && red <= 980) && (green >= 650 && green <= 1100) && (blue >= 450 && blue <= 750)){
        stop();
      }
      go_straight();
    }
}
  //myservo2.write(80);
  //myservo3.write(100);
  

  //myservo4();
  //myservo5();
  //myservo6();
  //myservo7();
  //for(int i = 0; i < 180; i++){
    //myservo4.write(i); 
    //myservo5.write(i);
    //myservo6.write(i);
    //myservo7.write(i);
    //delay(15);// waits for the servo to get there
  //}*/
 

