//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


//Explicit

int myOutput = D0;
int myDelayTime = 1000; 

//การกำหนดค่าคงที่
//String wifi_ssid = "";
#define wifi_ssid "MastreEWTC_2.4G"
#define wifi_pwd "12345abcde"

#define firebaseHost "rmutsvnodemcu-c2512.firebaseio.com"
#define firebaseKey "bmFe0QDnjPruYTYaBv9doTcBO9HG4yd1mPuVLlpv"

int intIndex = 0;
int intSwitch = 0;

void setup() {
    //  ส่วนที่กำหนด การส่ง Digital Out จากขาของ Node
    pinMode(myOutput, OUTPUT);
  
//  การกำหนดช่องทางในการ monitor 
  Serial.begin(9600);

//  การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_pwd);
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

//    ส่วนของการเชื่อมต่อ Firebase
    Firebase.begin(firebaseHost, firebaseKey);
    

}// setup

void loop() {
//  Serial.println("Hello Browni");
//  delay(2000);

//    Check Connected Firebase
    Firebase.setInt("myTimes",intIndex);
    if (Firebase.failed()) {
//      เมื่อไหร่ก็ตามที่ไม่สามารถเข้าถึง Firebase ได้
        Serial.print("Can not Connected Firebase : ");
        Serial.println(Firebase.error());
        return;
      }
        Serial.print("Sucess Connected Firebase Times ==> ");
        Serial.println(Firebase.getInt("myTimes"));

        intIndex=Firebase.getInt("myTimes");

        intIndex++;
        intSwitch=Firebase.getInt("Switch");
        if(intSwitch==0){
          //for my output
            digitalWrite(myOutput, HIGH);   // turn the LED on (HIGH is the voltage level)
                     
          }else{
            digitalWrite(myOutput, LOW);    // turn the LED off by making the voltage LOW
            }
        
        delay(myDelayTime);
        

}//loop




