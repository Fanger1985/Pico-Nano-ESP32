#include <WiFi.h>
#include <WebServer.h>

// Network credentials
const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";

// Ultrasonic Sensor Pins
const int triggerPin = D5; // D5 labeled pin corresponds to GPIO18
const int echoPin = D6;    // D6 labeled pin corresponds to GPIO19

// Variables to store the duration and the distance
long duration;
float distanceCm, distanceInch;

// Create an instance of the server
WebServer server(80);

void setup() {
  // Start the Serial Communication
  Serial.begin(115200);
  
  // Set sensor pins as output and input
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Connect to the Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the ESP32 Local IP Address once connected
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Define the route for root '/' directory
  server.on("/", HTTP_GET, handleRoot);

  // Define the route for '/distance' path to get the distance measured
  server.on("/distance", HTTP_GET, handleDistance);

  // Start the server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();

  // Measure the distance and print to the Serial Monitor
  measureDistance();
  Serial.print("Distance: ");
  Serial.print(distanceInch);
  Serial.println(" in");

  // Small delay to make the Serial output readable
  delay(500);
}

// Function to measure distance
void measureDistance() {
  // Clears the triggerPin condition
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Sets the triggerPin high (for set period of time)
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in cm and inches
  distanceCm = duration * 0.034 / 2;
  distanceInch = distanceCm / 2.54;
}

// Root page handler
void handleRoot() {
  // HTML content for the root page with neumorphic styling
  String html = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
                "<style>"
                "html, body { height: 100%; margin: 0; display: flex; justify-content: center; align-items: center; background-color: #e0e5ec; font-family: Arial, sans-serif; }"
                "h1 { font-size: 10vw; color: #333; }"
                "#distance { font-size: 20vw; text-align: center; margin-top: 20px; }"
                ".neu { background: #e0e5ec; border-radius: 20px; box-shadow: 8px 8px 16px #a3b1c6, -8px -8px 16px #ffffff; padding: 20px; }"
                "</style>"
                "</head>"
                "<body>"
                "<div class='neu'>"
                "<h1>Distance</h1>"
                "<div id='distance'>--</div>"
                "<h1>inches</h1>"
                "</div>"
                "<script>"
                "setInterval(() => {"
                "fetch('/distance').then(response => response.text()).then(data => {"
                "document.getElementById('distance').innerText = data;"
                "}).catch(error => console.error('Error:', error));"
                "}, 1000);"
                "</script>"
                "</body>"
                "</html>";
  server.send(200, "text/html", html);
}

// Distance handler
void handleDistance() {
  measureDistance(); // Call the measure function
  server.send(200, "text/plain", String(distanceInch));
}
