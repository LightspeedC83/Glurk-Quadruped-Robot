//https://makezine.com/article/technology/robotics/robot-quadruped-arduino-program/
//https://tote.readthedocs.io/en/latest/gait.html#:~:text=The%20creep%20gait%20is%20stable,step%20also%20takes%20some%20time.


#include <ESP32Servo.h>

//creating servo objects for each motor that needs to be controlled
Servo neck;

Servo f_left_upper;
Servo f_left_lower;

Servo f_right_upper;
Servo f_right_lower;

Servo b_left_upper;
Servo b_left_lower;

Servo b_right_upper;
Servo b_right_lower;

/////////////////////////////////////////////////////////////////////
///////////// functions for individual motor control ////////////////
/////////////////////////////////////////////////////////////////////

//functions to write the proper position to the upper motors
void f_l_u(int pos){ //front left upper
  f_left_upper.write(pos);  
}
void f_r_u(int pos){ //front right upper
  f_right_upper.write(180-pos);  
}
void b_l_u(int pos){ //back left upper
  b_left_upper.write(180-pos);  
}
void b_r_u(int pos){ //back right upper
  b_right_upper.write(pos);  
}

//functions to write the proper position to all the lower motors
void f_l_l(int pos){ //front left lower
  f_left_lower.write(180-pos);  
}
void f_r_l(int pos){ //front right lower
  f_right_lower.write(pos);  
}
void b_l_l(int pos){ //back left lower
  b_left_lower.write(pos);  
}
void b_r_l(int pos){ //back right lower
  b_right_lower.write(180-pos);  
}


/////////////////////////////////////////////////////////////////////
//////////////// functions for group motor control //////////////////
/////////////////////////////////////////////////////////////////////

//functions that controll all the motors in the upper group
void allUpper(int pos){
  f_l_u(pos);
  f_r_u(pos);
  b_l_u(pos);
  b_r_u(pos);
}

//functions that controll all the motors in the upper group
void allLower(int pos){
  f_l_l(pos);
  f_r_l(pos);
  b_l_l(pos);
  b_r_l(pos);
}


//function that makes glurk stand
void stand(){
  allUpper(50);
  delay(1500);
  allLower(40);
}

//function that makes glurk sit
void sit(){
  f_l_u(45);
  f_r_u(45);
  b_l_u(25);
  b_r_u(25);
  delay(5000);
  
  
  for (int i = 40; i<180; i++){
    delay(10);
    f_l_l(i);
    f_r_l(i);
  }
  delay(500);
  for (int i = 40; i<180; i++){
    delay(10);
    b_l_l(i);
    b_r_l(i);
  }
   
}

void wave(int amount){
  f_r_l(40);
  b_l_l(40);
  b_r_l(40);

  f_r_u(45);
  b_r_u(45);
  b_l_u(145);

  delay(500);

  f_l_u(45);
  f_l_l(180);

  for (int x = 0; x < amount; x ++){
    f_l_u(40);
    delay(250);
    f_l_u(50);
    delay(250);
  }
}

////////////////////////////////////////////////
//////////// Walking Funcitons /////////////////
////////////////////////////////////////////////

// fucntion that implements the creep walk algorithm
// ****!!**!** DOES NOT WORK ON THE SECOND HALF OF THE CYCLE ***!*!*!*!*!!**** //
void creep_walk(int timing, int cycle_repeats){ 
  int foot_lift_delay = timing/10;
  
  for (int i=0; i<=cycle_repeats; i++){  
    f_r_l(90);
    delay(foot_lift_delay);
    f_r_u(90);
    delay(foot_lift_delay);
    f_r_l(40);
    
    delay(foot_lift_delay);
    b_r_l(90);
    delay(foot_lift_delay);
    b_r_u(100);
    delay(foot_lift_delay);
    b_r_l(40);
  
    delay(timing);
  
    f_r_l(90);
    delay(foot_lift_delay);
    f_r_u(0);
    delay(foot_lift_delay);
    f_r_l(40);
  
    delay(timing);
  
    f_r_u(55);
    b_r_u(55);
    f_l_u(90);
    delay(foot_lift_delay);
    b_l_l(90);
    delay(foot_lift_delay);
    b_l_u(100);
    delay(foot_lift_delay);
    b_l_l(40);
  
    delay(timing);
    
    f_l_l(90);
    delay(foot_lift_delay);
    f_l_u(0);
    delay(foot_lift_delay);
    f_l_l(40);
    
    delay(timing);
  
    f_l_u(55);
    b_l_u(55);
    f_r_u(90);
  
    delay(timing);
  }
}

// trot gait algorithm --absolutely doesn't work rn
void trot_gait(){
  //  // setting the motors to the base position
//  allUpper(50);
//  delay(100);
//  allLower(40);
//
//  delay(1000);
//
//  //moving the right diagonal pair up
//  f_r_l(90);
//  b_l_l(90);
//
//  delay(100);
//  b_l_u(150);
//  f_r_u(25);  
//  delay(100);
//  
//  f_r_l(40);
//  b_l_l(40);
//
//  delay(1000);
//
//  //getting back to base position while moving
//  f_l_l(90);
//  b_r_l(90);
//  delay(50);
//  
//  b_l_u(50);
//  f_r_u(50);
//  delay(50);
//
//  f_l_l(40);
//  b_r_l(40);
}


//code in here runs once at program start
void setup() { 
  //defining the pins for each servo object created
  neck.attach(13);

  f_left_upper.attach(32);
  f_left_lower.attach(33);

  f_right_upper.attach(23);
  f_right_lower.attach(22);

  b_left_upper.attach(25);
  b_left_lower.attach(26);

  b_right_upper.attach(19);
  b_right_lower.attach(18);

  //making sure glurk stands up at the beginning
  stand();
  delay(100);
  stand();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  b_r_u(0);
//  creep_walk(1000,5);


}
