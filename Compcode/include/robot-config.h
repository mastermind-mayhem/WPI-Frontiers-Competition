using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor RightDriveSmart;
extern motor LeftDriveSmart;
extern motor intake;
extern motor feeder;
extern motor fly;
extern motor flicker;
extern sonar ultrasonic;
extern signature cam__SIG_1;
extern signature cam__SIG_2;
extern signature cam__SIG_3;
extern signature cam__SIG_4;
extern signature cam__SIG_5;
extern signature cam__SIG_6;
extern signature cam__SIG_7;
extern vision cam;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );