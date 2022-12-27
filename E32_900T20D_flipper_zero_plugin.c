#include "flipper.h"
#include "e32_900t20d.h"

// Flipper Zero's serial port
SoftwareSerial flipperSerial(RX_PIN, TX_PIN);

// E32-900T20D module
E32_900T20D e32Module;

void setup() {
  // Initialize Flipper Zero's serial port
  flipperSerial.begin(9600);
  
  // Initialize E32-900T20D module
  e32Module.begin(flipperSerial);
}

void loop() {
  // Check if there is any data available from the E32-900T20D module
  if (e32Module.available()) {
    // Read the message from the E32-900T20D module
    String message = e32Module.receiveMessage();
    
    // Send the message over the meshtastic network
    sendMessage(message);
  }
  
  // Check if there is any data available from the meshtastic network
  if (receivedMessage()) {
    // Read the message from the meshtastic network
    String message = receiveMessage();
    
    // Send the message to the E32-900T20D module
    e32Module.sendMessage(message);
  }
}
