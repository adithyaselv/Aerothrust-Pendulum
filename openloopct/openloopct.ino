const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
int minVal = 286;
int maxVal = 435;
byte i=0;
int xAng;
int yAng;
int zAng;
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
  int xRead = analogRead(xPin);
  int zRead = analogRead(zPin);
  xAng = map(xRead, minVal, maxVal, -90, 90);
  zAng = map(zRead, minVal, maxVal, -90, 90);
  double y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI)-273;
  if (digitalRead(9)==0)
  {
  {
    i++;
  }
    delay(50);//debounce
  }
  if (digitalRead(8)==0)
  {
  {
    i--;
  }
    delay(50);//debounce
  }
  if (digitalRead(7)==0)
  {
  {
    i=0;
  }
    delay(50);//debounce
  }
  if(i<-1)
  i=0;
  else if(i>256)
  i=255;
  if(i>180||i<-40)
  i=0;
  analogWrite(3,i);
  Serial.print(y);
  Serial.print("   ");
  Serial.println(i);
  delay(20);
}
