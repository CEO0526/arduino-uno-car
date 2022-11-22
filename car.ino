int analogPinL = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
int analogPinC = A1;
int analogPinR = A2;
int L = 0;  // variable to store the value read
int C = 0;
int R = 0;

 int intSpeed=80;


void backward() {
     Serial.print("front");
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH); }
void forward() {
     Serial.print("back");
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW); }
void turnRight() {
     Serial.print("right");
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW); }
void turnLeft() {
   Serial.print("left");
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH); }
 
void stop_() {
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW); }

void setup() {
  Serial.begin(9600);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT); 
;
 }


void track(){
    L=analogRead(A0);
  C=analogRead(A1);
  R=analogRead(A2);

  Serial.print("L:");
  Serial.print(L);
  Serial.print("\tC:");
  Serial.print(C);
  Serial.print("\tR:");
  Serial.println(R);
  
}

 

void lineTrack(){
  L=analogRead(A0);
  C=analogRead(A1);
  R=analogRead(A2);

  Serial.print("L:");
  Serial.print(L);
  Serial.print("\tC:");
  Serial.print(C);
  Serial.print("\tR:");
  Serial.println(R);
  
  if((L>=500)&&(R>=500)&&(C>=500)){
    forward();
    delay(5);
  L=analogRead(A0);
  C=analogRead(A1);
  R=analogRead(A2);
  }else if ((L<=100)&&(C>=200)){
    {
      backward();
      delay(700);
      turnRight();
      delay(800);
      
  L=analogRead(A0);
  C=analogRead(A1);
  R=analogRead(A2);
    }
//  }
//}else if((L>=100)&&(C<=100)&&(R<=100)){
//  {
//    turnLeft();
//    delay(5);
//  L=analogRead(A0);
//  C=analogRead(A1);
//  R=analogRead(A2);
//  }
//}else if ((L<=500)&&(C<=500)&&(R<=500)){
//  turnRight();
//  L=analogRead(A0);
//  C=analogRead(A1);
//  R=analogRead(A2);
//}else{
//  backward();
//  delay(500);
//  turnRight();
//  delay(300);
  }else{
    backward();
    
  }
}


void loop() {
      track();
      lineTrack();
  // put your main code here, to run repeatedly:  
}
  
