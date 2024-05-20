int sensor = A0; // KY-037 ses sensörünün analog çıkışı A0 pinine bağlı
int led = 13; // LED 13 numaralı pine bağlı

const int threshold = 500; // Eşik değeri (sessiz ortamda alınan maksimum değerin biraz üzerinde)
bool ledState = false; // LED durumu (başlangıçta kapalı)
unsigned long lastSoundTime = 0; // Son ses algılama zamanı
const unsigned long debounceDelay = 200; // Debouncing gecikme süresi (milisaniye)
const unsigned long sampleWindow = 1000; // Örnekleme süresi (milisaniye)
unsigned long sampleStartTime = 0; // Örnekleme başlangıç zamanı

int maxLevel = 0; // Maksimum ses seviyesi

void setup() {
  pinMode(sensor, INPUT); // Sensör pinini giriş olarak ayarla
  pinMode(led, OUTPUT); // LED pinini çıkış olarak ayarla
  Serial.begin(9600); // Seri haberleşmeyi başlat
}

void loop() {
  unsigned long currentTime = millis();

  // Örnekleme süresi dolduysa maksimum değeri yazdır ve sıfırla
  if (currentTime - sampleStartTime >= sampleWindow) {
    Serial.print("Max sound level: ");
    Serial.println(maxLevel);

    // Eşik değer kontrolü
    if (maxLevel > threshold) {
      // Debouncing kontrolü
      if (currentTime - lastSoundTime > debounceDelay) {
        ledState = !ledState; // LED durumunu değiştir
        lastSoundTime = currentTime; // Son ses algılama zamanını güncelle
      }
    }

    // LED'i güncellenmiş duruma göre ayarla
    digitalWrite(led, ledState ? HIGH : LOW);

    // Maksimum değeri sıfırla ve örnekleme zamanını güncelle
    maxLevel = 0;
    sampleStartTime = currentTime;
  }

  // Yeni ses seviyesini oku
  int soundLevel = analogRead(sensor);

  // Maksimum değeri güncelle
  if (soundLevel > maxLevel) {
    maxLevel = soundLevel;
  }

  delay(50); // Kısa bir gecikme ekle
}
