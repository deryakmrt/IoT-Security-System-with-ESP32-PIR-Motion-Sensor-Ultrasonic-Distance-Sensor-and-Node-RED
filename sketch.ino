#include <WiFi.h>          // WiFi kütüphanesini dahil et
#include <PubSubClient.h>  // MQTT kütüphanesini dahil et

const char* ssid = "Wokwi-GUEST";  // WiFi SSID
const char* password = "";         // WiFi şifresi

const char* mqtt_server = "test.mosquitto.org";  // MQTT Broker adresi
const char* topic = "21100011001/mesafe";             // MQTT Topic

const int pirPin = 34;           // PIR sensör pini
const int trigPin = 27;           // Ultrasonic sensör TRIG pini
const int echoPin = 12;          // Ultrasonic sensör ECHO pini
const int redPin = 14;           // RGB LED kırmızı pin
const int greenPin = 26;          // RGB LED yeşil pin
const int bluePin = 25;           // RGB LED mavi pin

WiFiClient espClient;
PubSubClient client(espClient);

long duration;                   // Mesafe ölçümü için süre
int distance;                    // Ölçülen mesafe
bool ledDurumu = false;           // LED durumu
unsigned long previousMillis = 0; // Zamanlayıcı için değişken


void wifi_baslat() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to "); //bağlantı başlatırken "connecting to yazısını getir"
  Serial.println(ssid); //ssid = "Wokwi-GUEST" idi

  WiFi.begin(ssid, password); // WiFi bağlantısını başlat

  while (WiFi.status() != WL_CONNECTED) { //bağlanana kadar
    delay(500);
    Serial.print("."); // ... yazdır
  }

  Serial.println("");
  Serial.println("WiFi'ye bağlanıldı :)"); //ve bağlanınca wifiy bağlanıldı yaz
  Serial.println("IP address: "); //ip adresini getir
  Serial.println(WiFi.localIP());
}
//-----------------------------------------------------------
void tekrar_baglan() { // MQTT bağlantısı yoksa yeniden bağlan
  while (!client.connected()) { 
    if (client.connect("ESP32Client")) { // MQTT broker'a bağlan
      Serial.println("connected");
      client.subscribe("21100011001/led"); // Node-RED'den gelecek mesajları dinle
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);// Bağlantı başarısızsa 5 saniye bekle
    }
  }
}
///------------------------------------------------------------
void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message= ""; // Mesajı saklamak için değişken

  for (int i = 0; i < length; i++) {
    message += (char)payload[i]; // Mesajın içeriğini al
  }
  Serial.println("->"+message);
  if(String(topic)=="21100011001/led") // Mesajın konusu "21100011001/led" ise ilgili işlemler gerçekleştirilmektedir. 
    {
        if(message=="ON") // Gelen mesaj "ON" ise switch açıktır.
        {
            ledDurumu=true; // dashboard
            digitalWrite(redPin, HIGH); // Kırmızı LED'i aç
            digitalWrite(greenPin, LOW); // Yeşil LED'i kapat
            digitalWrite(bluePin, LOW);  // Mavi LED'i kapat
        }
        else
        {
            ledDurumu=false; // Gelen mesaj "OFF" ise switch kapalıdır.
            digitalWrite(redPin, LOW);  // Kırmızı LED'i kapat
            digitalWrite(greenPin, LOW); // Yeşil LED'i kapat
            digitalWrite(bluePin, LOW);  // Mavi LED'i kapat
        }
    }
    delay(500); // 500 milisaniye bekletildi.
}
//------------------------------------------------------
void setup() {
  Serial.begin(115200);          // Seri haberleşmeyi başlat
  pinMode(pirPin, INPUT);        // PIR sensör pinini giriş olarak ayarla
  pinMode(trigPin, OUTPUT);      // TRIG pinini çıkış olarak ayarla
  pinMode(echoPin, INPUT);       // ECHO pinini giriş olarak ayarla
  pinMode(redPin, OUTPUT);       // Kırmızı LED pinini çıkış olarak ayarla
  pinMode(greenPin, OUTPUT);     // Yeşil LED pinini çıkış olarak ayarla
  pinMode(bluePin, OUTPUT);      // Mavi LED pinini çıkış olarak ayarla

  wifi_baslat();                  // WiFi bağlantısını başlat
  client.setServer(mqtt_server, 1883);  // MQTT Broker adresini ayarla
  client.setCallback(callback);        // MQTT callback fonksiyonunu ayarla
}

//----------------------------------------------------
void loop() {
  if (!client.connected()) {
    tekrar_baglan(); // MQTT bağlantısı kopmuşsa yeniden bağlan
  }
  client.loop(); // MQTT olaylarını kontrol et

  long now = millis();
  if (now - previousMillis > 250) { // 250ms aralıklarla kontrol et
    previousMillis = now;

    if (digitalRead(pirPin) == HIGH) { // PIR sensör hareket algılarsa
      digitalWrite(trigPin, LOW);   // Ultrasonik sensör için TRIG pini düşük seviyeye alınır
      delayMicroseconds(2);          // 2 mikrosaniye bekleme
      digitalWrite(trigPin, HIGH);  // TRIG pini yüksek seviyeye çıkarılır
      delayMicroseconds(10);         // 10 mikrosaniye bekleme
      digitalWrite(trigPin, LOW);   // TRIG pini tekrar düşük seviyeye alınır


      duration = pulseIn(echoPin, HIGH); // Ultrasonik sensörden yankı süresini al
      distance = duration * 0.034 / 2;   // Mesafeyi hesapla

      if (distance <= 50) { // Mesafe 50cm'den küçükse
        ledDurumu = !ledDurumu; 
        digitalWrite(redPin, HIGH); // Kırmızı LED'i aç
        digitalWrite(greenPin, LOW); // Yeşil LED'i kapat
        digitalWrite(bluePin, LOW);  // Mavi LED'i kapat
        digitalWrite(redPin, ledDurumu); // LED'i yanıp söndür
        String payload = "Mesafe: " + String(distance) + " cm"; // Mesafeyi stringe çevir
        Serial.println(payload); // Seri port üzerinden mesafeyi yazdır
        client.publish(topic, payload.c_str()); // Mesafeyi MQTT üzerinden gönder
      
      }
       else {
      digitalWrite(redPin, LOW); // Kırmızı LED'i kapat
}
    }
  }
}