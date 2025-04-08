/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 124 bytes
  { 255,1,0,4,0,117,0,19,0,0,0,0,31,1,106,200,1,1,5,0,
  10,39,89,24,24,48,4,26,31,79,78,0,31,79,70,70,0,129,6,6,
  90,15,64,177,83,109,97,114,116,32,75,111,111,122,105,101,0,129,7,26,
  85,9,64,13,67,117,114,114,101,110,116,32,84,101,109,112,101,114,97,116,
  117,114,101,58,0,67,29,43,40,10,77,2,26,2,129,2,66,99,10,0,
  8,67,111,111,108,32,121,111,117,114,32,75,111,111,122,105,101,32,119,105,
  116,104,58,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t pushSwitch_01; // =1 if state is ON, else =0

    // output variables
  float current_temp_01;

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);



}

void loop() 
{ 
  RemoteXY_Handler ();
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 

  //Reads temperature from temperature sensor. Data is stored in A0.
  int raw = analogRead(A0);
  float voltage = raw * (3.3 / 4095.0);  // Scale for ESP32's ADC
  float degreesC = (voltage - 0.5) * 100.0;
  float degreesF = degreesC * 9.0 / 5.0 + 32.0;

  Serial.print("Degrees C: ");
  Serial.print(degreesC);
  Serial.print(" °C");

  Serial.print("    Degrees F: ");
  Serial.print(degreesF);
  Serial.println(" °F");

  //Update temperature on phone 

  RemoteXY.current_temp_01 = degreesF;

  RemoteXY_delay(5000);


}