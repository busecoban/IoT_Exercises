#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "Buse";
const char *password = "casuva48";
const char *serverUrl = "http://192.168.1.1:8080/api/doorStatus"; 
const int manyetikSensorPin = 2;

void setup() {
  Serial.begin(115200);
  
  // Telefonunuzun kişisel erişim noktasına bağlan
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);

  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 10) {
    delay(1000);
    Serial.print(".");
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("WiFi connection failed");
    while(1) { // Bağlantı başarısız olduğunda programın donmasını önlemek için sonsuz döngü
      delay(1000);
    }
  }
}

void loop() {
  int manyetikDurum = digitalRead(manyetikSensorPin);
  String newStatus = manyetikDurum == HIGH ? "Kapı kapalı" : "Kapı açık";

  // HTTP POST isteği gönder
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
  String jsonBody = "{\"newStatus\":\"" + newStatus + "\"}";
  int httpResponseCode = http.POST(jsonBody);
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error in HTTP POST request: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();
  delay(1000); // 1 saniye bekle
}
