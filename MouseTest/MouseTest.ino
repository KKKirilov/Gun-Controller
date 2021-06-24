#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

int onState = 0;
const int onPin = A2;

const int button1 = 4;
const int button2 = 5;
int responseDelay = 10;
void setup() {
  pinMode(onPin, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
  Wire.begin();
  Mouse.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }
}

void loop() {
  onState = digitalRead(onPin);
  if (onState == HIGH){
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx - 400) / 200; // "-400" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy = -(gz - 200) / 200; // same here about "-200"
  int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);

  if (buttonState1 == HIGH) {
    Mouse.press(MOUSE_LEFT);
    delay(100);
    Mouse.release(MOUSE_LEFT);
    delay(200);
  }
  else if (buttonState2 == HIGH) {
    Mouse.press(MOUSE_RIGHT);
    delay(100);
    Mouse.release(MOUSE_RIGHT);
    delay(200);
  }
  Mouse.move(vx, vy);

  delay(20);
  }
}
