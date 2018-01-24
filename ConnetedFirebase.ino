//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


//Explicit
//การกำหนดค่าคงที่
//String wifi_ssid = "";
#define wifi_ssid "MastreEWTC_2.4G"
#define wifi_pwd "12345abcde"



void setup() {
//  การกำหนดช่องทางในการ monitor 
  Serial.begin(9600);

//  การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid,wifi_pwd);
  Serial.println("Start Find WiFi");
  
  while (WiFi.status()!= WL_CONNECTED) {
//    ถ้า Condition True จะทำงานที่นี้
        Serial.print("#");
        delay(500);
    }

//    ถ้ามาทำงานตรงนี้ คือ Connected WiFi ได้แล้วเท่านั้น
    Serial.println();
    Serial.println("Success Conneted WiFi");
    Serial.println(WiFi.localIP());

}// setup

void loop() {
//  Serial.println("Hello Browni");
//  delay(2000);

  

}//loop




