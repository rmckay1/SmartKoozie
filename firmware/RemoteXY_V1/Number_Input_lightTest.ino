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
uint8_t RemoteXY_CONF[] =   // 30 bytes
  { 255,2,0,0,0,23,0,19,0,0,0,0,31,1,106,200,1,1,1,0,
  7,32,88,40,10,118,64,2,26,2 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int16_t edit_01; // -32768 .. +32767

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
  pinMode(LED_BUILTIN, OUTPUT);  
  
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  int x = 5;
  if(RemoteXY.edit_01 >= x){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("It is on! because user inputted ");
    Serial.print(RemoteXY.edit_01);
    Serial.println("!");
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("It is off because user inputted a number less than ");
    Serial.print(x);
    Serial.println(".");

  }

  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}