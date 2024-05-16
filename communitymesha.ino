#include <RHMesh.h>
#include <RH_RF95.h>
#include <SPI.h>
#include <WiFi.h>

// LoRa settings
#define LORA_FREQUENCY 915.0
#define LORA_MESH_ADDRESS 1 // Set unique address for each node

// WiFi settings
const char *ssid = "ESP32_AP";
const char *password = "12345678";

// LoRa driver and manager
RH_RF95 driver;
RHMesh manager(driver, LORA_MESH_ADDRESS);

void setup() {
  Serial.begin(9600);

  // Initialize LoRa
  if (!driver.init()) {
    Serial.println("LoRa initialization failed.");
    while (true);
  }
  driver.setFrequency(LORA_FREQUENCY);

  // Initialize WiFi AP
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // LoRa mesh communication logic
  uint8_t data[] = "Hello from node";
  uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  // Send message to a specific node (e.g., node 2)
  if (manager.sendtoWait(data, sizeof(data), 2)) {
    Serial.println("Message sent to node 2");
  }

  // Check for incoming messages
  if (manager.recvfromAck(buf, &len)) {
    Serial.print("Received message: ");
    Serial.println((char *)buf);
  }
}
