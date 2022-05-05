#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#include <WiFi.h>         //Including wifi.h library it will take care of all wifi related task
#include <HTTPClient.h>   //Including HTTPClient.h library to use all api


#define BLYNK_PRINT Serial
// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
#define DHTPIN 13 

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

char auth[] =  "dByjRjRFbHivqzDIjNdUFSDdFswx3sAB"; //BLYNK_AUTH_TOKEN;

const char* ssid = "JioFiber-YfDLr";             //Add your WiFi ssid
const char* pass =  "jio@12345";    //Add your WiFi password

String apiKey = "621699";    //361111         //Add your Token number that bot has sent you on signal messenger
String phone_number = "+919407327288"; //Add your signal app registered phone number (same number that bot send you in url)

String url;//url String will be used to store the final generated URL



#define ldrPin 34
#define flameSensor 12
#define motion_sensor 14

/* Change these values based on your calibration values */
int lowerThreshold = 420;
int upperThreshold = 520;

// Sensor pins
#define sensorPower 27
#define sensorPin 34


// Value for storing water level
int val = 0;

void photoresistor()
{
 int sensorValue = analogRead(ldrPin)/4;
 Serial.print("ldr Value is :");
 Serial.println(sensorValue);
 delay(1000);
 Blynk.virtualWrite(V2,sensorValue );

 if(sensorValue >= 650)
 {
   message_to_signal("Night detected: turn on your lights");
 }
}

void temperatureAndHumidity()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);

  if(t > 35)
  {
    message_to_signal("Temperature above 35 degree celcius:Grow plants to decrease temperature level");
  }
}

void flame()
{
  int flameValue = digitalRead(flameSensor);  
  if(flameValue == HIGH)
  {
    Serial.println("Fire Detected!");
    message_to_signal("Fire Detected");
    delay(100);
  }
}

void motionsensor()
{
 int sensorValue = digitalRead(motion_sensor);
 Serial.println(sensorValue);

 if(sensorValue == HIGH)
 {
  message_to_signal("Motion detected!");
  delay(1000);
 }
 else
 {
  Serial.println("Motion not detected!");
  delay(1000);
 }
}

int readSensor() {
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}

void water_level()
{
   int level = readSensor();

  if (level == 0) {
    Serial.println("Water Level: Empty");
  }
  else if (level > 0 && level <= lowerThreshold) {
    Serial.println("Water Level: Low");
  }
  else if (level > lowerThreshold && level <= upperThreshold) {
    Serial.println("Water Level: Medium");
    
  }
  else if (level > upperThreshold) {
    message_to_signal("Water Level: High");
  }
  delay(1000);
}


void setup() 
{
  Serial.begin(115200);
  pinMode(motion_sensor,INPUT); 
  delay(60*1000); // takes 1 minute to activate motion sensor
  digitalWrite(motion_sensor,LOW);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);

  WiFi.begin(ssid, pass);// Try to connect with the given SSID and PSS
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {  // Wait until WiFi is connected
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to the WiFi network"); // Print wifi connect message

  
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  // Setup a function to be called every second
  timer.setInterval(1000L,temperatureAndHumidity);
}

void loop()
{
  //loop will do nothing for this example
  motionsensor();
  photoresistor();
  flame();
  water_level();
  Blynk.run();
  timer.run();
}


void  message_to_signal(String message)       // user define function to send meassage to Signal app
{
  //adding all number, your api key, your message into one complete url
  url = "https://api.callmebot.com/signal/send.php?phone=" + phone_number + "&apikey=" + apiKey + "&text=" + urlencode(message);

  postData(); // calling postData to run the above-generated url once so that you will receive a message.
}

void postData()     //userDefine function used to call api(POST data)
{
  int httpCode;     // variable used to get the responce http code after calling api
  HTTPClient http;  // Declare object of class HTTPClient
  http.begin(url);  // begin the HTTPClient object with generated url
  httpCode = http.POST(url); // Finaly Post the URL with this function and it will store the http code
  if (httpCode == 200)      // Check if the responce http code is 200
  {
    Serial.println("Sent ok."); // print message sent ok message
  }
  else                      // if response HTTP code is not 200 it means there is some error.
  {
    Serial.println("Error."); // print error message.
  }
  http.end();          // After calling API end the HTTP client object.
}

String urlencode(String str)  // Function used for encoding the url
{
    String encodedString="";
    char c;
    char code0;
    char code1;
    char code2;
    for (int i =0; i < str.length(); i++){
      c=str.charAt(i);
      if (c == ' '){
        encodedString+= '+';
      } else if (isalnum(c)){
        encodedString+=c;
      } else{
        code1=(c & 0xf)+'0';
        if ((c & 0xf) >9){
            code1=(c & 0xf) - 10 + 'A';
        }
        c=(c>>4)&0xf;
        code0=c+'0';
        if (c > 9){
            code0=c - 10 + 'A';
        }
        code2='\0';
        encodedString+='%';
        encodedString+=code0;
        encodedString+=code1;
        //encodedString+=code2;
      }
      yield();
    }
    return encodedString;
}
