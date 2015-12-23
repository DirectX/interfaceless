#include "ps2dev.h" // to emulate a PS/2 device

// data:text/html;base64,PGgxPkhlbGxvPC9oMT4NCjxzY3JpcHQ+DQphbGVydCgnMTIzJykNCjwvc2NyaXB0Pg==

int led = 13;

PS2dev keyboard(3, 2); // PS2dev object (2:data, 3:clock)
int enabled = 0;       // pseudo variable for state of "keyboard"

void ack() {
    //acknowledge commands
    while (keyboard.write(0xFA));
}

int keyboardcommand(int command) {
    unsigned char val;
    
    switch (command) {
        case 0xFF: //reset
            ack();
            //the while loop lets us wait for the host to be ready
            while (keyboard.write(0xAA) != 0);
            break;
    
        case 0xFE: //resend
            ack();
            break;
    
        case 0xF6: //set defaults
            //enter stream mode
            ack();
            break;
    
        case 0xF5: //disable data reporting
            //FM
            enabled = 0;
            ack();
            break;
    
        case 0xF4: //enable data reporting
            //FM
            enabled = 1;
            ack();
            break;
    
        case 0xF3: //set typematic rate
            ack();
            keyboard.read(&val); //do nothing with the rate
            ack();
            break;
    
        case 0xF2: //get device id
            ack();
            keyboard.write(0xAB);
            keyboard.write(0x83);
            break;
    
        case 0xF0: //set scan code set
            ack();
            keyboard.read(&val); //do nothing with the rate
            ack();
            break;
    
        case 0xEE: //echo
            //ack();
            keyboard.write(0xEE);
            break;
    
        case 0xED: //set/reset LEDs
            ack();
            keyboard.read(&val); //do nothing with the rate
            ack();
            break;
    }
}

void SendKey(char inChar) {
    // scancodes: http://www.computer-engineering.org/ps2keyboard/scancodes2.html

    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    char scanCode;
    int isShift = false;
    
    switch (inChar) {
        case '0':
            scanCode = 0x45;
            break;
      
        case '1':
            scanCode = 0x15;
            break;
      
        case '2':
            scanCode = 0x1E;
            break;
      
        case '3':
            scanCode = 0x26;
            break;
      
        case '4':
            scanCode = 0x25;
            break;
      
        case '5':
            scanCode = 0x2E;
            break;

        case '6':
            scanCode = 0x36;
            break;
      
        case '7':
            scanCode = 0x3D;
            break;
      
        case '8':
            scanCode = 0x3E;
            break;

        case '9':
            scanCode = 0x46;
            break;
      
        case '+':
            scanCode = 0x55;
            isShift = true;
            break;
      
        case '-':
            scanCode = 0x4E;
            break;
        
        case '*':
            scanCode = 0x3E;
            isShift = true;
            break;
            
        case '/':
            scanCode = 0x4A;
            break;

        case '=':
            scanCode = 0x55;
            break;
            
        case 'a':
            scanCode = 0x1C;
            break;

        case 'b':
            scanCode = 0x32;
            break;

        case 'c':
            scanCode = 0x21;
            break;

        case 'd':
            scanCode = 0x23;
            break;

        case 'e':
            scanCode = 0x24;
            break;

        case 'f':
            scanCode = 0x2B;
            break;
            
        case 'g':
            scanCode = 0x34;
            break;

        case 'h':
            scanCode = 0x33;
            break;

        case 'i':
            scanCode = 0x43;
            break;

        case 'j':
            scanCode = 0x3B;
            break;

        case 'k':
            scanCode = 0x42;
            break;

        case 'l':
            scanCode = 0x4B;
            break;
            
        case 'm':
            scanCode = 0x3A;
            break;
    
        case 'n':
            scanCode = 0x31;
            break;
        
        case 'o':
            scanCode = 0x44;
            break;

        case 'p':
            scanCode = 0x4D;
            break;

        case 'q':
            scanCode = 0x15;
            break;

        case 'r':
            scanCode = 0x2D;
            break;

        case 's':
            scanCode = 0x1B;
            break;

        case 't':
            scanCode = 0x2C;
            break;

        case 'u':
            scanCode = 0x3C;
            break;

        case 'v':
            scanCode = 0x2A;
            break;

        case 'w':
            scanCode = 0x1D;
            break;

        case 'x':
            scanCode = 0x22;
            break;

        case 'y':
            scanCode = 0x35;
            break;

        case 'z':
            scanCode = 0x1A;
            break;

        case 'A':
            scanCode = 0x1C;
            isShift = true;
            break;

        case 'B':
            scanCode = 0x32;
            isShift = true;
            break;

        case 'C':
            scanCode = 0x21;
            isShift = true;
            break;

        case 'D':
            scanCode = 0x23;
            isShift = true;
            break;

        case 'E':
            scanCode = 0x24;
            isShift = true;
            break;

        case 'F':
            scanCode = 0x2B;
            isShift = true;
            break;
            
        case 'G':
            scanCode = 0x34;
            isShift = true;
            break;

        case 'H':
            scanCode = 0x33;
            isShift = true;
            break;

        case 'I':
            scanCode = 0x43;
            isShift = true;
            break;

        case 'J':
            scanCode = 0x3B;
            isShift = true;
            break;

        case 'K':
            scanCode = 0x42;
            isShift = true;
            break;

        case 'L':
            scanCode = 0x4B;
            isShift = true;
            break;
            
        case 'M':
            scanCode = 0x3A;
            isShift = true;
            break;
    
        case 'N':
            scanCode = 0x31;
            isShift = true;
            break;
        
        case 'O':
            scanCode = 0x44;
            isShift = true;
            break;

        case 'P':
            scanCode = 0x4D;
            isShift = true;
            break;

        case 'Q':
            scanCode = 0x15;
            isShift = true;
            break;

        case 'R':
            scanCode = 0x2D;
            isShift = true;
            break;

        case 'S':
            scanCode = 0x1B;
            isShift = true;
            break;

        case 'T':
            scanCode = 0x2C;
            isShift = true;
            break;

        case 'U':
            scanCode = 0x3C;
            isShift = true;
            break;

        case 'V':
            scanCode = 0x2A;
            isShift = true;
            break;

        case 'W':
            scanCode = 0x1D;
            isShift = true;
            break;

        case 'X':
            scanCode = 0x22;
            isShift = true;
            break;

        case 'Y':
            scanCode = 0x35;
            isShift = true;
            break;

        case 'Z':
            scanCode = 0x1A;
            isShift = true;
            break;
            
        default:
            delay(10);
            digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
            Serial.write('-');
            return;
    }

    if (isShift) {
        // Press left shift
        keyboard.write(0x12);
    }

    // Press key
    keyboard.write(scanCode);
    
    // Release key
    keyboard.write(0xF0);
    keyboard.write(scanCode);
    
    if (isShift) {
        // Release left shift
        keyboard.write(0xF0);
        keyboard.write(0x12);
    }

    delay(10);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

    Serial.write(inChar);
}


void setup() {
    pinMode(led, OUTPUT);
    
    Serial.begin(9600);

    // send the keyboard start up
    while (keyboard.write(0xAA) != 0);
    
    delay(10);
}

void loop() {
    // Processing keyboard command from host (e.g. software-activated NumLock)
    
    unsigned char c;
        
    if ((digitalRead(3) == LOW) || (digitalRead(2) == LOW)) {
        while (keyboard.read(&c));
        keyboardcommand(c);
    }
    
    if (Serial.available() > 0) {
        // read incoming serial data:
        char inChar = Serial.read();
        
        SendKey(inChar);
    } 
}
