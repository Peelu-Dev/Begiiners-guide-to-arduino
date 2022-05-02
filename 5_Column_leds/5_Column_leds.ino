#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9


void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<2; i++){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    delay(500);
    }
    digitalWrite(led1,HIGH);
    delay(300);
    digitalWrite(led2,HIGH);
    delay(300);
    digitalWrite(led1,HIGH);
    delay(300);
    digitalWrite(led3,HIGH);
    delay(300);
    digitalWrite(led4,HIGH);
    delay(300);
    digitalWrite(led5,HIGH);
    delay(300);
    digitalWrite(led5,LOW);
    delay(300);
    digitalWrite(led4,LOW);
    delay(300);
    digitalWrite(led3,LOW);
    delay(300);
    digitalWrite(led2,LOW);
    delay(300);
    digitalWrite(led1,LOW);
    delay(300);
    for (int j = 0; j<2; j++){
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led3,HIGH);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      delay(300);
      digitalWrite(led3,LOW);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      delay(300);
      }
}
