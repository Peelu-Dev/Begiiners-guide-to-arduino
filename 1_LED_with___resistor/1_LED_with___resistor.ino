// C++ code
//
int ledWithResistor = 12;
void setup()
{
  Serial.begin(9600);
  pinMode(ledWithResistor, OUTPUT);
}

void loop()
{
  Serial.println("Led with resistor On!"); //debugging code
  digitalWrite(ledWithResistor, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  Serial.println("Led with resistor Off!"); //debugging code
  digitalWrite(ledWithResistor, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
