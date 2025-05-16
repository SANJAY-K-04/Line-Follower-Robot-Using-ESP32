# Line Follower Robot Using ESP32

This project demonstrates how to build a simple **Line Follower Robot** using the ESP32 microcontroller, L298N motor driver, IR sensors, and DC motors. The robot detects and follows a line using IR sensors, making decisions based on the sensor inputs to navigate along the path.

<p align="center">
  <img src="https://github.com/SANJAY-K-04/Line-Follower-Robot-Using-ESP32/blob/main/Screenshot%202024-11-20%20154536.png?raw=true" width="700" alt="Top View"><br>
</p>

## Components Used
1. ESP32 Microcontroller
2. L298N Motor Driver Module
3. IR Sensors (2 units)
4. DC Motors (2 units)
5. 7V to 12V Li-ion battery
6. Switch
7. Connecting Wires
8. Chassis for mounting the components

---

## Circuit Diagram

<p align="center">
  <img src="https://github.com/SANJAY-K-04/Line-Follower-Robot-Using-ESP32/blob/main/image3.jpg?raw=true" width="700" alt="Top View"><br>
</p>
---

## How It Works
1. **IR Sensors**: Detect the presence of the line and send digital signals to the ESP32.
   - Left IR Sensor: Detects the left side of the line.
   - Right IR Sensor: Detects the right side of the line.
   
2. **ESP32 Microcontroller**: Processes the sensor inputs and determines the direction of movement:
   - If both sensors detect the line, the robot moves forward.
   - If only the left sensor detects the line, the robot turns left.
   - If only the right sensor detects the line, the robot turns right.
   - If no line is detected, the robot stops.

3. **Motor Driver (L298N)**: Controls the motors based on the ESP32 output signals.

---


## Setup Instructions
1. Assemble the hardware components as per the circuit diagram.
2. Connect the ESP32 to your computer and upload the code using Arduino IDE.
3. Power the robot using the 18650 battery.
4. Place the robot on a line path and turn it on using the switch.
5. The robot will autonomously follow the line.

---
