#include <WiFi.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";

WiFiUDP udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char replyPacket[255];     // buffer for reply packets

// Soil moisture sensor setup
const int soilMoisturePin = 14;  // GPIO 14 (ADC2_CH6)

void setup() {
  Serial.begin(115200);
  pinMode(soilMoisturePin, INPUT);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  udp.begin(localUdpPort);
  Serial.printf("Now broadcasting on IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    // Receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udp.remoteIP().toString().c_str(), udp.remotePort());
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);

    // Check if the incoming packet is a command to read soil moisture
    if (strcmp(incomingPacket, "read_moisture") == 0) {
      int moistureValue = analogRead(soilMoisturePin);
      snprintf(replyPacket, sizeof(replyPacket), "Soil Moisture Value: %d", moistureValue);
      udp.beginPacket(udp.remoteIP(), udp.remotePort());
      udp.write((uint8_t *)replyPacket, strlen(replyPacket));
      udp.endPacket();
    } else {
      // For any other message, just reply with "fart"
      udp.beginPacket(udp.remoteIP(), udp.remotePort());
      udp.write((uint8_t *)"fart", 4);
      udp.endPacket();
    }
  }
  delay(10);
}
