#include <iostream>
#include "KalmanFilter.h"

int main(int argc, char *argv[]) {
    if (argc == 5) {
        KalmanFilter k_f(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]));
        while(true) {
            float calc_val;
            float measr_val;
            std::cin>>calc_val>>measr_val;
            if (int(calc_val) == 999 && int(measr_val) == 999){
                break;
            }
            float kal_value = k_f.get_value(calc_val, measr_val);
            std::cout<<"Kalman Filter Value: "<<kal_value<<"\n";
        }
        std::cout<<"Complete\n";
        return 1;
    }
    else {
        std::cout<<"Incorrcet number of arguments\n";
        return 0;
    }
}