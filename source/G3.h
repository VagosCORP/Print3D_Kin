void g3_setup(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    
}
void g3_um(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    float ndt1x = ndt1;
    float ndt2x = ndt2;
    float xc = (float)xa + i;
    float yc = (float)ya + j;
    float dl = (float)((float)dt*feed) / ((float)60000000.0);
    float dlc = (float)dl*dl;
    float rc = (float)i*i + (float)j*j;
    float r = (float)sqrtf(rc);
    float ddl1 = (float)dl / ndt1x;
    float ddl2 = (float)dl / ndt2x;
    char state_S1 = 1;
    int contState = 0;
    float zas = 0;
    float was = 0;
    float sWas = 0;
    float valxi = xa;
    float valyi = ya;
    float valx = 0;
    float valy = 0;
    float xcq = (float)xc*xc;
    float yacq = 0;
    float xac = 0;
    float xaq = 0;
    float yac = 0;
    float rcmdlc = 0;
    float rcpdlc = 0;
    float dx = 0;
    float dy = 0;
    float numx2 = 0;
    float numx3 = 0;
    float numy2 = 0;
    float numy3 = 0;
    float valDL = 0; 
    float valDLc = 0;
    char runwhile = 1;
    float delta = 0;
    float mydelta = 0;
    long cont = 0;
    valxi = xb;
    valyi = yb;
    int num = (float)0.5*((float)ndt2x - 1);
    while(cont < num) {
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * xa;
        yacq = (float)yac * yac;
        rcmdlc = (float)rc - dlc;
        rcpdlc = (float)rc + dlc;
        zas = (float)(float)xac * xac + yacq;
        zas = (float)2 * zas;
        was = (float)2*dl*r;
        was = (float)((float)was - rcpdlc + zas)*((float)was + rcpdlc - zas);
        sWas = (float)sqrtf(was);
        numx3 = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx3/zas;
        numy3 = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy3/zas;
        cont++;
    }
    float xbi = (float)xb - valxi;
    float ybi = (float)yb - valyi;
    mydelta = (float)xbi*xbi + (float)ybi*ybi;
    mydelta = (float)sqrtf(mydelta);
    valxi = xa;
    valyi = ya;
    while(runwhile) {
        if(state_S1) {
            if(contState < ndt1x - 1) {
                valDL = valDL + ddl1;
                contState++;
            }else {
                valDL = dl;
                contState = 0;
                state_S1 = 0;
            }
        }else {
            if(delta > mydelta)
                contState++;
            else {
                if(valDL > ddl2)
                    valDL = valDL - ddl2;
            }
        }
        xaq = (float)valxi * valxi;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        yacq = (float)yac * yac;
        valDLc = (float)valDL*valDL;
        rcmdlc = (float)rc - valDLc;
        rcpdlc = (float)rc + valDLc;
        zas = (float)(float)xac * xac + yacq;
        zas = (float)2 * zas;
        was = (float)2*valDL*r;
        was = (float)((float)was - rcpdlc + zas)*((float)was + rcpdlc - zas);
        sWas = (float)sqrtf(was);
        numx2 = (float)xac*rcmdlc - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valx = (float)numx2/zas;
        numy2 = (float)yac*rcmdlc + (float)sWas*xac + (float)zas*((float)valyi + yc);
        valy = (float)numy2/zas;
        dx = valx - valxi;
        dy = valy - valyi;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        valxi = valx;
        valyi = valy;
        delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
        if(ddl2 > delta)
            runwhile = 0;
        cont++;
//        send_float_vt(valx);
//        send_float_vt(valy);
    }
    dx = xb - valx;
    dy = yb - valy;
    calc_DM1(dx, dy);
    calc_DM2(dx, dy);
    cont++;
//    send_float_vt(ndt1x);
//    send_float_vt(ndtm);
//    send_float_vt(ndt2x);
//    send_float_vt(dl);
//    send_float_vt(dAngT);
//    send_float_vt(dAng);
//    send_float_vt(ddAng1);
//    send_float_vt(ddAng2);
//    send_float_vt(valx);
//    send_float_vt(valy);
//    send_float_vt((float)cont);
}

void g3(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    g3_um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, feed*1000);
}