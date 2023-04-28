#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "shaheen"
#define WIFI_PASSWORD "****"


/* 2. Define the API Key */
#define API_KEY "o4i10yfcBe7zL5tUxdzDSBQZihgeKiG8QjXfAJCL"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://voltageread-22aa9-default-rtdb.firebaseio.com/"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

#define dd 2

FirebaseData firebaseData;

// FirebaseJson json;

int num;

void setup() {

  // baud rate
  Serial.begin(115200);

  // connect to wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  pinMode(dd, INPUT);

  // connect to firebase
  Firebase.begin(DATABASE_URL, API_KEY);

  Firebase.reconnectWiFi(true);
}

void loop() {

  for (int i = 100; i > 0; i++) {

    // default data for checking
    // json.set("/data", i);
    // Firebase.updateNode(firebaseData, "/number", json);
    Firebase.pushString(firebaseData, "/number", i);
    delay(500);
  }
}
