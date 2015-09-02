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

const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
int minVal = 286;
int maxVal = 435;
int p[2];
double Kp=0.005;
double x;
double y;
double z;   
int xAng;
int yAng;
int zAng;
int SETANGLE=10;
float previ=0;
float i=0;
void setup()
{
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  digitalWrite(10,1);
  pinMode(11,OUTPUT);
  digitalWrite(11,0);
}
void loop()
{
  double filteredp=0;
  double oplangle;
  double filteredc;
 if(Serial.available()>0)
 { 
  for(int i=0;i<2;i++)
  {
    p[i]=Serial.read()-48;
    delay(30);
  }
  int dat=(p[0]*10)+(p[1]);
  SETANGLE=dat;
 }
  int error;
  for(int j=0;j<10;j++)
  {
  int xRead = analogRead(xPin);
  int zRead = analogRead(zPin);
  xAng = map(xRead, minVal, maxVal, -90, 90);
  zAng = map(zRead, minVal, maxVal, -90, 90);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI)-273;
  filteredp += y;
  if(j==9)
  filteredp = filteredp/10;
  }
  oplangle=(0.001*previ*previ)+(0.21*previ)-6.5;
  filteredc=(filteredp+oplangle)/2;
  error=SETANGLE-(int(filteredc));
  i = i+(error*Kp);
  analogWrite(3,byte(i));
  Serial.print(filteredc);
  Serial.print("  ");
  Serial.print(error);
  Serial.print("  ");
  Serial.println(i);
  previ=i;
}
