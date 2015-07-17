void G1RT(void) {
    vd = 0;
    valDL = 0;
    cont = 0;
    while(cont < ndt1x) {
        valDL += ddl1;
        valDX = (float)valDL*cosA;
        valDY = (float)valDL*sinA;
        calc_DM1(valDX, valDY);
        calc_DM2(valDX, valDY);
        calc_DME(valDL);
        coordX += valDX;
        coordY += valDY;
        cont++;
    }
    send_float_vt(cont);
    cont = 0;
    valDL = dl;
    while(cont < ndtmx) {
        valDX = (float)valDL*cosA;
        valDY = (float)valDL*sinA;
        calc_DM1(valDX, valDY);
        calc_DM2(valDX, valDY);
        calc_DME(valDL);
        coordX += valDX;
        coordY += valDY;
        cont++;
    }
    send_float_vt(cont);
    cont = 0;
    vd = genDist(coordX,coordY,valXb,valYb);
    while(valDL <= vd) {
        if(cont < ndt2x - 1.0) {
            valDL -= ddl2;
            valDX = (float)valDL*cosA;
            valDY = (float)valDL*sinA;
        }
        coordX += valDX;
        coordY += valDY;
        vd = genDist(coordX,coordY,valXb,valYb);
        calc_DM1(valDX, valDY);
        calc_DM2(valDX, valDY);
        calc_DME(valDL);
        cont++;
    }
    valDL = vd;
    valDX = valXb - coordX;
    valDY = valYb - coordY;
    calc_DM1(valDX, valDY);
    calc_DM2(valDX, valDY);
    calc_DME(valDL);
    coordX = valXb;
    coordY = valYb;
    cont++;
    
    send_float_vt(cont);
}

void g1um(/*float xa, float ya, */float xb, float yb, float ext, float feed) {
    float xa = coordX;
    float ya = coordY;
    valXb = xb;
    valYb = yb;
    ndt1x = ndt1;
    ndtmx = 0;
    ndt2x = ndt2;
    dl = (float)((float)dt*feed) / ((float)60000000.0);
    float dxt = (float)xb - xa;
    float dyt = (float)yb - ya;
    float insqrt = (float)dxt*dxt + (float)dyt*dyt;
    dlt = (float)sqrtf(insqrt);
    flex = gen_FLEX(ext,dlt);
    cosA = (float)dxt / dlt;
    sinA = (float)dyt / dlt;
    ddl1 = (float)dl / ndt1x;
    ddl2 = (float)dl / ndt2x;
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
    float vd = 0;
    float valDL = 0;
    float xRA = 0;
    float yRA = 0;
    float xRD = 0;
    float yRD = 0;
    float cont1 = 0;
    float cont2 = 0;
    float valx = xa;
    float valy = ya;
    while(cont1 < ndt1x) {
        valDL = valDL + ddl1;
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
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
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        cont++;
    }
    xRD = valx;
    yRD = valy;
    valx = xRA;
    valy = yRA;
    valDL = dl;
    vd = genDist(xRA,yRA,xRD,yRD);
    while(valDL <= vd) {
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        vd = genDist(valx,valy,xRD,yRD);
        ndtmx++;
    }
    vd = genDist(valx,valy,xb,yb);
    while(valDL <= vd) {
        if(cont2 < ndt2x - 1.0) {
            valDL -= ddl2;
            dx = (float)valDL*cosA;
            dy = (float)valDL*sinA;
        }
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        vd = genDist(valx,valy,xb,yb);
        cont2++;
    }
    valDL = vd;
    dx = xb - valx;
    dy = yb - valy;
    valx = xb;
    valy = yb;
    calc_DM1(dx, dy);
    calc_DM2(dx, dy);
    calc_DME(valDL);
    cont2++;
    
    send_float_vt(cont1);
    send_float_vt(ndtmx);
    send_float_vt(cont2);
    
    G1RT();
}

void g1(/*float xa, float ya, */float xb, float yb, float ext, float feed) {
    flex = 0;
    Gtype = G1;
    g1um(/*xa*1000, ya*1000, */xb*1000, yb*1000, ext, feed*1000);
}