PROJE LİNKİ:
https://wokwi.com/projects/399584757273243649

KULLANILAN KÜTÜPHANELER VE AÇIKLAMALARI:
---WiFi.h Kütüphanesi---
ESP32 veya ESP8266 gibi Wi-Fi özellikli mikrodenetleyicilerle Wi-Fi bağlantısı yapmak için kullanılır.
+WiFi.begin(ssid, password): Belirtilen SSID ve şifreyle Wi-Fi ağına bağlanmayı başlatır.
+WiFi.localIP(): Bağlı olduğunuz ağdaki cihazın IP adresini alır.

---PubSubClient.h Kütüphanesi---
MQTT (Message Queuing Telemetry Transport) protokolü kullanarak IoT cihazları arasında iletişim kurmayı sağlar.
+PubSubClient(WiFiClient): MQTT istemci nesnesi oluşturur ve bir WiFiClient nesnesiyle ilişkilendirir.
+client.setServer(mqtt_server, 1883): MQTT broker adresini ve port numarasını ayarlar.
+client.setCallback(callback): MQTT mesajları geldiğinde çağrılacak geri çağırma işlevini belirler.
+client.connect(clientID): MQTT broker'a bağlanır. clientID, istemcinin benzersiz tanımlayıcısıdır.
+client.subscribe(topic): Belirtilen MQTT topic'ini dinlemeye başlar.
+client.publish(topic, payload): Belirtilen MQTT topic'ine bir mesaj yayınlar.

PROJEYİ ÇALIŞTIRMA ADIMLARI:
1) Bilgisayara node.js ve node-red platformu için gerekli kurulumlar yapılır.
2) Gereken kurulumlar yapıldıktan sonra cmd ekranına "node-red" yazılır. Örnekteki gibi çıktı alınır:

C:\Users\Gulduren>node-red
7 Jun 22:58:35 - [info]

Welcome to Node-RED
===================

7 Jun 22:58:35 - [info] Node-RED version: v3.1.9
7 Jun 22:58:35 - [info] Node.js  version: v20.14.0
7 Jun 22:58:35 - [info] Windows_NT 10.0.19045 x64 LE
7 Jun 22:58:37 - [info] Loading palette nodes
7 Jun 22:58:44 - [info] Dashboard version 3.6.5 started at /ui
7 Jun 22:58:45 - [info] Settings file  : C:\Users\Gulduren\.node-red\settings.js
7 Jun 22:58:45 - [info] Context store  : 'default' [module=memory]
7 Jun 22:58:45 - [info] User directory : \Users\Gulduren\.node-red
7 Jun 22:58:45 - [warn] Projects disabled : editorTheme.projects.enabled=false
7 Jun 22:58:45 - [info] Flows file     : \Users\Gulduren\.node-red\flows.json
7 Jun 22:58:45 - [info] Server now running at http://127.0.0.1:1880/
7 Jun 22:58:45 - [warn]

3) Alınan çıktıda verilen adres kopyalanıp tarayıcıda yapıştırılıp çalıştırılır. (http://127.0.0.1:1880/)
4) Node-red platformuna bağlanmış olunacaktır.
5) Dashboarda ulaşmak için alınan adresin sağına "ui" yazılıp adres çubuğunda aratılır (http://127.0.0.1:1880/ui/)
6) Wokwi projesine verilen link üzerinden ulaşılır.
7) Wokwi projemizde "Start the simulation" butonuna basıp proje çalışacaktır :)
