# Microwave Oven Simulation using PIC Microcontroller

## 1. Introduction

This project implements a Microwave Oven Controller Simulation using Embedded C on a PIC microcontroller. The system mimics the basic operational behavior of a household microwave oven by integrating a matrix keypad for user input, a character LCD (CLCD) for visual feedback, a fan to represent the heating mechanism, and a buzzer to indicate the completion of the cooking process.

The project is designed with a modular architecture, where each peripheral (keypad, LCD, fan, and buzzer) is handled by independent driver modules. The core microwave logic is implemented using a state-machine-based approach, ensuring clear control flow and reliable operation.

This project is intended for educational purposes to demonstrate embedded system design, peripheral interfacing, and real-time control logic.

---

## 2. Objectives

* To design and implement a microwave oven control system using a PIC microcontroller.
* To interface and control a matrix keypad, LCD, fan, and buzzer.
* To implement time-based cooking functionality with countdown display.
* To design firmware using a modular and structured approach.
* To understand state machine implementation in embedded systems.

---

## 3. System Overview

The microwave oven system consists of:

* User input interface (Matrix Keypad)
* Display unit (16x2 Character LCD)
* Output actuators (Fan and Buzzer)
* Control unit (PIC Microcontroller)

The microcontroller continuously monitors keypad input, updates the LCD display, and controls the fan and buzzer based on the selected cooking time and system state.

---

## 4. Features

* User-defined cooking time input through keypad
* Real-time countdown display on LCD
* Start, Stop, and Reset operations
* Fan control to simulate heating
* Buzzer indication on cooking completion
* Modular firmware design
* Makefile-based build system
* Clear separation between drivers and application logic

---

## 5. Project Structure

```
microwave-oven-project/
│
├── main.c               → Main application and state machine logic  
├── microwave.c          → Microwave operation logic  
├── microwave.h  
├── matrix_keypad.c      → Matrix keypad driver  
├── matrix_keypad.h  
├── clcd.c               → Character LCD driver  
├── clcd.h  
├── fan.c                → Fan control driver  
├── buzzer.c             → Buzzer control driver  
├── Makefile             → Build automation  
└── README.md            → Project documentation  
```

---

## 6. Hardware Requirements

* PIC Microcontroller (PIC16F877A or compatible)
* 16x2 Character LCD
* 4x4 Matrix Keypad
* Buzzer
* DC Fan or LED (for demonstration)
* Power supply (5V regulated)
* Connecting wires and breadboard

---

## 7. Software Requirements

* MPLAB X IDE
* XC8 Compiler
* Proteus (optional for simulation)
* Git

---

## 8. Functional Description

### 8.1 Initialization Phase

On system startup:

* LCD is initialized and cleared.
* Keypad interface is configured.
* Fan and buzzer pins are configured as output.
* The system enters the idle state waiting for user input.

### 8.2 Time Input Phase

* The user enters cooking time using the keypad.
* Each key press updates the time value displayed on the LCD.
* The system validates the entered time before starting cooking.

### 8.3 Cooking Phase

* When the Start key is pressed, the system transitions into cooking state.
* Fan is turned ON.
* Countdown timer starts decrementing every second.
* Remaining time is continuously updated on the LCD.

### 8.4 Completion Phase

* When the timer reaches zero:

  * Fan is turned OFF.
  * Buzzer is activated to alert the user.
  * LCD displays a completion message.

### 8.5 Reset Phase

* User can reset the system at any time.
* All outputs are turned OFF.
* System returns to idle state.

---

## 9. System Flow

```
Power ON  
   ↓  
Initialize peripherals  
   ↓  
Idle state (waiting for keypad input)  
   ↓  
Enter cooking time  
   ↓  
Press Start  
   ↓  
Cooking state (fan ON, countdown running)  
   ↓  
If time = 0  
   → Fan OFF  
   → Buzzer ON  
   → Display "Cooking Complete"  
   ↓  
Reset or restart  
```

---

## 10. Module Description

### 10.1 main.c

* Initializes all hardware modules.
* Implements the state machine for microwave operation.
* Handles user input and system transitions.

### 10.2 microwave.c / microwave.h

* Contains logic for time handling and state control.
* Manages cooking timer and system flags.
* Interfaces with fan and buzzer modules.

### 10.3 matrix_keypad.c / matrix_keypad.h

* Implements keypad scanning and debouncing.
* Converts row-column presses into key values.

### 10.4 clcd.c / clcd.h

* Implements LCD initialization and data display routines.
* Displays messages, time, and system status.

### 10.5 fan.c

* Controls fan ON and OFF through GPIO.

### 10.6 buzzer.c

* Controls buzzer ON and OFF through GPIO.

---

## 11. Build and Execution

### Step 1: Clone the repository

```bash
git clone https://github.com/your-username/microwave-oven-project.git
```

### Step 2: Open project in MPLAB X IDE

* Open MPLAB X IDE
* Select File → Open Project
* Choose the project directory

### Step 3: Compile the project

```bash
make
```

### Step 4: Program the microcontroller

* Use PICKit to flash the generated HEX file
* Or load the HEX file into Proteus for simulation

---

## 12. Simulation (Optional)

Proteus can be used to simulate the complete hardware setup by connecting:

* LCD
* Keypad
* Fan
* Buzzer

The HEX file generated by MPLAB can be loaded into the Proteus microcontroller model for testing.

---

## 13. Limitations

* Does not measure real temperature.
* Fan is used only as a heating simulation device.
* No door safety sensor implemented.
* Limited to basic microwave functions.

---

## 14. Future Enhancements

* Add temperature sensor (LM35 or DHT11).
* Implement door open/close safety interlock.
* Add EEPROM-based cooking presets.
* Add RTC module for accurate timing.
* Implement PWM-based fan speed control.
* Add graphical LCD or touch interface.
* Add IoT connectivity for remote monitoring.

---

## 15. Learning Outcomes

* Embedded C programming for PIC microcontrollers
* Peripheral interfacing techniques
* State machine design
* Modular firmware development
* Build automation using Makefile
* Real-time system logic
