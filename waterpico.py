import network
import urequests
import machine
import time

# WiFi details
WIFI_SSID = 'YourWiFiSSID'
WIFI_PASSWORD = 'YourWiFiPassword'
SERVER_URL = 'http://yourserver.com/data'

# Initialize WiFi
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(WIFI_SSID, WIFI_PASSWORD)

# Wait for connection
while not wlan.isconnected():
    time.sleep(1)
print('Connected to WiFi!')

# Moisture sensor setup
adc = machine.ADC(machine.Pin(26))  # Assuming the moisture sensor is connected to GP26

def read_moisture():
    value = adc.read_u16()  # Read the moisture value
    return value

def send_data(value):
    try:
        response = urequests.post(SERVER_URL, json={'moisture': value})
        print('Data sent:', response.text)
    except Exception as e:
        print('Failed to send data:', e)

# Main loop
while True:
    moisture_level = read_moisture()
    print('Moisture Level:', moisture_level)
    send_data(moisture_level)
    time.sleep(600)  # Wait for 10 minutes before the next read
