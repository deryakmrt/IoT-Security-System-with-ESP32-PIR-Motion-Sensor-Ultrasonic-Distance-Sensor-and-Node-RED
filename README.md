# *Introduction*  
The aim of this project is to practice using widely used sensors (PIR Motion Sensor and Ultrasonic Distance Sensor), one of the most common development boards (ESP32), and other components such as LEDs, resistors, and breadboards. The project involves creating the circuit on the Wokwi simulation platform, establishing necessary pin connections, and programming the devices. Additionally, we will use the Node-RED platform and MQTT protocol to monitor and control the circuit via the "mosquitto" broker.

# Project Requirements
When the PIR sensor detects motion and the distance sensor measures a distance between 0 and 50 cm, it should send the measurement to the broker, which we can observe on the Node-RED dashboard. Additionally, an LED should blink every 250 ms within this distance range. A button on the Node-RED dashboard should allow the LED to be turned on and off in case of danger.

# Components and Tools
Simulation Platform: Wokwi  
Sensors:  PIR Motion Sensor, HC-SR04 Ultrasonic Distance Sensor  
Development Board: ESP32  
Other Components: RGB LED, Full Breadboard, Resistor  
MQTT Broker: test.mosquitto.org:1883  
Wi-Fi Configuration:  SSID: Wokwi-GUEST  
Password: ""  
Node-RED Platform: Set up with Node.js and necessary dashboard packages  

# Steps to Run the Project
1. Set Up the Hardware:
Build the circuit according to the provided schematic on Wokwi, including the PIR Motion Sensor, Ultrasonic Distance Sensor, ESP32, and LED.
2. Program the ESP32:
Write and upload the sketch (sketch.ino) to ESP32 to read sensor data and publish to the MQTT broker.
3. Configure Node-RED:
Install Node-RED and required packages.  
Create the Node-RED flow to subscribe to the sensor data and control the LED.
4. MQTT Configuration:
Use the topic OGR_NO/mesafe for publishing distance measurements (replace OGR_NO with your student number).
5. Node-RED Dashboard:
Design a dashboard to display distance measurements and provide control for the LED.

## Conclusion
This project demonstrates practical applications of IoT using ESP32, sensors, and the Node-RED platform. It provides hands-on experience with circuit simulation, MQTT communication, and remote monitoring and control.
PROJE LİNKİ:
https://wokwi.com/projects/399584757273243649

## KULLANILAN KÜTÜPHANELER VE AÇIKLAMALARI:
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
1. Bilgisayara node.js ve node-red platformu için gerekli kurulumlar yapılır.
2. Gereken kurulumlar yapıldıktan sonra cmd ekranına "node-red" yazılır. Örnekteki gibi çıktı alınır:

C:\Users\Gulduren>node-red
7 Jun 22:58:35 - [info]

Welcome to Node-RED  

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

3. Alınan çıktıda verilen adres kopyalanıp tarayıcıda yapıştırılıp çalıştırılır. (http://127.0.0.1:1880/)
4. Node-red platformuna bağlanmış olunacaktır.
5. Dashboarda ulaşmak için alınan adresin sağına "ui" yazılıp adres çubuğunda aratılır (http://127.0.0.1:1880/ui/)
6. Wokwi projesine verilen link üzerinden ulaşılır.
7. Wokwi projemizde "Start the simulation" butonuna basıp proje çalışacaktır :)
