# Deep-Space-Network - Presentation Summary

## Infrastructure Summary
__________________
Deep Space Network
__________________
|____ |______|___|______________ > 
|     |______|___|______________ > NOCC
|     |      |__________________ >      
|     |      |
GDSCC MDSCC  CDSCC
|____  |________  |_________
     |          |           |
     |          |           |
    SPC        SPC         SPC
     |          |           |
Multiple DSS  Mutiple DSS  Multiple DSS




The DSN is an extremely complex facility, but it becomes more easily comprehensible if we recognize its **seven data types**. In the past, each of these seven data types was associated with a separate DSN system.

Today, thanks to the Network Simplification Program, these have been consolidated into two DSN systems: **Uplink (The Uplink Tracking and Command Subsystem, UPL)** and **Downlink (The Downlink Tracking & Telemetry Subsystem, DTT)**.

The seven data-types include:
- **Frequency & Timing Data Type, FT&T** : It is the DSN’s internal clock, providing ultra-precise time and frequency signals that synchronize all network operations. Using hydrogen masers, cesium standards, and GPS calibration, it keeps all DSN stations aligned within fractions of a microsecond. 

- **Tracking Data Type, TRK** : The DSN uses Doppler and ranging measurements to precisely determine a spacecraft’s velocity, distance, and trajectory. These data help generate predicts for antenna pointing and frequency control to maintain communication with spacecraft.

- **Telemetry Data Type, TLM** : Telemetry (TLM) data represents a spacecraft’s engineering and scientific measurements transmitted as digital signals. The DSN decodes these signals and delivers the data for analysis, monitoring, and scientific use.

- **Command Data Type, CMD** : Consists of digital instructions sent from Earth to control spacecraft operations. The DSN’s uplink system transmits these bits, which the spacecraft interprets as commands or software updates.

- **Monitor Data Type, MON** : Provides information about the DSN’s own performance and health. It’s collected across DSN subsystems to manage operations, ensure reliability, and assist flight projects in monitoring signal quality in real time.

- **Radio Science Data Type, RS** : Radio Science (RS) data treats the spacecraft radio and DSN as a scientific instrument to study how signals are affected by planets, moons, the Sun, or other structures.Using open-loop receivers, RS captures a range of frequencies to measure Doppler shifts, refraction, attenuation, and other signal modifications.