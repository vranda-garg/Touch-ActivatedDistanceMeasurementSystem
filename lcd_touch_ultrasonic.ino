#include <LiquidCrystal.h>

// Initialize LCD with RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int trigPin = 6;
const int echoPin = 5;
const int touchPin = 13;

long duration;
int distance;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(touchPin, INPUT);

  //lcd.print("Touch to Start");
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    lcd.clear();
    lcd.print("Measuring...");
    delay(1000); 

  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

  
    duration = pulseIn(echoPin, HIGH, 30000); 
  
      distance = duration * 0.034 / 2;

      
      lcd.clear();
      lcd.print("Distance: ");
      lcd.setCursor(0, 1);
      lcd.print(distance);
      lcd.print(" cm");

    
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }

    delay(3000);  
    lcd.clear();
    lcd.print("Touch to Start");
  
}
