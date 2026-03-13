#include <TinyWireM.h>

#define RDA_ADDR 0x10 // Sequential Mode

void setup() {
  TinyWireM.begin();
  delay(500); 

  TinyWireM.beginTransmission(RDA_ADDR);

  // 1. Register 02H: start, Stereo, Bass Boost off
  TinyWireM.write(0xC0); 
  TinyWireM.write(0x01);

  // 2. Register 03H: 82.0 MHz
  // 82.0 MHz : 60 (Hex: 0x3C)
  // BAND: 10 (76-108 MHz) -> Bit 2 , 3
  TinyWireM.write(0x0F); 
  TinyWireM.write(0x18); 

  // 3. Register 04H: default
  TinyWireM.write(0x00);
  TinyWireM.write(0x00);

  // 4. Register 05H: volume 10/15  higher values than 10 can mess up the sound quality
  TinyWireM.write(0x84);
  TinyWireM.write(0xDA); 

  TinyWireM.endTransmission();
}

void loop() {}