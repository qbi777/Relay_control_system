# Relay_control_system
This Arduino relay control system activates three relays via pushbuttons, automatically deactivating them after 5 minutes. 
<img width="1646" alt="image" src="https://github.com/user-attachments/assets/5b3b27d8-7f95-47e3-b575-9f81a8590634">

It detects potential welded conditions and provides status updates through the serial monitor. Ideal for learning about relay management and timing functions, this project is built using Tinkercad for easy simulation and visualization.

**Abstract**
This project presents a robust relay control system implemented with Arduino, designed to enhance automation through pushbutton activation. The system manages three relays, each capable of being activated independently. With a built-in timer, each relay remains engaged for a maximum of 5 minutes, ensuring efficient control while preventing overheating and potential damage.

Additionally, the project incorporates error detection mechanisms for welded relay conditions, which could compromise system performance. By monitoring the status of each relay and providing real-time feedback via the serial monitor, users can easily identify operational issues.

This relay control system serves as an educational tool for understanding embedded systems, relay management, and time-based control mechanisms. Built and simulated using Tinkercad, it offers a practical introduction to electronics and programming, making it suitable for both beginners and experienced users in the field of automation.

**Block diagram**
![1](https://github.com/user-attachments/assets/e35b91b1-eed3-4c4e-b462-0adcc835ca5c)


**Flow Chart**
![2](https://github.com/user-attachments/assets/a10ce17d-aeba-4699-be02-6aed23cd68cc)

**Code Documentation**
Initialization:
Start the Program: The Arduino initializes, setting up serial communication.

Configure Pins: Relay pins are set as outputs, while button pins are configured as inputs with internal pull-up resistors.
Set Initial States: All relays are initially set to the OPEN state (LOW).

Main Loop:
Continuously executes the following steps:
Read Button States:
Check the state of each button (Button 1, Button 2, Button 3).
If a button is pressed (LOW), and its corresponding relay is OFF:
Activate Relay: Set the relay pin to HIGH, turning on the relay.
Update Relay State: Change the state variable (e.g., relayState1) to TRUE.
Record Start Time: Capture the current time using millis() for timer management.
Check Relay Timers:
For each relay that is currently ON:
Timer Check: If 5 minutes (300,000 ms) have elapsed since activation:
Deactivate Relay: Set the relay pin to LOW, turning off the relay.
Update Relay State: Change the state variable to FALSE.
Special Condition Check:
For each relay that is ON:
Welded Condition Check: If the relay has been ON for 10 minutes (600,000 ms):
Mark the relay as "welded" by setting the corresponding flag to TRUE.
Status Monitoring:
Output the status of each relay to the serial monitor:
Indicate whether the relay is OPEN or CLOSED.
Report any error conditions (welded status).
Repeat Loop:
The loop continues, checking for button presses, managing relay states, and monitoring conditions.

**Reusability**

This Arduino code for the relay control system exemplifies reusability through its modular and structured design, allowing for easy integration and adaptation in future projects. Key aspects include:

Modular Functions: 
The code is organized into specific functions, such as checkSpecialConditions() and monitorRelayStatus(), each handling distinct tasks. This modularity allows these functions to be reused in different applications requiring similar logic.
Parameterization Potential: Functions can be adapted to accommodate different relay configurations or timing settings, enabling customization without rewriting core logic.
Clear Structure: 
The use of boolean states and timer variables allows for straightforward adjustments and expansions. New relays or buttons can be added with minimal changes to the existing code.

Consistent Logic: 
The uniform approach to handling button presses and relay states promotes understanding and reuse across various projects, ensuring consistent behavior in different contexts.
By implementing these principles, the code not only meets the immediate requirements of this project but also serves as a versatile foundation for future developments in automation and control systems, thereby enhancing efficiency and reducing development time.


**Hardware Design Document**

<img width="676" alt="image" src="https://github.com/user-attachments/assets/bd5e8ba8-9c70-443e-9b28-5d95b0152715">

<img width="956" alt="image" src="https://github.com/user-attachments/assets/cb13487e-519e-4474-8cec-6260feec6bd4">

Thank you.
