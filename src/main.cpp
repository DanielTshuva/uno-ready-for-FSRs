#include <Arduino.h>

void setup()
{
    // D2 Pin 20 ,D3 Pin 21 ,D4 Pin 22 ,D5 Pin 23  pins for MUX Selectors NANU!!!!!!!!!
    // UNO differnt Pins
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(13,OUTPUT);     // INPUT
    pinMode(14,INPUT);
    Serial.begin(9600);
}

void loop()
{
	   // D2 Pin 20 ,D3 Pin 21 ,D4 Pin 22 ,D5 Pin 23  pins for MUX Selectors NANU!!!!!!!!!
    // UNO differnt Pins

    // int sensorIndex = 4;
    
    int sensorIndices[] = {0, 4, 7, 11};

    digitalWrite(13, HIGH);

    for(auto sensorIndex : sensorIndices) {
        digitalWrite( 8, HIGH && bitRead(sensorIndex, 0));    // Pin 23 is LSB
        digitalWrite( 9, HIGH && bitRead(sensorIndex, 1));
        digitalWrite(10, HIGH && bitRead(sensorIndex, 2));
        digitalWrite(11, HIGH && bitRead(sensorIndex, 3));    // Pin 20 is MSB

        Serial.print("Analog Read: ");
        Serial.println(analogRead(14));

        delay(250);
    }

}
