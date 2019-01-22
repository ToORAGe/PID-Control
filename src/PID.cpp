#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/
double PID::cte_m1 = 0; 
double PID::total_cte = 0; 
int PID::counter = 0; 
PID::PID() {
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp; 
  this->Ki = Ki; 
  this->Kd = Kd; 
}

void PID::UpdateError(double cte) {
    
  if(counter==0)
  {
    cte_m1 = cte; 
  }
  p_error = Kp*cte; 
  i_error = Ki*total_cte; 
  d_error = Kd*(cte-cte_m1); 

  total_cte += cte; 
  cte_m1 = cte; 
  
  
}

double PID::TotalError() {
  
  return -1*p_error - i_error - d_error; 
  
}

