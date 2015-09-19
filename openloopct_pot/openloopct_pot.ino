/*

Copyright (c) 2014 Adithya Selvaprithiraj.  All right reserved.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


const int potPin = A4;
byte motor_speed=0;
int potVal;
void setup()
{
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  digitalWrite(10,1);
  pinMode(11,OUTPUT);
  digitalWrite(11,0);
  pinMode(9,INPUT);
  digitalWrite(9,HIGH); //internal pullup
  pinMode(8,INPUT);
  digitalWrite(8,HIGH); //internal pullup
  pinMode(7,INPUT);
  digitalWrite(7,HIGH); //internal pullup
}
void loop()
{
  potVal=analogRead(potPin);
  int map_pot=map(-potVal,-263,-12,0,90);
  if (digitalRead(9)==0)
  {
  {
    motor_speed++;
  }
    delay(50);//debounce
  }
  if (digitalRead(8)==0)
  {
  {
    motor_speed--;
  }
    delay(50);//debounce
  }
  if (digitalRead(7)==0)
  {
  {
    motor_speed=0;
  }
    delay(50);//debounce
  }
  if(motor_speed>160||motor_speed<0)
  motor_speed=120;
  analogWrite(3,motor_speed);
  
  Serial.print(potVal);
  Serial.print("   ");
  Serial.print(map_pot);
  Serial.print("   ");
  Serial.println(motor_speed);
  delay(20);
}
