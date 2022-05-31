#include <Arduino.h>
#include <ArduinoSTL.h>
#include <queue>
#include <cmath>
#include "math.h"
std::queue<int> analogValues;
int sum = 0;

void setup()
{
    for(int i = 0; i < 20; i++)
        analogValues.push(0);

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

float getForceFromAnalog(int analogValue)
{   
    // return pow(10, -2.8344 * log10(analogValue) + 8.4354);
    // return pow(10, -2.4242 * log10(analogValue) + 8.4354);
    //return 18596 * exp(-0.016 * analogValue);
    return pow(10, -3.3283 * log10(analogValue) + 10.207);
    // return pow(10, -2.2417 * log10(analogValue) + 8.0255);
    // y = -2.2417x + 8.0255
    // y = -3.3283x + 33.908

}

float getForcePercentage(int analogValue)
{
    float forceInGrams = getForceFromAnalog(analogValue);

    float forcePercentage = forceInGrams < 0 ? 0 : forceInGrams / 10000;

    return forcePercentage;
}

void loop()
{
	   // D2 Pin 20 ,D3 Pin 21 ,D4 Pin 22 ,D5 Pin 23  pins for MUX Selectors NANU!!!!!!!!!
    // UNO differnt Pins

    // int sensorIndex = 4;
    
    int sensorIndices[] = {15};

    digitalWrite(13, HIGH);

    for(auto sensorIndex : sensorIndices) {
        digitalWrite( 8, HIGH && bitRead(sensorIndex, 0));    // Pin 23 is LSB
        digitalWrite( 9, HIGH && bitRead(sensorIndex, 1));
        digitalWrite(10, HIGH && bitRead(sensorIndex, 2));
        digitalWrite(11, HIGH && bitRead(sensorIndex, 3));    // Pin 20 is MSB

        int analogValue = analogRead(14);

        int poppedValue = analogValues.front();

        analogValues.pop();

        sum -= poppedValue;

        analogValues.push(analogValue);

        sum += analogValue;

        float averageAnalog = sum / 20;

        Serial.println(averageAnalog);

        // Serial.print("The wizard says you are applying: ");

        // float forceInGrams = getForceFromAnalog(averageAnalog);

        // Serial.println(forceInGrams);

        delay(10);
    }

}
