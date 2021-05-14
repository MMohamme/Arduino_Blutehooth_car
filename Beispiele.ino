#include <Servo.h>
Servo One;
Servo Two;
Servo Three;
char lastValue;  
char blueToothVal;
int trigger=7;//Abstandsensor Pin7 
int echo=6;//Abstandsensor Pin6 
long dauer=0;//Abstandsensor
long entfernung=0;//Abstandsensor
int piezo=5; //Lautsprecher

//int GSM1 = 10;
int in1 = 5;
int in2 = 4;



//int GSM2 = 5;
int in3 = 3;
int in4 = 2;

void setup()
{
  One.attach(8);//Servo
  Two.attach(9);//Servo
  Three.attach(10);//Servo
  //pinMode(GSM1, OUTPUT);    
  //pinMode(GSM2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT); //HC
  pinMode(trigger, OUTPUT);

pinMode(echo, INPUT);

pinMode(piezo, OUTPUT);
}
void loop()
{
  Servomotor();
   Motor();
}
void Motor(){
  
   digitalWrite(in1, HIGH);  
  digitalWrite(in2, LOW);

 // analogWrite(GSM1, 200);   
  digitalWrite(in3, HIGH);  
  digitalWrite(in4, LOW);

 // analogWrite(GSM2, 200);   
  delay(2000);

  digitalWrite(in1, LOW);   // Durch die Veränderung von HIGH auf LOW (bzw. LOW auf HIGH) wird die Richtung der Rotation verändert.
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);

  digitalWrite(in1, LOW);   // Anschließend sollen die Motoren 2 Sekunden ruhen.
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(2000);
  }
  void Servomotor(){
One.write(0); 

delay(3000); 

One.write(90);

delay(3000); 

One.write(180); 

delay(3000);

One.write(20); 

delay(3000);

    
    
    }
void Abstandsensor(){
  digitalWrite(trigger, LOW);

delay(5);

digitalWrite(trigger, HIGH);

delay(10);

digitalWrite(trigger, LOW);

dauer = pulseIn(echo, HIGH);

entfernung = (dauer/2) * 0.03432;

if (entfernung >= 500 || entfernung <= 0)

{

Serial.println("Kein Messwert");

}

else

{

Serial.print(entfernung);

Serial.println(" cm");

}
//Es wird eine weitere IF-Bedingung erstellt: 
 
if (entfernung <= 80)//Wenn der Wert für die Entfernung unter oder gleich 80 ist, dann... 
{
digitalWrite(piezo,HIGH); //...fange an zu piepsen. 
}

else  //Und wenn das nicht so ist... 
{
digitalWrite(piezo,LOW);  //...dann sein leise. 
}

delay(1000);
  
  }
    
    void HC(){
      
      if(Serial.available()) //wenn Daten empfangen werden...      
{
    blueToothVal=Serial.read();//..sollen diese ausgelesen werden
  }
  if (blueToothVal=='1') //wenn das Bluetooth Modul eine „1“ empfängt..
  {
    digitalWrite(13,HIGH);   //...soll die LED leuchten
    if (lastValue!='1') //wenn der letzte empfangene Wert keine „1“ war...
      Serial.println(F("LED is on")); //..soll auf dem Seriellen Monitor „LED is on“ angezeigt werden
    lastValue=blueToothVal;
  }
  else if (blueToothVal=='0') //wenn das Bluetooth Modul „0“ empfängt...
  {           
    digitalWrite(13,LOW);  //..soll die LED nicht leuchten
    if (lastValue!='0'){  //wenn der letzte empfangene Wert keine „0“ war...
      Serial.println(F("LED is off")); //..soll auf dem seriellen Monitor „LED is off“ angezeigt werden 
    lastValue=blueToothVal;
  }
      
      }
    }
