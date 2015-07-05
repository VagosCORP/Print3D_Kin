#include "SYSconfig.h"
#include <math.h>
//#include "PeriferialConfig.h"
#include "../../Comunic.h"
#include "UART1Config.h"
#include "ConfigEHW.h"
//#include "Timer1Config.h"
#include "Timer3Config.h"
//#include "OCconfig.h"


float coord_X = 0;
float coord_Y = 0;
float coord_Z = -800;
float ang_act1 = 0;
float ang_act2 = 0;
float ang_act3 = 0;

#include "COREXYkinematics.h"
#include "G1.h"
#include "G2.h"
#include "G3.h"

int main(int argc, char** argv) {
    
    float timex = 0;
    float time = 0;
//    float ang1 = 0;
//    float ang2 = 0;
//    float ang3 = 0;
    
    config_clock();
//    config_Periferials();//24F
//    setup_kinematics();
//    config_T1();
    config_T3();
//    config_OC1();
//    config_OC2();
//    config_OC3();
    config_uart1();
    
    INTCON1bits.NSTDIS = 0;
//    config_RN171XV();
    
    while(1) {
        T3CONbits.TON = 0;
        tof = 0;
        TMR3 = 0;
        T3CONbits.TON = 1;
        g2(50.0,50.0,50.0,50.0,-50.0,0.0,12000.0);
//        g3(0.0,50.0,50.0,0.0,0.0,-50.0,0.1);
//        ang1 = calc_ang1(-500,-500,-1800);
//        ang2 = calc_ang2(-500,-500,-1800);
//        ang3 = calc_ang3(-500,-500,-1800);
        T3CONbits.TON = 0;
        timex = (float)TMR3 + (float)tof*65536;
//        time = (float)timex*0.0000625;//24F
        time = (float)timex*0.000025;//24H
//        send_float_vt(ang1);
//        send_float_vt(ang2);
//        send_float_vt(ang3);
        send_float_vt(time);
        delay_ms(5000);
    }
    return (EXIT_SUCCESS);
}