# 🎧 AnalogSync: Open-Source Zero-Latency Wireless Headset

![Open Source Hardware](https://img.shields.io/badge/Open%20Source-Hardware-orange)
![License: MIT](https://img.shields.io/badge/License-MIT-green)
![Zero Latency](https://img.shields.io/badge/Latency-0ms-blue)

Welcome to the **AnalogSync** project! This is a 100% open-source, DIY wireless headset system built from scratch. Unlike standard Bluetooth headphones that suffer from digital compression and audio latency, this project uses **pure analog FM transmission** to achieve **true zero-latency** and **Hi-Fi Stereo** sound. 

Whether you are a gamer, musician, or hardware enthusiast, you can buy the parts, 3D print the shell, and build your own latency-free wireless audio system!

## ✨ Key Features
* **Zero Latency (0ms):** End-to-end analog signal processing. Perfect for gaming and lip-syncing.
* **Bare-Metal I2C Control:** Custom firmware bypassing standard libraries to directly control IC registers (RDA5807M & KT0803L) for advanced stereo and bass management.
* **Optimized Power Management:** Engineered impedance matching for the TDA1308 Class-AB amplifier driving 8-Ohm speakers.
* **100% 3D Printable:** Custom-designed ergonomic headset shell and headband.

---

## 🛠️ Bill of Materials (BOM) - What You Need
Anyone can build this! Here is the complete list of parts:

**Receiver (The Headset):**
* 1x ATtiny85 Microcontroller (Overclocked to 8MHz internal)
* 1x RDA5807M FM Stereo Receiver Module
* 1x TDA1308 Class-AB Headphone Amplifier
* 2x 32mm 8-Ohm Speakers
* 2x 3.7V Li-Po Battery & Charging Module (e.g., TP4056) or 4x aa battery
* Assorted Capacitors & Resistors (See Schematics)

**Transmitter (The Base Station):**
* 1x Arduino (Nano or Uno)
* 1x KT0803L FM Transmitter Module
* 2x Push Buttons (For frequency tuning)
* Audio Jack / Aux Cable
 (any fm transmitter module works)
---

## 🚀 How to Build It (DIY Guide)

### Step 1: 3D Print the Enclosure
Navigate to the `/Mechanical` folder. You will find the `.STL` files for the left/right ear cups and the headband. Print them using PLA or PETG (20% infill is recommended for durability).

### Step 2: The Hardware & Solder
Check the `/Hardware` folder for the wiring diagram. 
* **Note on Amplifier:** Ensure you add a 680uF decoupling capacitor at the output of the TDA1308 to protect the 8-Ohm speakers and prevent voltage drops!

### Step 3: Flash the Firmware
Navigate to the `/Firmware` folder.
* **RX (Headset):** Flash the ATtiny85. *Make sure to burn the bootloader to 8MHz internal clock first!*
* **TX (Base):** Upload the Arduino sketch. The buttons on Pin 2 and Pin 3 allow you to scan frequencies (Default lock: 82.0 MHz).

### Step 4: Assemble & Enjoy
Put the electronics inside your fresh 3D prints, power up the transmitter with an audio source, and enjoy your zero-latency analog sound!

---

## 🤝 Contributing
Feel free to fork this project, submit pull requests, or open an issue if you have ideas to improve the audio quality or 3D design. Let's make open-source hardware better together!

## 📝 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
