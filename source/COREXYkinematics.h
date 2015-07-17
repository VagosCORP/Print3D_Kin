char G1 = 121;
char G2 = 122;
char G3 = 123;
const float pi = 3.14159265358979323846264338327950288419716939937510;
float pix2 = 0;
char Gtype = 0;
long redrad = 0;
long nppr = 2500;
float nppa = 397.88735772974;//*/(float)nppr / pix2;
float rotorRad = 10000000;//um
float dt = 500;//us
long ndt1 = 19.0;//ac
long ndt2 = 19.0;//dc
float reduc = 30.0;
float np1 = 0;
float np2 = 0;
float dm1 = 0;
float dm2 = 0;
float dmE = 0;
float flex = 0;
float const_pc = 0;

long cont = 0;
float valDL = 0;
float valDX = 0;
float valDY = 0;
float valDLq = 0;
char casoC = 0;
char mDXY = 0;
char stateX = 0;
char stateY = 0;
long ndt1x = 0;
long ndtmx = 0;
long ndt2x = 0;
long cont2 = 0;
float ddl1 = 0;
float ddl2 = 0;
float ddx1 = 0;
float ddx2 = 0;
float ddy1 = 0;
float ddy2 = 0;
float dl = 0;
float dlq = 0;
float dlt = 0;
float sinA = 0;
float cosA = 0;
float yc = 0;
float xc = 0;
float xcq = 0;
float r = 0;
float rq = 0;
float vd = 0;
float valXb = 0;
float valYb = 0;

float circ_xb1(float yb, float rq, float xc, float yc) {
    float res = (float)yb - yc;
    res = (float)rq - (float)res*res;
    res = (float)xc + sqrtf(res);
    return res;
}

float circ_xb2(float yb, float rq, float xc, float yc) {
    float res = (float)yb - yc;
    res = (float)rq - (float)res*res;
    res = (float)xc - sqrtf(res);
    return res;
}

float circ_yb1(float xb, float rq, float xc, float yc) {
    float res = (float)xb - xc;
    res = (float)rq - (float)res*res;
    res = (float)yc + sqrtf(res);
    return res;
}

float circ_yb2(float xb, float rq, float xc, float yc) {
    float res = (float)xb - xc;
    res = (float)rq - (float)res*res;
    res = (float)yc - sqrtf(res);
    return res;
}

float genDistq(float xa, float ya, float xb, float yb) {
    return (float)(xb - xa)*(xb - xa) + (float)(yb - ya)*(yb - ya);
}

float genDist(float xa, float ya, float xb, float yb) {
    return (float)sqrtf(genDistq(xa, ya, xb, yb));
}

void setup_kinematics(float radRot) {
    pix2 = (float)pi*2;
    rotorRad = radRot;
    nppa = (float)nppr / pix2;
    redrad = (float)reduc * rotorRad;
    const_pc = (float)nppa / redrad;
}

void calc_DM1(float dx, float dy) {
    dm1 = dx + dy;
    np1 = (float)dm1*const_pc;
}

void calc_DM2(float dx, float dy) {
    dm2 = dx - dy;
    np2 = (float)dm2*const_pc;
}

float gen_FLEX(float lte, float dlt) {
    return (float)lte / dlt;
}

void calc_DME(float dl) {
    dmE = flex*dl;
}