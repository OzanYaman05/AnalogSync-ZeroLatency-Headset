#include <Wire.h>
#include <KT0803.h>

KT0803L radio;

float frequency = 82.0; // Default startup frequency (82.0 MHz)
int bassLevel = 0;      // 0:Off, 1:5%, 2:10%, 3:15%

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  radio.begin(frequency, false);
  
  Serial.println("\n--- ADVANCED AUDIO AND FREQUENCY CONTROL ---");
  Serial.println("Serial : Type 'f[number]' to set frequency via Serial Monitor (e.g., f82.5)");
  Serial.println("Serial : Type 'b[0-3]' to set Bass Boost level");
  Serial.println("----------------------------------------\n");
  
  updateFrequency(frequency); // Send initial frequency to the radio
}

void loop() {
  // --- SERIAL CONTROL (Allows entering frequency/bass via Serial Monitor) ---
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    
    if (data.length() > 1) {
      char command = toLowerCase(data.charAt(0));
      String value = data.substring(1);
      
      // 'f' command to set frequency directly from Serial Monitor
      if (command == 'f') {
        frequency = value.toFloat();
        updateFrequency(frequency);
      } 
      // 'b' command to set bass boost level
      else if (command == 'b') {
        bassLevel = value.toInt();
        if (bassLevel >= 0 && bassLevel <= 3) {
          setBassBoost(bassLevel);
          Serial.print(">> BASS BOOST: "); Serial.print(bassLevel * 5); Serial.println("%");
        }
      }
    }
  }
}

// Helper function to set frequency and print it to the Serial Monitor
void updateFrequency(float newFrequency) {
  radio.setFrequency(newFrequency);
  Serial.print(">> NEW FREQUENCY: "); 
  Serial.println(newFrequency, 1); // Display 1 decimal place (e.g., 82.1)
}

// Configures Bass Boost by directly accessing KT0803L Registers via I2C (Bare-metal style)
void setBassBoost(int level) {
  Wire.beginTransmission(0x3E); // KT0803L I2C address
  Wire.write(0x04);             // Target register address
  
  byte regVal = 0x00;           // Clear default
  regVal |= (level & 0x03); 
  
  Wire.write(regVal);
  Wire.