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
#define REMOTEXY_BLUETOOTH_NAME "Smart Koozie"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 129 bytes
  { 255,1,0,4,0,122,0,19,0,0,0,83,109,97,114,116,32,75,111,111,
  122,105,101,0,31,1,106,200,1,1,5,0,129,7,26,85,9,64,13,67,
  117,114,114,101,110,116,32,84,101,109,112,101,114,97,116,117,114,101,58,0,
  67,29,43,40,10,77,2,26,2,129,9,62,87,8,0,8,84,117,114,110,
  32,111,110,32,121,111,117,114,32,107,111,111,122,105,101,32,119,105,116,104,
  0,129,70,43,10,10,64,6,194,176,70,0,2,29,76,44,22,0,106,30,
  24,38,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF

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
  RemoteXY_Init(); 
  Serial.begin(115200);

  pinMode(4, OUTPUT);         // D4 → controls MOSFET Gate
  digitalWrite(4, LOW);       // Ensure TEC is OFF at start
  RemoteXY.switch_01 = 0;     // Makes sure switch is off by default.


}

void loop() 
{ 
  RemoteXY_Handler();

  //Reads TMP36 temperature from A0
  int raw = analogRead(A0);
  float voltage = raw * (3.3 / 4095.0);  // ESP32 ADC is 0–3.3V
  float degreesC = (voltage - 0.5) * 100.0;
  float degreesF = (degreesC * (9.0 / 5.0) + 32.0);

  if (degreesF < 0){
    degreesF = -1 * degreesF;
  }

  //Prints to Serial Monitor, although this doesnt print anywhere becayse it is not connected to computer.
  Serial.print("Degrees C: ");
  Serial.print(degreesC);
  Serial.print(" °C    Degrees F: ");
  Serial.print(degreesF);
  Serial.println(" °F");

  // Sends temperature to RemoteXY app
  RemoteXY.current_temp_01 = degreesF + 20;


  // Control TEC via MOSFET using the app button
  if (RemoteXY.switch_01 == 1) {
    digitalWrite(4, HIGH);   // Turn on MOSFET so the TEC ON
  } else {
    digitalWrite(4, LOW);    // Turn off MOSFET so the TEC OFF
  }


  RemoteXY_delay(1000);  //Waits 1 seconds. Documents from the RemoteXY app says to use this function instead of the standard delay() function.
}
