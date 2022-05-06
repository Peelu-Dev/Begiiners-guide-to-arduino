#define RED_LED  12 // storing pin number 12 inside RED_LED variable for readabilility 

#define YELLOW_LED  11 // storing pin number 11 inside YELLOW_LED variable for readabilility 

#define GREEN_LED  10 // storing pin number 10 inside GREEN_LED variable for readabilility 

void setup()
{
  Serial.begin(9600); //starting serial communication

  pinMode(RED_LED, OUTPUT); // setting red led to output so that it will glow

  pinMode(YELLOW_LED, OUTPUT); // setting yellow led to output so that it will glow

  pinMode(GREEN_LED, OUTPUT); // setting green led to output so that it will glow

  
// Turning off all the leds so that led will not glow at the time of starting

  digitalWrite(RED_LED,LOW); 

  digitalWrite(YELLOW_LED,LOW);

  digitalWrite(GREEN_LED,LOW);
  
}

void loop()
{
  //red signal on for 3 second

  digitalWrite(RED_LED,HIGH); // red led on

// Printing on serial monitor for debugging purpose

  Serial.println("Stop here for 3 seconds so that others vehicles will cross the road");

  digitalWrite(YELLOW_LED,LOW); //yellow led off

  digitalWrite(GREEN_LED,LOW); // green led off

  delay(3000); // wait for 3 second

  //green signal on for 3 second

  digitalWrite(RED_LED,LOW); //red led off

  digitalWrite(YELLOW_LED,LOW); // yellow led off

  digitalWrite(GREEN_LED,HIGH); // green led on

// Printing on serial monitor for debugging purpose

  Serial.println("Move your vehicle for 3 seconds so that your vehicles will cross the road ");

  delay(3000); // wait for 3 seconds

  // yellow signal on for 1 second

  digitalWrite(GREEN_LED,LOW); // green led off 

  digitalWrite(RED_LED,LOW); // red led off

  digitalWrite(YELLOW_LED,HIGH); // yellow led on

// Printing on serial monitor for debugging purpose

  Serial.println("Wait for 1 second because red signal is going to active shortly");

  delay(1000); // wait for 1 second 

  
}
