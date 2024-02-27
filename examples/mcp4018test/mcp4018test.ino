/*******************************************************************************
This is a library for the MCP4018-103E digital potentiometer

Designed specifically to work with the Destination Automation Line Follower

This sensor uses the I2C protocol. The device's address is 0x2F

MIT LICENSE AGREEMENT

Copyright © 2023 Destination SPACE Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************************/

#include <Wire.h>
#include <DS_MCP4018.h>

MCP4018 MCP;

void setup(){
  Serial.begin(115200);
  while(!Serial);
  Serial.print("MCP4018 test");
  if(!MCP.begin()){
    Serial.print("\nMCP4018 could not be found...");
    while(true){
      delay(10);
    }
  }
  MCP.reset();
  MCP.setWiperResistance(5000);
}

void loop(){
  
}