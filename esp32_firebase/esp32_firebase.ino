#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "shaheen"
#define WIFI_PASSWORD "ALI123456y"


/* 2. Define the API Key */
#define API_KEY "o4i10yfcBe7zL5tUxdzDSBQZihgeKiG8QjXfAJCL"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://voltageread-22aa9-default-rtdb.firebaseio.com/"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

// pin to read from
#define analogDataRead 34

FirebaseData firebaseData;

// FirebaseJson json;

float num;
float out;

void setup() {

  // baud rate
  Serial.begin(115200);

  // connect to wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // set the pin as an input
  pinMode(analogDataRead, INPUT);

  // connect to firebase
  Firebase.begin(DATABASE_URL, API_KEY);

  Firebase.reconnectWiFi(true);
}

void loop() {

  // re-assign num var to hold the data  

  num = analogRead(analogDataRead);

  out = num * (3.3 / 4095.0);

  // print output
  Serial.println(out);
  // push num to node "/voltage" 
  Firebase.pushString(firebaseData, "/voltage", out);
  delay(200);

}
