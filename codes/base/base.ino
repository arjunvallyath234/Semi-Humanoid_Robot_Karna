
String voice;

#define m1forward 2
#define m1backward 3
#define m2forward 4
#define m2backward 5
#define m3forward 6
#define m3backward 7
#define m4forward 8
#define m4backward 9
#define buzzer 13
#define fire 11
#define gun 10
#define pump 12
void setup() 
{  
  Serial.begin(9600);
  pinMode(m1forward, OUTPUT);
  pinMode(m1backward, OUTPUT);
  pinMode(m2forward, OUTPUT);
  pinMode(m2backward, OUTPUT);
  pinMode(m3forward, OUTPUT);
  pinMode(m3backward, OUTPUT);
  pinMode(m4forward, OUTPUT);
  pinMode(m4backward, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fire, OUTPUT);
  pinMode(gun, OUTPUT);
  pinMode(pump, OUTPUT);
}

  int forwardVal;
  int backwardVal;
  int leftVal;
  int rightVal;
  int stopVal;
  int activategunVal;
  int activatepumpVal;
  int deactivteVal;
  int fireVal;
  int deactivategunVal;
  int deactivatepumpVal;


void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Multiple Pins/ LEDs----------// 

       if(voice == "*forward")//                                FOR RED COLOUR OF THE LED 
     {
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
     digitalWrite(m1forward, HIGH);
     digitalWrite(m2forward, HIGH);
     digitalWrite(m3forward, HIGH);
     digitalWrite(m4forward, HIGH);
     digitalWrite(m1backward, LOW);
     digitalWrite(m2backward, LOW);
     digitalWrite(m3backward, LOW);
     digitalWrite(m4backward, LOW);
     }  
  else if(voice == "*backward")//                              FOR GREEN COLOUR OF THE LED !
     {
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
     digitalWrite(m1forward, LOW);
     digitalWrite(m2forward, LOW);
     digitalWrite(m3forward, LOW);
     digitalWrite(m4forward, LOW);
     digitalWrite(m1backward, HIGH);
     digitalWrite(m2backward, HIGH);
     digitalWrite(m3backward, HIGH);
     digitalWrite(m4backward, HIGH);
     }
   else if(voice =="*left")
   { 
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);  
     digitalWrite(m1forward, HIGH);
     digitalWrite(m2forward, LOW);
     digitalWrite(m3forward, LOW);
     digitalWrite(m4forward, HIGH);
     digitalWrite(m1backward, LOW);
     digitalWrite(m2backward, HIGH);
     digitalWrite(m3backward, HIGH);
     digitalWrite(m4backward, LOW);
   }

  else if(voice == "*right")
  { 
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
     digitalWrite(m1forward, LOW);
     digitalWrite(m2forward, HIGH);
     digitalWrite(m3forward, HIGH);
     digitalWrite(m4forward, LOW);
     digitalWrite(m1backward, HIGH);
     digitalWrite(m2backward, LOW);
     digitalWrite(m3backward, LOW);
     digitalWrite(m4backward, HIGH); 
  } 
 else if(voice == "*stop")
 { 
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
     digitalWrite(m1forward, LOW);
     digitalWrite(m2forward, LOW);
     digitalWrite(m3forward, LOW);
     digitalWrite(m4forward, LOW);
     digitalWrite(m1backward, LOW);
     digitalWrite(m2backward, LOW);
     digitalWrite(m3backward, LOW);
     digitalWrite(m4backward, LOW);
     
     
 }
 else if(voice == "*activate gun")
 { 
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(1000);
     digitalWrite(buzzer, HIGH);
     delay(100);
     digitalWrite(buzzer, LOW);
     delay(1000);
     digitalWrite(buzzer, HIGH);
     delay(1000);
     digitalWrite(buzzer, LOW);
     digitalWrite(gun, HIGH);
     
 }
 else if(voice == "*deactivate gun")
 { 
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      
     digitalWrite(gun, LOW);
     
 }
else if(voice == "*activate pump")
{
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(pump, HIGH);
}
else if(voice == "*deactivate pump")
{
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(pump, LOW);
}
else if(voice == "*deactivate")
{
  digitalWrite(fire,LOW);
  digitalWrite(gun, LOW);
  digitalWrite(pump, LOW);
     digitalWrite(m1forward, LOW);
     digitalWrite(m2forward, LOW);
     digitalWrite(m3forward, LOW);
     digitalWrite(m4forward, LOW);
     digitalWrite(m1backward, LOW);
     digitalWrite(m2backward, LOW);
     digitalWrite(m3backward, LOW);
     digitalWrite(m4backward, LOW);
     digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(500);
     digitalWrite(buzzer, HIGH);
     delay(100);
     digitalWrite(buzzer, LOW);
     delay(500);
     digitalWrite(buzzer, HIGH);
     delay(1000);
     digitalWrite(buzzer, LOW);
}
else if(voice == "*fire")
{
   digitalWrite(buzzer,HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      
     digitalWrite(fire,HIGH);
     delay(2000);
     digitalWrite(fire,LOW);
}
  
voice="";                                                       //Reset the variable after initiating
}
}

