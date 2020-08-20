#include <iostream>

class KalmanFilter{
    private:
        float param_q, param_r, param_h, param_a, param_p;
    public:
        KalmanFilter(){};
        KalmanFilter(float q, float r, float h, float a);
        void print_parameters();
        bool update_parameters(float q, float r, float h, float);
        float get_value(float calc_val, float measr_val);
};