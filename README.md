# 📡 DSNSim: Deep Space Network (DSN) Transceiver Simulator

## ✨ Project Summary

DSNSim utilizes an Arduino MKR WiFi 1010 to simulate a single Deep Space Station (DSS) acting as a transceiver. It models the core functions of the DSN by using a 433MHz RF module to physically send (Uplink) and receive (Downlink) a stream of simulated deep space communication data types (Telemetry, Command, Tracking).

The use of a common transceiver setup emphasizes the shared hardware component used for both sending and receiving signals, simulating a crucial aspect of modern deep space communication systems.

## 💻 Code and Hardware Details

### Target Hardware
- Microcontroller: Arduino MKR WiFi 1010

- RF Module: 433MHz RF Transmitter and Receiver Pair

- Role: Simulated Deep Space Station (DSS) Transceiver.

### Wireless Communication
- Frequency: 433MHz (A common, unlicensed frequency band for short-range radio communication).

- Modulation: Typically Amplitude Shift Keying (ASK), where the carrier wave's amplitude is switched ON (HIGH) or OFF (LOW) to transmit binary data. This is a simplified, yet functional, model of the complex RF communication used by the DSN.

- Library: The project relies on RadioHead library to handle the encoding and decoding of the serial data for reliable wireless transmission.

## 🛠️ Setup and Running the Simulator

### Prerequisites
- Arduino IDE: Latest version installed.

- Arduino SAMD Boards: Board package installed for the MKR family.

- Library: Install the required RadioHead library via the Arduino IDE's Library Manager (Sketch > Include Library > Manage Libraries...).

### Execution Steps
- Wiring: Connect the 433MHz transmitter and receiver modules to your Arduino MKR WiFi 1010 based on the pin definitions in the ```main.ino``` sketch.

- Antenna: Attach a 17.3 cm wire to the antenna pin of both the transmitter and receiver for optimal 433MHz range (this is approximately a quarter-wavelength antenna).

- Upload the Code: Compile and upload the main.ino sketch to your Arduino MKR WiFi 1010.

- Monitor the Simulation: Open the Serial Monitor to observe the flow of simulated DSN data being encoded (for Uplink) and decoded (for Downlink) by the 433MHz RF modules by virtue of the commands ```uplink``` and ```downlink``` respectively.

## 🔬 Next Steps for Development

- Signal Strength: Use the RadioHead library features (if available) or simply add noise modeling to simulate the signal strength and distance challenges inherent in DSN communication.

- Error Correction: Implement a simple checksum or cyclic redundancy check (CRC) to simulate how DSN data ensures integrity over long, noisy links.
