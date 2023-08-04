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
// Drivetrain           drivetrain    2, 1            
// Controller1          controller                    
// Intake               motor         3               
// Feeder               motor         4               
// Fly                  motor         5               
// Flick                motor         6               
// Ultrasonic           sonar         G, H            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
const double pi = 3.14159265358979323846;
const float circumfrence = 4*pi;
const int track_width = 11;
const float degperin = 360 / circumfrence;
const float gear = 5/3;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Drivetrain.setDriveVelocity(50, percent);
  Drivetrain.setStopping(brake);

  Intake.setStopping(hold);
  Intake.setVelocity(200, percent);

  Feeder.setStopping(brake);
  Feeder.setVelocity(30, percent);

  Fly.setStopping(coast);
  Fly.setVelocity(200, percent);

  Flick.setStopping(hold);
  Flick.setVelocity(100, percent);
  // while (true) {
  //   Drivetrain.drive(reverse);
  //   printf("%2.2f\n", Ultrasonic.distance(inches));
  //   if (Ultrasonic.distance(inches) <= 6) {
  //     Drivetrain.stop();
  //   }
  //   wait(1, msec);
  // }
  // while (true) {
  //   float distance = Ultrasonic.distance(inches);
  //   float stopdistance = 6;
  //   float error = 0.5;
  //   if (distance >= stopdistance-error && distance <= stopdistance+error) {
  //     Drivetrain.stop();
  //   } else if (distance > stopdistance+error) {
  //     Drivetrain.drive(reverse);
  //   } else if (distance < stopdistance-error) {
  //     Drivetrain.drive(forward);
  //   }
  // }
  
  
}
