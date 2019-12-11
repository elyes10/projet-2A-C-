int led=1;
int x=0;


void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  x=Serial.read();
  if(x==1)
  {
    digitalWrite(led,HIGH);
  }
  else if(x==0)
  {
    digitalWrite(led,LOW);
  }
  
  // put your main code here, to run repeatedly:

}
