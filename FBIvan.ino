#include <WiFi.h>
#include <WebServer.h>

// Replace these with your desired SSID and password
const char *ssid = "FBI Surveillance Van #334";
const char *password = "totallysecure";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<!DOCTYPE html><html><head><title>FBI Surveillance Authorization</title></head><body><h1>FBI Surveillance Van #334</h1><p>To access this network, please complete the following authorization:</p><ul><li>Declare your favorite donut flavor.</li><li>Agree to sing 'Baby Shark' every time you connect.</li><li>Confirm you believe in aliens.</li></ul><p><button onclick=\"alert('Access Denied: Please contact your local FBI office.')\">I Agree</button></p></body></html>");
}

void setup() {
  Serial.begin(115200);

  // Set up the ESP32 as an access point
  WiFi.softAP(ssid, password);

  // Start the server
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}
