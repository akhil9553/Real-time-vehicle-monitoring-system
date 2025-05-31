Real-Time Vehicle Status Monitoring Using CAN
-----------------------------------------------
A compact vehicle status monitoring system utilizing the Controller Area Network (CAN) protocol on the LPC2129 ARM7 microcontroller. This system is designed to display critical vehicle parameters in real time, including fuel percentage, indicator status, and airbag status/activation, all coordinated over a CAN bus. 

🔧 Key Features
----------------------

⛽ Fuel Percentage Monitoring
-------------------------------
Monitors fuel gauge sensor information.

Displays fuel percentage on an LCD. 

Transmits fuel information to the Main Node via CAN. 

🚦 Indicator Status Display
---------------------------
Receives indicator signals from the Main Node via CAN. 

Controls indicator signals connected to the microcontroller, typically using LEDs. 

External interrupts (SW1, SW2) on the Main Node trigger indicator signals. 

💥 Airbag Status/Activation Monitoring
----------------------------------------
Utilizes an MMA7660 accelerometer sensor for motion sensing. 

Displays accelerometer information, which can be used to infer airbag status/activation. 

📶 CAN Bus Communication
----------------------------
Employs the CAN protocol for real-time data exchange. 

Requires understanding of the CAN interface and protocol. 

CAN Transceiver (MCP2551) is a required hardware component. 

🛠️ Hardware Components
--------------------------
🎛️ LPC2129 Microcontroller
-------------------------
ARM7TDMI core. 

Handles general-purpose I/O, ADC, Interrupts, and CAN interface. 

A core component for processing and communication. 

🔄 CAN Transceiver (MCP2551)
--------------------------------
Enables communication over the CAN bus. 

💡 LEDs
----------------
Used for displaying indicator signals. 

📟 LCD
---------------
Used for displaying critical vehicle parameters like fuel percentage and accelerometer information. 

📈 MMA7660 (Accelerometer)
-----------------------------
Sensor for reading accelerometer information, contributing to airbag status/activation. 

⛽ Fuel Gauge
-------------
Sensor for reading fuel level information. 

🔌 Switches (SW1, SW2)
---------------------------
Accessed via external interrupts to generate indicator signals. 

↔️ USB to UART Converter
-------------------------
Hardware requirement for interaction and potentially flashing. 

💻 Software & Firmware
----------------------

Embedded C Programming
-----------------------
The core programming language for the project. 

KEIL-C Compiler
---------------
Used for compiling the Embedded C code. 

Flash Magic
------------
Software used for flashing the compiled code onto the LPC2129. 

🔁 System Logic
------------------
Main Node 🧠
--------------
Reads and displays accelerometer sensor information on the LCD. 

Sends indicator signals to the Indicator Node based on generated interrupts (from SW1, SW2). 

Receives and displays fuel percentage from the Fuel Node on the LCD. 

Indicator Node 🚦
------------------
Continuously waits for data from the Main Node via CAN. 

Controls indicator signals (LEDs) based on received data. 

Fuel Node ⛽
----------------
Continuously reads fuel gauge sensor information using the on-chip ADC. 

Sends the fuel information to the Main Node. 

✅ Testing Checklist
----------------------
✅ LCD displays character, string, and integer constants. 

✅ On-chip ADC reads variable voltage and displays it on the LCD. 

✅ Logic for reading and displaying fuel percentage on the LCD is developed and tested. 

✅ External interrupts code functions, incrementing a count value on the LCD when an interrupt is raised. 

✅ Logic for reading and displaying accelerometer sensor information on the LCD is developed. 
✅ Basic CAN code is downloaded, tested on hardware, and its working analyzed. 
✅ The integrated system provides the expected output, signifying project completion. 
