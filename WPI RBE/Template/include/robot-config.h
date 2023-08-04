using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Left_m;
extern motor Right_m;
extern motor Arm;
extern motor Claw;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );