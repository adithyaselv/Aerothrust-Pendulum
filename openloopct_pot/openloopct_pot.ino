const int potPin = A4;
byte i=0;
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
  if(i>160||i<0)
  i=120;
  analogWrite(3,i);
  Serial.print(potVal);
  Serial.print("   ");
  Serial.print(map_pot);
  Serial.print("   ");
  Serial.println(i);
  delay(20);
}
