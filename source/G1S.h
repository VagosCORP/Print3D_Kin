void g1um(float xa, float ya, float xb, float yb, float ext, float feed) {
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
    long ndl = (long)(float)dlt / dl;
    long ndlx2 = 2*ndl;
    signed long ndtmx2 = ndlx2 - ndt1x - ndt2x;
    signed long ndtm = (signed long)(float)ndtmx2 / 2.0;
    if(ndtm < 0) {
        float constR = (float)ndt2x / ndt1x;
        float num = (float)ndt1x*ndlx2;
        float den = (float)1.0 + constR;
        float insq = (float)num/den;
        ndt1x = (long)(float)sqrtf(insq);
        ndt2x = (long)(float)ndt1x*constR;
        ndtm = 0;
    }
    float dx = 0;
    float dy = 0;
    long cont = 0;
    float delta = 0;
    float valDL = 0;
    float xRA = 0;
    float yRA = 0;
    float xRD = 0;
    float yRD = 0;
    float cont1 = 0;
    float contm = 0;
    float cont2 = 0;
    float valx = xa;
    float valy = ya;
    while(cont1 < ndt1x) {
        valDL = valDL + ddl1;
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        cont1++;
    }
    xRA = valx;
    yRA = valy;
    valDL = 0;
    valx = xb;
    valy = yb;
    while(cont < ndt2x - 1.0) {
        valDL = valDL - ddl2;
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        cont++;
    }
    xRD = valx;
    yRD = valy;
    valx = xRA;
    valy = yRA;
    valDL = dl;
    delta = genDist(xRA,yRA,xRD,yRD);
    while(valDL <= delta) {
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        calc_DME(valDL);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = genDist(valx,valy,xRD,yRD);
        contm++;
    }
    delta = genDist(valx,valy,xb,yb);
    while(valDL <= delta) {
        if(cont2 < ndt2x - 1.0) {
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
        cont2++;
    }
    valDL = delta;
    dx = xb - valx;
    dy = yb - valy;
    valx = xb;
    valy = yb;
    calc_DM1(dx, dy);
    calc_DM2(dx, dy);
    calc_DME(valDL);
    cont2++;
    
    send_float_vt(cont1);
    send_float_vt(contm);
    send_float_vt(cont2);
}

void g1(float xa, float ya, float xb, float yb, float ext, float feed) {
    flex = 0;
    g1um(xa*1000, ya*1000, xb*1000, yb*1000, ext, feed*1000);
}