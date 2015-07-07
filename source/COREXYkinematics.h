float pi = 3.14159265358979323846264338327950288419716939937510;
long redrad = 0;
long nppa = 397.88735772974;//2500/2*pi
long nppr = 2500;
float rotorRad = 0;
float dt = 500;//us
float ndt1 = 19;//ac
float ndt2 = 19;//dc
float reduc = 30.0;
float np1 = 0;
float np2 = 0;
float dm1 = 0;
float dm2 = 0;
float const_pc = 0;

float genDistq(float xa, float ya, float xb, float yb) {
    return (float)(xb - xa)*(xb - xa) + (float)(yb - ya)*(yb - ya);
}

float genDist(float xa, float ya, float xb, float yb) {
    return (float)sqrtf(genDistq(xa, ya, xb, yb));
}

void setup_kinematics(float radRot) {
    rotorRad = radRot;
    nppa = (float)nppr / ((float)2*pi);
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