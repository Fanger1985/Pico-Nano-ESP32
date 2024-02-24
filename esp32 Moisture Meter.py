import machine
import network
import time
import urequests

# Replace with your network details
ssid = 'Your_WiFi_SSID'
password = 'Your_WiFi_Password'

# Replace with the endpoint you're sending data to
url = 'http://yourserver.com/data'

# Setup the ADC for reading the soil moisture sensor
adc = machine.ADC(machine.Pin(34)) # Change the pin number to match your ESP32 setup
adc.atten(machine.ADC.ATTN_11DB) # Configure the attenuation for full range of 0 to 3.6V

# Connect to WiFi
def connect_to_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)

    while not wlan.isconnected():
        pass  # wait for connection

    print('Network config:', wlan.ifconfig())

# Read the sensor value
def read_soil_moisture():
    # Read the ADC value
    value = adc.read()
    # Convert it to a percentage (assuming 0 is dry and 4095 is wet)
    moisture_percent = (value / 4095.0) * 100
    return moisture_percent

# Send the data to the server
def send_data(moisture):
    data = {'moisture': moisture}
    try:
        response = urequests.post(url, json=data)
        print(response.text)
    except Exception as e:
        print('Failed to send data:', e)

# Main routine
def main():
    connect_to_wifi()
    while True:
        moisture = read_soil_moisture()
        print('Soil Moisture:', moisture)
        send_data(moisture)
        
        # Sleep for a bit before taking the next reading
        time.sleep(10)  # Sleep for 10 seconds

# Run the main routine when the script starts
if __name__ == '__main__':
    main()
