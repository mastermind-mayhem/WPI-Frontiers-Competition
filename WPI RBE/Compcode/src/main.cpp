/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 1            
// intake               motor         3               
// feeder               motor         4               
// fly                  motor         5               
// flicker              motor         6               
// ultrasonic           sonar         G, H            
// cam                  vision        7               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

const float stall_current = 0.05; // Amps
const float feed_spintime = 0.15; // Seconds
const float autospeed = 100;

// Gears
const float drive_gear = 5.0/3.0;
const float intake_gear = 1;
const float feeder_gear = 1;
const float fly_gear = 1;
const float flick_gear = 3;

const double pi = 3.14159265358979323846;
const float circumfrence = 4*pi;
const int track_width = 14;
const float degperin = 360 / circumfrence;
const float gear = 5.0/3.0;

// PID Parameters 

const float mindrive = 10;
const float maxdrive = 100;
const float cautiondiff = 4;

// Line Track

const float whitemin = 90;
const float whitemax = 100;
const float blackmin = 0;
const float blackmax = 30;


void fcali() {
  flicker.setVelocity(200, velocityUnits::rpm);
  flicker.spin(reverse);
  flicker.torque();
  wait(0.25, sec);
  bool run = true;
  while (run) {
    float torqueq = flicker.torque();
    printf("%f\n",torqueq);
    if (torqueq >= stall_current) {
      wait(0.25, sec);
      flicker.stop();
      flicker.setPosition(0, degrees);
      flicker.setVelocity(80, velocityUnits::rpm);
      run = false;
    }
  }
}

void fspin_pos(float ang) {
  ang = ang * flick_gear;
  flicker.spinToPosition(ang, rotationUnits::deg);
}

void forw(float inches) {
  float rotationDeg = degperin * inches * gear;
  rotationDeg = rotationDeg - 0.25;
  RightDriveSmart.spinFor(forward, rotationDeg, degrees, autospeed, velocityUnits::rpm, false);
  LeftDriveSmart.spinFor(forward, rotationDeg, degrees, autospeed, velocityUnits::rpm);

}

void reve(float inches) {
  float rotationDeg = degperin * inches * gear;
  rotationDeg = rotationDeg - 0.25;
  RightDriveSmart.spinFor(reverse, rotationDeg, degrees, autospeed, velocityUnits::rpm, false);
  LeftDriveSmart.spinFor(reverse, rotationDeg, degrees, autospeed, velocityUnits::rpm);

}

void leftt(float deg) {
  float turnDeg = deg * track_width / 4 * gear;
  RightDriveSmart.spinFor(forward, turnDeg, degrees, autospeed, velocityUnits::rpm, false);
  LeftDriveSmart.spinFor(reverse, turnDeg, degrees, autospeed, velocityUnits::rpm);

}

void rightt(float deg) {
  float turnDeg = deg * track_width / 4 * gear;
  RightDriveSmart.spinFor(reverse, turnDeg, degrees, autospeed, velocityUnits::rpm, false);
  LeftDriveSmart.spinFor(forward, turnDeg, degrees, autospeed, velocityUnits::rpm);

}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}


void autonomous1(void) {
  Brain.Screen.print("Test");
  fcali();
  forw(3);
  intake.spin(forward);
  leftt(45);
  forw(8);
  rightt(48);
  intake.stop();
  fspin_pos(193.5);
  forw(43);
  fspin_pos(195);
  leftt(3);
  reve(55);
  forw(5);
  rightt(90);
  forw(38);
  leftt(90);
  forw(60);
  fspin_pos(210);
  

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}


void usercontrol(void) {
  // fcali();

  while (1) {

    // Flicker (A) - Spin to bucket height
    if (Controller1.ButtonA.pressing()) {
      fspin_pos(193.5);
    }

    // Flicker (Y) - Spin to 0
    if (Controller1.ButtonY.pressing()) {
      fspin_pos(0);
    }

    // Feeder (R1)
    if (Controller1.ButtonR1.pressing()) {
      feeder.spin(forward);
    } else if (!Controller1.ButtonR2.pressing()) {
      feeder.stop();
    }

    // Flywheel (R2)
    if (Controller1.ButtonR2.pressing()) {
      fly.spin(forward);
    } else if (!Controller1.ButtonR2.pressing()) {
      fly.stop();
    }

    // Flicker (X - B)
    if (Controller1.ButtonX.pressing()) {
      flicker.spin(forward);
    } else if (Controller1.ButtonB.pressing()) {
      flicker.spin(reverse);
    } else {
      flicker.stop();
    }
    wait(10, msec);
  }
}

int main() {
  flicker.setVelocity(80, velocityUnits::rpm);
  flicker.setStopping(brake);

  fly.setVelocity(300, velocityUnits::rpm);
  fly.setStopping(coast);

  feeder.setVelocity(300, velocityUnits::rpm);
  feeder.setStopping(brake);

  intake.setVelocity(150, velocityUnits::rpm);
  intake.setStopping(brake);

  Drivetrain.setDriveVelocity(300, velocityUnits::rpm);
  Drivetrain.setStopping(coast);
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous1);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
