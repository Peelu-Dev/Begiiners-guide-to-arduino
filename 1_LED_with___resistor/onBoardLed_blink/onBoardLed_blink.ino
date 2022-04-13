#define onBoardLed 13
void setup() {
  // put your setup code here, to run once:
  pinMode(onBoardLed,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(onBoardLed,HIGH);
  delay(500);
  digitalWrite(onBoardLed,LOW);
  delay(1000);
}
