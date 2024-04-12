# IoT Exercises

## 1-Arduino L Pin Blink

![image](https://github.com/busecoban/IoT_Exercises/assets/73944611/157345ac-3d61-4c26-9e71-35557c6f6508)
```cpp
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
```

## 2-Arduino and Led Blink

![IMG_0795](https://github.com/busecoban/IoT_Exercises/assets/73944611/bb7d4aec-2fe5-45cb-bb73-2abb5b074e21)

```cpp
#define led 2

void setup()
{
pinMode(led,OUTPUT);
}

void loop()
{
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);

}
//Orange 330 ohm
```

## 3-Arduino and Led Blink with Switch 

![IMG_0800](https://github.com/busecoban/IoT_Exercises/assets/73944611/624f0643-0c9c-4de0-a07f-37e1be9e69e0)


![image](https://github.com/busecoban/IoT_Exercises/assets/73944611/7f0ce2e1-24d4-4322-bb60-904e804267b0)

```cpp
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
```
