
int LED_PIN = 10; // storing pin number 10 inside LED_PIN variable so we can easily identify that we are storing led inside our variable.

#define PUSHBUTTON_PIN 2 // storing pin number 2 inside PUSHBUTTON_PIN variable so we can easily identify that we are storing push button inside our variable.

void setup()
{

// Establishing Serial communication to debug our code
  Serial.begin(9600);

// setting push button to input to read the data from push button
  pinMode(PUSHBUTTON_PIN,INPUT);

// led to output to turn on and off based on push button pin input
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{

// Turning on led whenever we press the push button pin
  if(digitalRead(PUSHBUTTON_PIN) == HIGH){ // using if condition to read the push button state

    digitalWrite(LED_PIN,HIGH); // turning on led if push button is pressed

    Serial.println("PushButton is pressed and Led is On!"); // debugging with Serial.println function 


  }
  else {

    digitalWrite(LED_PIN,LOW); // turning off led using else statement when push button is not pressed

    Serial.println("PushButton is not pressed and Led is Off!");  // debugging with Serial.println function 

  }
}
