#include <IBusBM.h>
 
// Create iBus Object
IBusBM ibus;
 
// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
void setup() {
  // Start serial monitor
  Serial.begin(115200);
 
  // Attach iBus object to serial port
  ibus.begin(Serial1);
}

 
  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"
 
 void loop() {
 
  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"
 
  int value = readChannel(0, -100, 100, 0);
    Serial.print("XX");
    Serial.print(" ");
    Serial.print(value);
    Serial.print("  ");
    Serial.print(readChannel(1, -100, 100, 0));
    Serial.print("  ");
  
 
 
  // Print channel 6 (switch) boolean value
  Serial.print("");
  Serial.print(readChannel(3, -100, 100, 0));
  Serial.println();
 
  delay(10);
}
