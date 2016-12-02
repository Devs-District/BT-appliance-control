
/**
   @example BT-control.ino
   @brief The arduino sketch for controlling a digital pin via bluetooth over serial.
   @author HW-Team-DD<hardware@devsdistrictnigeria.com>
   @date 2016.12

   @par Copyright:
   Copyright (c) 2016 Devs District. \n\n
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version. \n\n
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.

*/


//declare the pin the LED is connected to,this is the same pin used for the relay
int ledPin = 7;

String BTcommand; //this variable stores the command sent to the device through bluetooth

bool ledState = HIGH;  //this variable stores the state of the LED


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);	//set the pin as an OUTPUT Pin

  Serial.begin(9600); 	//initialize serial communication

}

void loop() {

  // put your main code here, to run repeatedly:

  while (!Serial.available());			//The program remains stuck here till a command is available over seral i.e a command is sent through bluetooth.


  BTcommand = Serial.readString(); //the command sent through Bluetooth is read and saved

  //set the value of the variable ledState bsed on BTcommand
  if (BTcommand == "ON")
  {
    ledState = HIGH;
  }
  else if (BTcommand = "OFF")
  {
    ledState = LOW;
  }

  digitalWrite(ledPin, ledState); //change the state of the pin based on the value of "ledState"
}
