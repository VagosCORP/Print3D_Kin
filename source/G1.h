void g1_um(float xa, float ya, float xb, float yb, float ext, float feed) {
    long ndt1x = ndt1;
    long ndt2x = ndt2;
    float vd = 0;
    float dl = (float)((float)dt*feed) / ((float)60000000.0);
    float dxt = (float)xb - xa;
    float dyt = (float)yb - ya;
    float insqrt = (float)dxt*dxt + (float)dyt*dyt;
    float dlt = (float)sqrtf(insqrt);
    flex = gen_FLEX(ext,dlt);
    float cosA = (float)dxt / dlt;
    float sinA = (float)dyt / dlt;
    float ddl1 = (float)dl / ndt1x;
    float ddl2 = (float)dl / ndt2x;
    float ndl = (float)dlt / dl;
    float ndlx2 = (float)2.0*ndl;
    float ndtmx2 = (float)ndlx2 - ndt1x - ndt2x;
    long ndtm = (float)ndtmx2 / 2.0;
    if(ndtm <= 0) {
        float constR = (float)ndt2x/ndt1x;
        float num = (float)ndt1x*ndlx2;
        float den = (float)1.0 + constR;
        float insq = (float)num/den;
        ndt1x = (float)sqrtf(insq);
        ndt2x = (float)ndt1x*constR;
        ndtm = 0;
    }
    float dx = 0;
    float dy = 0;
    float valx = xa;
    float valy = ya;
    long cont = 0;
    float delta = 0;
    float valDL = 0;
    while(cont < ndt1x) {
        valDL = valDL + ddl1;
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = (float)(xb - valx)*(xb - valx) + (yb - valy)*(yb - valy);
        cont++;
    }
    cont = 0;
    while(cont < ndtm) {
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = genDist(valx,valy,xb,yb);
        cont++;
    }
    cont = 0;
    delta = genDist(valx,valy,xb,yb);
    while(valDL <= delta) {
        if(cont < ndt2x - 1.0) {
            valDL = valDL - ddl2;
            dx = (float)valDL*cosA;
            dy = (float)valDL*sinA;
        }
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = genDist(valx,valy,xb,yb);
        send_float_vt(valx);
        cont++;
    }
    valDL = delta;
    dx = xb - valx;
    dy = yb - valy;
    valx = xb;
    valy = yb;
    calc_DM1(dx, dy);
    calc_DM2(dx, dy);
    calc_DME(valDL);
    cont++;
    
    send_float_vt(valx);
    send_float_vt(valy);
    send_float_vt(ndt1x);
    send_float_vt(ndtm);
    send_float_vt(cont);
}

void g1(float xa, float ya, float xb, float yb, float ext, float feed) {
    flex = 0;
    g1_um(xa*1000, ya*1000, xb*1000, yb*1000, ext, feed*1000);
}