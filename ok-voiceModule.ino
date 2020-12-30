#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);   //RX.TX
String receive_data;

void setup(){
  mySerial.begin(115200);
  Serial.begin(115200);
  receive_data = "";
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  while (mySerial.available() > 0) {
    receive_data = String(receive_data) + String(char(mySerial.read()));
  }
  if (String(receive_data).indexOf("dakainuanqi") >= 0) {
    digitalWrite(4,HIGH);
    Serial.println("打开暖气");
    receive_data = "";

  } else if (String(receive_data).indexOf("guanbinuanq") >= 0) {
    digitalWrite(4,LOW);
    Serial.println("关闭暖气");
    receive_data = "";
  }
  if (String(receive_data).indexOf(String("dakaicfeng")) >= 0) {
    digitalWrite(5,HIGH);
    Serial.println("打开吹风");
    receive_data = "";

  } else if (String(receive_data).indexOf(String("guanbicfeng")) >= 0) {
    digitalWrite(5,LOW);
    Serial.println("关闭吹风");
    receive_data = "";
  }
  if (String(receive_data).indexOf(String("dakdianfangbao")) >= 0) {
    digitalWrite(6,HIGH);
    Serial.println("打开电饭煲");
    receive_data = "";

  } else if (String(receive_data).indexOf(String("guabdianfangbao")) >= 0) {
    digitalWrite(6,LOW);
    Serial.println("关闭电饭煲");
    receive_data = "";
  }
  if (String(receive_data).indexOf(String("turnon")) >= 0) {
    digitalWrite(7,HIGH);
    Serial.println("打开台灯");
    receive_data = "";

  } else if (String(receive_data).indexOf(String("turnoff")) >= 0) {
    digitalWrite(7,LOW);
    Serial.println("关闭台灯");
    receive_data = "";
  }
}
