#define led1 2
#define led2 3
#define button 7

int button_status=0;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_status=digitalRead(button);

  if(button_status==1) 
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);

  }else{
     digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
  }
}
