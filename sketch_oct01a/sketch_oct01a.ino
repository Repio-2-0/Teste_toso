#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Servo.h>

Servo myservo // Servo
Adafruit_BMP085 bmp; // Termômetro

int ant = 0;
int pos = 120;

void setup() {
  Serial.begin(9600); //Inicia conversa com o Arduino
  pinMode (12, OUTPUT); //Porta do Buzzer
  pinMode (11, INPUT); //Porta do Readswitch
  pinMode (9, OUTPUT); //Porta do LED
  myservo.attach(8); //Porta do Servo
  Serial.println("Qual a temperatura?"); //Imprimi essa pergunta
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");  
  }  
}

void loop() {
    myservo.write(ant); //Diz posição inicial do Servo
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature()); //Imprimi temperatura
    Serial.print(" *C");
    delay(3000);
    if (bmp.readTemperature() > 25){ //Se a temperatura estive maior que 25*C
    digitalWrite(12, HIGH); //Liga o Buzzer
    delay (1000); //Espera 1 segundo
    myservo.write(pos); //Aciona o Servo
     }
     delay(5000); //Espera 5 segundos
    {
 if (digitalRead (11) == 0){ //Se o valor do Sensor do Reedswitch estiver 0
    digitalWrite(9, HIGH); //Liga LED
}   
    else if (digitalRead (11) == 1) //Se o valor do Sensor do Reedswitch estiver 1
    digitalWrite(9, LOW); //Desliga o LED
}
delay (10000000); //Tempo de espera gigantesco
}
