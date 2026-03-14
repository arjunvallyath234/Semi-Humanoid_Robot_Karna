#include <Servo.h>
#include <math.h>

// Servo setup
Servo servo_1, servo_2, servo_3, servo_4, servo_5, servo_6;

// Link Lengths (Adjust these to your actual robot arm in mm or cm)
const float L1 = 100.0; 
const float L2 = 100.0;
const float L3 = 50.0;

void setup() {
  Serial.begin(38400);
  servo_1.attach(3);  // Shoulder
  servo_2.attach(5);  // Elbow
  servo_3.attach(6);  // Wrist
  // ... attach others as needed
}

void solve_and_move(float x_target, float y_target, float phi_deg) {
  float phi = phi_deg * PI / 180.0; // Convert to radians

  // 1. Find Wrist Position (x2, y2)
  float x2 = x_target - L3 * cos(phi);
  float y2 = y_target - L3 * sin(phi);

  // 2. Solve for Theta 2
  float cos_theta2 = (pow(x2, 2) + pow(y2, 2) - pow(L1, 2) - pow(L2, 2)) / (2 * L1 * L2);
  cos_theta2 = constrain(cos_theta2, -1, 1); // Safety check for math errors
  float theta2 = atan2(sqrt(1 - pow(cos_theta2, 2)), cos_theta2); // Elbow up solution

  // 3. Solve for Theta 1
  float theta1 = atan2(y2, x2) - atan2(L2 * sin(theta2), L1 + L2 * cos(theta2));

  // 4. Solve for Theta 3
  float theta3 = phi - theta1 - theta2;

  // Convert radians to degrees for servos
  int s1 = (int)(theta1 * 180.0 / PI);
  int s2 = (int)(theta2 * 180.0 / PI);
  int s3 = (int)(theta3 * 180.0 / PI);

  // Write to servos (Adjust offsets if 0 degrees isn't your center)
  servo_1.write(constrain(s1, 0, 180));
  servo_2.write(constrain(s2, 0, 180));
  servo_3.write(constrain(s3, 0, 180));
}

void loop() {
  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    
    // Example: If value is 2000, trigger a specific IK movement
    if (val == 2000) {
      solve_and_move(150, 50, 0); // Move to x=150, y=50, angle=0
    } 
    // Otherwise, keep your original manual override logic
    else if (val > 0 && val < 180) {
      servo_1.write(val);
    }
  }
}