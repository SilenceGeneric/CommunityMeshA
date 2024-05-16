LoRa Mesh Networking with ESP32 (WiFi Access Point)
This project demonstrates a basic setup for a node in a LoRa mesh network using an ESP32 microcontroller board. The code enables the ESP32 to:

Create a WiFi access point: This allows other devices to connect to the ESP32 and potentially interact with it.
Communicate via LoRa mesh: The ESP32 can send and receive messages to other nodes within the LoRa mesh network.
Libraries Used:

RHMesh.h: Provides functionalities for LoRa mesh networking.
RH_RF95.h: Enables communication with the RF95 LoRa radio module.
SPI.h: Facilitates communication with the LoRa module using SPI.
WiFi.h: Offers functionalities for WiFi access point creation.
Getting Started:

Hardware: You'll need an ESP32 board equipped with an RF95 LoRa module.
Libraries: Install the required libraries (RHMesh, RH_RF95) using the Arduino IDE library manager.
Configuration:
Update LORA_FREQUENCY to match your LoRa network's frequency (common options are 915.0 MHz or 433.0 MHz).
Assign a unique LORA_MESH_ADDRESS to this node within the mesh network.
Modify ssid and password to set the desired credentials for the WiFi access point.
Upload: Upload the code to your ESP32 board using the Arduino IDE.
Functionality:

Upon startup, the ESP32 initializes serial communication, LoRa radio, and the WiFi access point. The IP address of the access point is printed to the serial monitor.
In a continuous loop, the code:
Creates a sample message "Hello from node".
Attempts to send the message to a specific node (address 2 in this example) using manager.sendtoWait. If successful, it displays a confirmation message.
Listens for incoming messages with acknowledgement using manager.recvfromAck. If a message is received, its content is printed to the serial monitor
