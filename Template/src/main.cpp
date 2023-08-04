/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\maste                                            */
/*    Created:      Tue Jul 25 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Left_m               motor         1               
// Right_m              motor         2               
// Arm                  motor         3               
// Claw                 motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
const double pi = 3.14159265358979323846;
const float circumfrence = 4*pi;
const int track_width = 11;
const float degperin = 360 / circumfrence;
const float gear = 5;

void forw(float inches) {
  float rotationDeg = degperin * inches * gear;
  rotationDeg = rotationDeg - 0.25;
  Right_m.spinFor(reverse, rotationDeg, degrees, 200, velocityUnits::rpm, false);
  Left_m.spinFor(forward, rotationDeg, degrees, 200, velocityUnits::rpm);

}

void reve(float inches) {
  float rotationDeg = degperin * inches * gear;
  rotationDeg = rotationDeg - 0.25;
  Right_m.spinFor(forward, rotationDeg, degrees, 200, velocityUnits::rpm, false);
  Left_m.spinFor(reverse, rotationDeg, degrees, 200, velocityUnits::rpm);

}

void left_turn(float deg) {
  float turnDeg = deg * track_width / 4 * gear;
  Right_m.spinFor(forward, turnDeg, degrees, 200, velocityUnits::rpm, false);
  Left_m.spinFor(forward, turnDeg, degrees, 200, velocityUnits::rpm);

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  for (int i = 0; i < 5; i++) {
  forw(24);
  left_turn(90);
  }
  
  
}
