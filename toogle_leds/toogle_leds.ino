// C++ code
//

//#define led1 12
#define led1 11
#define led2 10

#define BUTTON_PIN 2

int toggleLedState = 1;


unsigned long lastTimeButtonChange = millis();
unsigned long debounceDelay = 50;
byte buttonState =  LOW;


void toggleOtherLeds(){
  if(toggleLedState == 1){
    toggleLedState = 2;
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
  else{
     toggleLedState = 1;
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }
    
}




void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
  buttonState = digitalRead(BUTTON_PIN);
}






void loop()
{
  unsigned long timeNow = millis(); //current time
  
  // toggle led 2 and 3 when the button is pressed
  if(timeNow - lastTimeButtonChange > debounceDelay){
    byte newButtonState = digitalRead(BUTTON_PIN);
    if(newButtonState != buttonState){
      lastTimeButtonChange = timeNow;
      buttonState = newButtonState;
      if(buttonState == HIGH){
       toggleOtherLeds(); 
      }
    }
  }
  
}
