//reversew car parking sensor

int buzPin = 7;       // pin for Buzzer;

int trigPin = 8;      // pin for trigger pin of UltraSonic sensor; 

int echoPin = 4;      // pin for echo pin of UltraSonic sensor;

float speed = 0.0347; //declare speed of sound;

float dist;           //declare variable for containing distance sensed;

float pingTime;       //declare variable for containing echo time;

int buzNear = 20;     //declare buzzing time for very close proximity;

int buzHigh = 50;     //declare buzzing time for close proximity;

int buzMid  =150;     //declare buzzing time for mid proximity;

int buzFar = 500;     //declare buzzing time for far off object;

int delayFar = 260;


void setup() {
  pinMode(buzPin,OUTPUT);     // buzzer & trigger pin are connected to output pin;
  pinMode(trigPin,OUTPUT);    
  pinMode(echoPin,INPUT);     // echo pin ; is connected to output pin

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);          //creating a pulse for sensing distance;
  pingTime = pulseIn(echoPin,HIGH);   //read the echoTime;
  dist = (speed*pingTime*0.5);        
  
  if(dist<=10.0){
    digitalWrite(buzPin,HIGH);         //change in frequency according to the time distance;
    delay(20);
    digitalWrite(buzPin,LOW);
    delay(20);
  }  
  else if(dist<=30.0 && dist>10.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzHigh);
    digitalWrite(buzPin,LOW);
    delay(buzHigh);
  }
  else if((dist>30.0) && (dist<60.0))
  {
    digitalWrite(buzPin,HIGH);
    delay(buzMid);
    digitalWrite(buzPin,LOW);
    delay(buzMid);
  }
  else if(dist>=60.0 && dist<120.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzFar);
    digitalWrite(buzPin,LOW);
    delay(delayFar);
  }

  
}
