#define LED_PIN  10 // storing pin number 10 inside LED_PIN variable so we can easily identify that we are storing led inside our variable.

#define POTENTIOMETER_PIN A2 // storing pin number 2 inside POTENTIOMETER_PIN variable so we can easily identify that we are storing potentiometer inside our variable.

void setup()
{
  
// Establishing Serial communication to debug our code

  Serial.begin(9600);

  // setting led to output to set the brightness level according to potentiometer

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // reading potentiometer value with the help of analogRead Function

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);//0-1023

  // printing value on serial monitor to debug the code as early as possible

  Serial.println(potentiometerValue);

  // converting potentiometer value 0 -1023 to 0 - 255 to make analog value digital

  int ledBrightness = potentiometerValue / 4 ;//0-255

  // printing value on serial monitor to debug the code as early as possible

  Serial.println(ledBrightness);

  // Glowing led based on the readings from the potentiometer

  analogWrite(LED_PIN,ledBrightness);
}
