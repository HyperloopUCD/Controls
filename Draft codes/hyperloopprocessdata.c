#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pod_Struct{            // Define Pod
  char name[10];                      // Pod has unique name
  double time;                        // Pod time based on its clock
  double position;                    // Pod position in tunnel
  double velocity;                    // Pod instantaneous velocity at time
  double accelaration;                // Pod instantaneous accelaration at time
}Pod;

Pod makePod(char name[10], double tim, double pos, double vel, double acc); // Initializes pod
bool podMonitor(Pod *pod, double expvals[4][2], FILE** datasheets); // Monitors optimal functioning of pod
bool detectReflexiveStrip(); // External function which returns true if sensor detects strip
double getTime(); // External function which returns the time based on the pods clock
double calcPosition(Pod *pod); // Function to calculate position of pod
double calcVelocity(Pod *pod, double previous_time, double previous_position); // Function to calculate velocity of pod
double calcAccelaration(Pod *pod, double previous_time, double previous_velocity); // Function to calculate accelaration of pod
double getPosition(Pod *pod); // Return current pod position
double getVelocity(Pod *pod); // Return current pod velocity
double getAccelaration(Pod *pod); // Return current pod accelaration
void fileWrite(Pod *pod, FILE** datasheet); // Fucntion to write pod struct variables to datasheet

int main(int argc, char *argv[]){
  const double track_length ; // Constant value equal to the lenght of the tunnel
  double expected_vals[4][2]; // Two dimensional array containing expected values, three rows: position, velocity, accelaration, two columns: min,max
  Pod oneLoop = makePod("OneLoop",0.0,0.0,0.0,0.0); // Create pod
  FILE **complete_data =malloc(sizeof(FILE*)*(argc-1)); // Define array of files
  FILE *time_data_sheet = fopen(argv[1],"w");
  FILE *position_data_sheet = fopen(argv[2],"w"); // Initialize position data sheet
  FILE *velocity_data_sheet = fopen(argv[3],"w"); // Initialize velocity data sheet
  FILE *accelaration_data_sheet = fopen(argv[4],"w"); // Initialize accelaration data sheet
  complete_data[0] = time_data_sheet; // Assign first element of cmoplete sheet to time
  complete_data[1] = position_data_sheet; // Assign first element of complete sheet to position sheet
  complete_data[2] = velocity_data_sheet; // Assign second element of complete sheet to velocity sheet
  complete_data[3] = accelaration_data_sheet; // Assign third element of complete sheet to accelaration sheet
  while(getPosition(&oneLoop)!=track_length){  // Monitoring continues for entire lenght of tunnel
    if(!podMonitor(&oneLoop,expected_vals,complete_data))  // Return 0 if the values are critically different indicating Pod Faliure
      return 0;
  }
  return 1; // Return 1 if the pod completes trip appropriately
}

Pod makePod(char name[10], double tim, double pos, double vel, double acc){
  Pod pod;                        // Declare Pod
  strcpy(pod.name,name);          // Assign parameters to pod structure variables
  pod.time = tim;
  pod.position = pos;
  pod.velocity = vel;
  pod.accelaration = acc;
  return pod;                     // Return Initialized pod
}

bool podMonitor(Pod *pod, double expvals[4][2], FILE** datasheets){  // Checks if Pod is function as expected
  bool change_in_state = detectReflexiveStrip();   // Detect reflexive strip
  double prev_tim = pod->time;  // Store previous values of time, position and velocity for calculation of accelaration and velocity
  double prev_pos = pod->position;
  double prev_vel = pod->velocity;
  pod->time = getTime(); // Pod time is updates using external function
  if(change_in_state){  // Update pod structure variables if reflexive strip corssed
    pod->position = calcPosition(pod);
    pod->velocity = calcVelocity(pod, prev_tim, prev_pos);
    pod->accelaration = calcAccelaration(pod, prev_tim, prev_vel);
  }
  fileWrite(pod, datasheets); //Write updated pod struct values to datasheet
  if(!(pod->position>=expvals[0][0] && pod->position<=expvals[0][1])){
    return false; // Return pod faliure if pod position not within limits
  }
  if(!(pod->velocity>=expvals[1][0] && pod->velocity<=expvals[1][1])){
    return false; // Return pod faliure if pod velocity not within limits
  }
  if(!(pod->accelaration>=expvals[2][0] && pod->accelaration<=expvals[2][1])){
    return false; // Return pod faliure if pod accelaration not within limits
  }
    return true;  // Return true if pod functioning optimally (within limits)
}

double calcPosition(Pod *pod){  // Calculate and Return pod Position
  double return_pos;
  return_pos = pod->position + 3048;  // Each reflexive strip indicates that pod has crossed 100*30.48 cm
  return return_pos;
}

double calcVelocity(Pod *pod, double prev_time, double prev_position){ // Calculate and Return pod Velocity
  double return_vel;
  return_vel = (pod->position-prev_position)/(pod->time-prev_time);
  return return_vel;
}

double calcAccelaration(Pod *pod, double prev_time, double prev_velocity){ // Calculate and Return pod Accelaration
  double return_acc;
  return_acc = (pod->velocity-prev_velocity)/(pod->time-prev_time);
  return return_acc;
}

double getPosition(Pod *pod){ // Return current position
  return pod->position;
}

double getVelocity(Pod *pod){ // Return current velocity
  return pod->velocity;
}

double getAccelaration(Pod *pod){ // Return current accelaration
  return pod->accelaration;
}

void fileWrite(Pod* pod, FILE** datasheet){
  fprintf(&((*datasheet)[0]),"%f",pod->time);  //Write time to time data sheet
  fprintf(&((*datasheet)[1]),"%f",pod->position);  // Write postion to position sheet
  fprintf(&((*datasheet)[2]),"%f",pod->velocity);  // Write velcoity to velocity sheet
  fprintf(&((*datasheet)[3]),"%f",pod->accelaration);  // Write accelaraion to accelaration sheet
}
