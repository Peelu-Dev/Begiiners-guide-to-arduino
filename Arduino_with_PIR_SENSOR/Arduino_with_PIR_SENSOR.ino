#define LED_PIN 13 // storing pin number 13 inside LED_PIN variable so we can easily identify that we are storing led inside our variable.


#define PIR_PIN 2 // storing pin number 2 inside PIR_PIN variable so we can easily identify that we are storing motion sesnor signal pin inside our variable.


void setup() {

  // put your setup code here, to run once:
 // setting led to output to turn on the led when motion is detected by sensor
  pinMode(LED_PIN,OUTPUT);

// Setting PIR motion sensor to INPUT to detect motion around sensor
  pinMode(PIR_PIN,INPUT);

// Establishing Serial communication to debug our code
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:

// reading motion sensor value with digitalRead function and storing inside pirValue variable
  int pirValue = digitalRead(PIR_PIN);


  // printing value on serial monitor to debug the code as early as possible
  Serial.println(pirValue);

// Using if condition to turn on the led when motion is detected
  if(pirValue == 1)

  {

// turning on led if motion is detected 
    digitalWrite(LED_PIN,HIGH);

// Giving 50 milli seconds delay after motion detected
    delay(50);

  }

// Using else condition to turn off the led when motion is not detected
  else

  {

// turning off led if motion is not detected 
    digitalWrite(LED_PIN,LOW);

  }
}
