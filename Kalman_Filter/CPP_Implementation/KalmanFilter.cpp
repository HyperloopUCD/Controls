#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(float q, float r, float h, float a):param_q(q), param_r(r), param_h(h), param_a(a), param_p(0){}

void KalmanFilter::print_parameters(){
    std::cout<<"\nThe parameters are: "<<"\nq = "<<param_q<<"\nr = "<<param_r<<"\nh = "<<param_h<<"\na = "<<param_a<<"\np = "<<param_p<<"\n";
}

bool KalmanFilter::update_parameters(float q, float r, float h, float a){
    param_q = q;
    param_r = r;
    param_h = h;
    param_a = a;
    param_p = 0;
    if(param_q == q && param_r == r && param_h == h && param_a == a && param_p == 0)
        return true;
    return false;
}

float KalmanFilter::get_value(float calc_val, float measr_val){
    float temp_p = param_a * param_a * param_p + param_q;
    float kalman_gain = param_h * temp_p / (param_h * param_h * temp_p + param_r);
    float kalman_value = calc_val + kalman_gain * (measr_val - param_h * calc_val);
    param_p = (1 - kalman_gain * param_h) * temp_p;
    return kalman_value;
}
