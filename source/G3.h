void g3_um(float xa, float ya, float xb, float yb, float i, float j, float dl) {
    float rc = (float)i*i + (float)j*j;
    float cosAp = (float)1 - (float)(((float)dl*dl) / ((float)2*rc));
    float xc = (float)xa + i;
    float yc = (float)ya + j;
    float Z = (float)2*cosAp - 1.0;
    float valx = xa;
    float valy = ya;
    float W = 0;
    float constinsqrt = 0;
    float numx = 0;
    float numy = 0;
    char runwhile = 1;
    float delta = 0;
    float mydelta = (float)dl*dl;
    long cont = 0;
    while(runwhile) {
        W = rc/*(float)(xc-valx)*(xc-valx) + (float)(yc-valy)*(yc-valy)*/;//Teoricamente sería r^2
        constinsqrt = (float)W*rc*((float)4 - Z*2) - (float)Z*Z*rc*rc - (float)W*W;
        numx = (float)(yc-valy)*sqrtf(constinsqrt) - (float)Z*rc*(xc - valx) + (float)W*(xc+valx);
        numy = (float)(valx-xc)*sqrtf(constinsqrt) - (float)Z*rc*(yc - valy) + (float)W*(yc+valy);
        valx = (float)numx / ((float)2*W);
        valy = (float)numy / ((float)2*W);
        delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
        if(mydelta > delta)
            runwhile = 0;
        cont++;
//        putch(13);
//        send_float(valx);
//        putch(10);
//        putch(13);
//        send_float(valy);
//        putch(10);
    }
    cont++;
//    putch(13);
//    send_float(xb);
//    putch(10);
//    putch(13);
//    send_float(yb);
//    putch(10);
    putch(13);
    send_float((float)cont);
    putch(10);
}

void g3(float xa, float ya, float xb, float yb, float i, float j, float dl) {
    g3_um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, dl*1000);
}

//float rc = (float)i*i + (float)j*j;
//float cosAp = (float)1 - (float)(((float)dl*dl) / ((float)2*rc));
//float xc = (float)xa + i;
//float yc = (float)ya + j;
//float Z = (float)2*cosAp - 1.0;
//float valx = xa;
//float valy = ya;
//float W = 0;
//float constinsqrt = 0;
//float numx = 0;
//float numy = 0;
//char runwhile = 1;
//float delta = 0;
//float mydelta = (float)dl*dl;
//long cont = 0;
//while(runwhile) {
//    W = rc/*(float)(xc-valx)*(xc-valx) + (float)(yc-valy)*(yc-valy)*/;//Teoricamente sería r^2
//    constinsqrt = (float)W*rc*((float)4 - Z*2) - (float)Z*Z*rc*rc - (float)W*W;
//    numx = (float)(yc-valy)*sqrtf(constinsqrt) - (float)Z*rc*(xc - valx) + (float)W*(xc+valx);
//    numy = (float)(valx-xc)*sqrtf(constinsqrt) - (float)Z*rc*(yc - valy) + (float)W*(yc+valy);
//    valx = (float)numx / ((float)2*W);
//    valy = (float)numy / ((float)2*W);
//    delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
//    if(mydelta > delta)
//        runwhile = 0;
//    cont++;
//}