const int potPin = A4;
int p[2];
double Kp=0.009;
double Kd=0.00;
double Ki=0.0000;
float integral;
int SETANGLE=0;
float preverror=0;
float i=22;
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
  int error;
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
  int potVal=analogRead(potPin);
  int map_pot=map(-potVal,-263,-12,0,90);
  error=SETANGLE-(map_pot);
  integral += error;
  if(integral>1000)
  integral=1000;
  i = i+(error*Kp)+((error-preverror)*Kd)+(integral*Ki);
  if(i>220||i<0)
  i=190;
  analogWrite(3,byte(i));
  Serial.print(map_pot);
  Serial.print("  ");
  Serial.print(error);
  Serial.print("  ");
  Serial.println(i);
  preverror=error;
}
