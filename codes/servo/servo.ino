
#include <Servo.h>
Servo servo_channel_1;
Servo servo_channel_2;
Servo servo_channel_3;
Servo servo_channel_4;
Servo servo_channel_5;
Servo servo_channel_6;
#define supply 13
int hasil_servo_channel_1;
int hasil_servo_channel_2;
int hasil_servo_channel_3;
int hasil_servo_channel_4;
int hasil_servo_channel_5;
int hasil_servo_channel_6;
int hasil_serial;

void setup() {
  pinMode(supply, OUTPUT);
  Serial.begin(38400); //Baudrate adjust to your bluetooth module
  Serial.setTimeout(4);
  servo_channel_1.attach(3);
  servo_channel_2.attach(5);
  servo_channel_3.attach(6);
  servo_channel_4.attach(9);
  servo_channel_5.attach(10);
  servo_channel_6.attach(12);
  servo_channel_1.write(hasil_servo_channel_1);
  servo_channel_2.write(hasil_servo_channel_2);
  servo_channel_3.write(hasil_servo_channel_3);
  servo_channel_4.write(hasil_servo_channel_4);
  servo_channel_5.write(hasil_servo_channel_5);
  servo_channel_6.write(hasil_servo_channel_6);

}

void loop() {
  digitalWrite(supply, HIGH);
  if (Serial.available()>0) {
    hasil_serial = Serial.parseInt();
    if (hasil_serial >0 && hasil_serial <180) //Do not change this section
    {
        hasil_servo_channel_1 = hasil_serial;
        hasil_servo_channel_2 = map(hasil_serial, 0, 180, 0, 180);  //Only change on the part 0, 180
        servo_channel_1.write(hasil_servo_channel_1);
}
   if (hasil_serial >180 && hasil_serial <360) //Do not change this section
    {
        hasil_servo_channel_2 = hasil_serial;
        hasil_servo_channel_2 = map(hasil_serial, 180, 360, 0, 180); //Only change on the part 0, 180
        servo_channel_2.write(hasil_servo_channel_2);
}
   if (hasil_serial >360 && hasil_serial <540) //Do not change this section
    {
        hasil_servo_channel_3 = hasil_serial;
        hasil_servo_channel_3 = map(hasil_serial, 360, 540, 0, 180);  //Only change on the part 0, 180
        servo_channel_3.write(hasil_servo_channel_3);
}
       if (hasil_serial >540 && hasil_serial <720) //Do not change this section
    {
        hasil_servo_channel_4 = hasil_serial;
        hasil_servo_channel_4 = map(hasil_serial, 540, 720, 0, 180);  //Only change on the part 0, 180
        servo_channel_4.write(hasil_servo_channel_4);
}
       if (hasil_serial >720 && hasil_serial <900) //Do not change this section
    {
        hasil_servo_channel_5 = hasil_serial;
        hasil_servo_channel_5 = map(hasil_serial, 720, 900, 0, 180);  //Only change on the part 0, 180
        servo_channel_5.write(hasil_servo_channel_5);
}
       if (hasil_serial >900 && hasil_serial <1080) //Do not change this section
    {
        hasil_servo_channel_6 = hasil_serial;
        hasil_servo_channel_6 = map(hasil_serial, 900, 1080, 0, 180);  //Only change on the part 0, 180
        servo_channel_6.write(hasil_servo_channel_6);
    }
  }
}
