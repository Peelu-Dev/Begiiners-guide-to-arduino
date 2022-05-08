// C++ code
//
int LED_PIN = 10;
#define PUSHBUTTON_PIN 2
void setup()
{
  Serial.begin(9600);
  pinMode(PUSHBUTTON_PIN,INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if(digitalRead(PUSHBUTTON_PIN) == HIGH){
    digitalWrite(LED_PIN,HIGH);
    Serial.println("PushButton is pressed and Led is On!");
  }
  else {
    digitalWrite(LED_PIN,LOW);
    Serial.println("PushButton is not pressed and Led is Off!");
  }
}
//
//
