#ifndef DELTAKINEMATICS_H
#define	DELTAKINEMATICS_H

#ifdef	__cplusplus
extern "C" {
#endif


float distb = 0;
float distp = 0;
float lg = 0;
float l = 0;
float sb = 0;
float sp = 0;
float wb = 0;
float ub = 0;
float wp = 0;
float up = 0;
float a = 0;
float b = 0;
float c = 0;

void setup_kinematics(float cpB, float cpP, float larm, float lant) {
    distb = cpB;
    distp = cpP;
    lg = larm;
    l = lant;
    sb = (float)distb*(((float)6)/(sqrtf(3)));
    sp = (float)distp*(((float)3)/(sqrtf(3)));
    wb = (float)sb*((sqrtf(3))/((float)6));
    ub = (float)sb*((sqrtf(3))/((float)3));
    wp = (float)sp*((sqrtf(3))/((float)6));
    up = (float)sp*((sqrtf(3))/((float)3));
    a = (float)wb - up;
    b = (float)sp*0.5 - (float)wb*0.5*sqrtf(3);
    c = (float)wp - (float)wb*0.5;
}

float calc_ang1(float x, float y, float z) {
    float res = 0;
    float e1 = (float)2*lg*(y + a);
    float f1 = (float)2*z*lg;
    float g1 = (float)x*x + (float)y*y + (float)z*z + (float)a*a + (float)lg*lg + (float)2*y*a - (float)l*l;
    res = 2*atanf((float)((float)(-f1 - sqrtf((float)e1*e1 + (float)f1*f1 - (float)g1*g1))/(g1 - e1)));
    res = (float)res*180/3.1415926535898;
    return res;
}

float calc_ang2(float x, float y, float z) {
    float res = 0;
    float e2 = -(float)lg*(sqrtf(3)*(x+b)+y+c);
    float f2 = (float)2*z*lg;
    float g2 = (float)x*x + (float)y*y + (float)z*z + (float)b*b + (float)c*c + (float)lg*lg + (float)2*(x*b+y*c) - (float)l*l;
    res = 2*atanf((float)((float)(-f2 - sqrtf((float)e2*e2 + (float)f2*f2 - (float)g2*g2))/(g2 - e2)));
    res = (float)res*180/3.1415926535898;
    return res;
}

float calc_ang3(float x, float y, float z) {
    float res = 0;
    float e3 = (float)lg*((float)sqrtf(3)*(x-b)-y-c);
    float f3 = (float)2*z*lg;
    float g3 = (float)x*x + (float)y*y + (float)z*z + (float)b*b + (float)c*c + (float)lg*lg + (float)2*(-x*b+y*c) - (float)l*l;
    res = 2*atanf((float)((float)(-f3 - sqrtf((float)e3*e3 + (float)f3*f3 - (float)g3*g3))/(g3 - e3)));
    res = (float)res*180/3.1415926535898;
    return res;
}


#ifdef	__cplusplus
}
#endif

#endif	/* DELTAKINEMATICS_H */

