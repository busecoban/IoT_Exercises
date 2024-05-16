const int manyetikSensorPin = 2;
int doorStatus = 0;

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat
  pinMode(manyetikSensorPin, INPUT_PULLUP); // Manyetik sensör pinini giriş olarak ayarla ve dahili pull-up direnci etkinleştir
}

void loop() {
  int manyetikDurum = digitalRead(manyetikSensorPin); 
  
  if (manyetikDurum == HIGH) {
    Serial.println("Door Open"); // Eğer manyetik sensör LOW ise, kapı açıktır
    doorStatus = 1;
  } else {
    Serial.println("Door Close "); // Eğer manyetik sensör HIGH ise, kapı kapalıdır
    doorStatus = 0;
  }
  
  // Door status'u backend'e gönder
  sendDoorStatusToBackend(doorStatus);
  
  delay(1000); 
}

void sendDoorStatusToBackend(int status) {
  // Buraya backend'e status'u gönderen kodu ekleyin
  // Örneğin:
  // Backend.sendData(status);
}
