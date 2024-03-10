#include <WiFi.h>

const char* meshSSID = "FBI Surveillance Van";
const char* password = "thereisnospoon";  // It's a mesh network, so why not have a little fun?

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(meshSSID, password);
  WiFi.softAP(meshSSID, password);  // Create the AP with the same credentials

  Serial.println("Node started. Scanning for other nodes...");
}

void loop() {
  int n = WiFi.scanNetworks();
  int nodeCount = 0;
  
  Serial.println("Scan done");
  if (n == 0) {
    Serial.println("No nodes found.");
  } else {
    for (int i = 0; i < n; ++i) {
      // Check if the found SSID matches our mesh network SSID
      if (String(WiFi.SSID(i)) == meshSSID) {
        nodeCount++;
      }
    }
    Serial.print(nodeCount);
    Serial.println(" nodes found.");
  }
  delay(5000);  // Wait a bit before scanning again
}
