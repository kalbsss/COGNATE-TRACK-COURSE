<img width="921" height="629" alt="image" src="https://github.com/user-attachments/assets/b1f86182-02c7-4c19-b363-d66ed92db564" />


This Tinkercad circuit features a breadboard on the far left, an Arduino Uno board on the bottom right, and a parallel array of ten red LEDs with current-limiting resistors spanning across the top right.

Starting on the left, a black ground wire connects a GND pin on the Arduino to the negative power rail of the breadboard, which is then jumped down to the lower rail and also extended to the right via a long green wire bundle to act as a common ground. Moving to the bottom right, the Arduino Uno is powered via a black USB cable plugged into its left side, while ten individual green control wires run upwards from Digital Pins 2 through 11. Finally, on the upper right, these ten control wires connect to the bottom of ten vertical resistors, which flow upwards into the anodes of ten red LEDs whose cathodes are all tied back to the common green ground line coming from the breadboard.
