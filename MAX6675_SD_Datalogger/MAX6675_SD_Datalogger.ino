#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library
 #include "max6675.h"

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;
int chipSelect = 10; //chipSelect pin for the SD card Reader

float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
File mySensorData; //Data object you will write your sesnor data to
 
void setup(){
Serial.begin(115200); //turn on serial monitor
pinMode(10, OUTPUT); //Must declare 10 an output and reserve it
SD.begin(10); //Initialize the SD card reader
}
 
void loop() {
tempC = thermocouple.readCelsius(); //  Read Temperature from BMP180
tempF = thermocouple.readFahrenheit(); // Convert degrees C to F

 
mySensorData = SD.open("PTData.txt", FILE_WRITE);
if (mySensorData) {
Serial.print("The Temp is: "); //Print Your results
Serial.print(tempF);
Serial.println(" degrees F");
Serial.println("");
delay(250); //Pause between readings.
 
 
mySensorData.println(tempF);                             //write temperature data to card                    
mySensorData.close();                                  //close the file
}
}

