#include <Keypad.h>


const int segA = 10;
const int segB = 11;
const int segC = 12;
const int segD = 13;
const int segE = A0;
const int segF = A1;
const int segG = A2;
const int segDP = A3;


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};   
byte colPins[COLS] = {5, 4, 3, 2};   

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


const byte numberSegments[10] = {
  B11111100,  
  B01100000, 
  B11011010,  
  B11110010,  
  B01100110, 
  B10110110,  
  B10111110, 
  B11100000,  
  B11111110,  
  B11110110   
};


const byte letterSegments[6] = {
  B11101110, 
  B00111110, 
  B10011100,  
  B01111010,  
  B10011110,  
  B10001110   
};

void setup() {
  
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  
 
  displayNumber(100);
  
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key != NO_KEY) {
    Serial.println(key);
    
    
    if (key >= '0' && key <= '9') {
      displayNumber(key - '0');
    }
    else if (key >= 'A' && key <= 'F') {
      displayLetter(key - 'A');
    }
    else if (key == '*') {
      displayClear();  
    }
    else if (key == '#') {
      displayNumber(8); 
    }
    else if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
      displayLetter(key - 'A' + 1);  
    }
  }
}

void displayNumber(int num) {
  if (num >= 0 && num <= 9) {
    digitalWrite(segA, bitRead(numberSegments[num], 7));
    digitalWrite(segB, bitRead(numberSegments[num], 6));
    digitalWrite(segC, bitRead(numberSegments[num], 5));
    digitalWrite(segD, bitRead(numberSegments[num], 4));
    digitalWrite(segE, bitRead(numberSegments[num], 3));
    digitalWrite(segF, bitRead(numberSegments[num], 2));
    digitalWrite(segG, bitRead(numberSegments[num], 1));
    digitalWrite(segDP, bitRead(numberSegments[num], 0));
  }
}

void displayLetter(int let) {
  if (let >= 0 && let <= 5) {
    digitalWrite(segA, bitRead(letterSegments[let], 7));
    digitalWrite(segB, bitRead(letterSegments[let], 6));
    digitalWrite(segC, bitRead(letterSegments[let], 5));
    digitalWrite(segD, bitRead(letterSegments[let], 4));
    digitalWrite(segE, bitRead(letterSegments[let], 3));
    digitalWrite(segF, bitRead(letterSegments[let], 2));
    digitalWrite(segG, bitRead(letterSegments[let], 1));
    digitalWrite(segDP, bitRead(letterSegments[let], 0));
  }
}

void displayClear() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
}
