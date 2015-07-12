void g2_setup(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    
}

float xb1(float yb, float rc, float xc, float yc) {
    float res = 0;
    res = (float)yb - yc;
    res = (float)rc - (float)res*res;
    res = (float)xc + sqrtf(res);
    return res;
}

float xb2(float yb, float rc, float xc, float yc) {
    float res = 0;
    res = (float)yb - yc;
    res = (float)rc - (float)res*res;
    res = (float)xc - sqrtf(res);
    return res;
}

float yb1(float xb, float rc, float xc, float yc) {
    float res = 0;
    res = (float)xb - xc;
    res = (float)rc - (float)res*res;
    res = (float)yc + sqrtf(res);
    return res;
}

float yb2(float xb, float rc, float xc, float yc) {
    float res = 0;
    res = (float)xb - xc;
    res = (float)rc - (float)res*res;
    res = (float)yc - sqrtf(res);
    return res;
}

void g2_um(float xa, float ya, float xb, float yb, float i, float j, float feed) {
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
    float ddl1q = (float)ddl1*ddl1;
    float ddl2q = (float)ddl2*ddl2;
    char state_S1 = 1;
    int contState = 0;
    float pzas = 0;
    float zas = 0;
    float was = 0;
    float pwas = 0;
    float sWas = 0;
    float valxi = 0;
    float valyi = 0;
    float valx = 0;
    float valy = 0;
    float xcq = (float)xc*xc;
    float xacq = 0;
    float yacq = 0;
    float xac = 0;
    float xaq = 0;
    float yac = 0;
    float rcmdlc = 0;
    float rcpdlc = 0;
    float dx = 0;
    float dy = 0;
    float xbi = 0;
    float ybi = 0;
    float numx = 0;
    float numy = 0;
    float valDL = 0; 
    float valDLc = 0;
    char runwhile = 1;
    float delta = 0;
    float mydelta = 0;
    float tempxbi = 0;
    float tempybi = 0;
    float xRA = 0;
    float yRA = 0;
    float xRD = 0;
    float yRD = 0;
    char siPy = 0;//1 es positivo, 2 es negativo
    int num = (float)0.5*((float)ndt2x - 1);
    float val_vdiq = genDistq(xa,ya,xb,yb);
    char casoC = 0;//true V false;
    long cont = 0;
    long cont1 = 0;
    long contm = 0;
    long cont2 = 0;
    long gcont = 0;
    char baj = 0;
    char sub = 0;
    float vdqi = val_vdiq;
    float vdq = val_vdiq;
    float vd = 0;
    float valDX = 0;
    float valDY = 0;
    float ddx1 = 0;
    float ddy1 = 0;
    float ddx2 = 0;
    float ddy2 = 0;
    
    valxi = xa;
    valyi = ya;
    while(!casoC && cont1 < ndt1x) {
        valDL = valDL + ddl1;
        valDLc = (float)valDL*valDL;
        pwas = (float)2*valDL*r;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * valxi;
        xacq = (float)xac * xac;
        yacq = (float)yac * yac;
        rcmdlc = (float)rc - valDLc;
        rcpdlc = (float)rc + valDLc;
        zas = (float)xacq + yacq;
        pzas = (float)2 * zas;
        was = (float)((float)pwas - rcpdlc + zas)*((float)rcpdlc + pwas - zas);
        sWas = (float)sqrtf(was);
        numx = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx/pzas;
        numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy/pzas;
//        xbi = (float)xb - valxi;
//        ybi = (float)yb - valyi;
        vdq = genDistq(valx, valy, xb, yb);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdqi > vdq)//baja
            baj = 1;
        else if(baj)//baja, luego sube => casoC
            casoC = 1;
        vdqi = vdq;
        cont1++;
    }
    xRA = valxi;
    yRA = valyi;
    
    vdqi = val_vdiq;
    vdq = val_vdiq;
    baj = 0;
    sub = 0;
    valDL = 0;
    valxi = xb;
    valyi = yb;
    while(!casoC && cont < ndt2x - 1.0) {//-1 porque completo valDL llega a ser dl, dl será parte de rutaM
        valDL = valDL + ddl2;
        valDLc = (float)valDL*valDL;
        pwas = (float)2*valDL*r;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * valxi;
        xacq = (float)xac * xac;
        yacq = (float)yac * yac;
        rcmdlc = (float)rc - valDLc;
        rcpdlc = (float)rc + valDLc;
        zas = (float)xacq + yacq;
        pzas = (float)2 * zas;
        was = (float)((float)pwas - rcpdlc + zas)*((float)rcpdlc + pwas - zas);
        sWas = (float)sqrtf(was);
        numx = (float)xac*rcmdlc - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx/pzas;
        numy = (float)yac*rcmdlc + (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy/pzas;
//        xbi = (float)xa - valxi;
//        ybi = (float)ya - valyi;
        vdq = genDistq(valx, valy, xa, ya);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdqi > vdq)//baja
            baj = 1;
        else if(baj)//baja, luego sube => casoC
            casoC = 1;
        vdqi = vdq;
        cont++;
    }
    xRD = valxi;
    yRD = valyi;
    
    if(!casoC) {
        valxi = xRA;
        valyi = yRA;
        vdq = genDistq(xRA, yRA, xRD, yRD);
        valDL = dl;
        valDLc = dlc;
        pwas = (float)2*valDL*r;
        rcmdlc = (float)rc - valDLc;
        rcpdlc = (float)rc + valDLc;
        while(valDLc <= vdq) {
            xaq = (float)valxi * valxi;
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            zas = (float)(float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rcpdlc + zas)*((float)pwas + rcpdlc - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valxi = (float)numx/pzas;
            numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
            valyi = (float)numy/pzas;
            vdq = genDistq(valxi, valyi, xRD, yRD);
            contm++;
        }
//        send_float_vt(valxi);
//        send_float_vt(valyi);
//        send_float_vt(xRD);
//        send_float_vt(yRD);
        while(runwhile) {
            vdq = genDistq(valxi, valyi, xb, yb);
            if(valDL > ddl2) {
                valDL = valDL - ddl2;
                valDLc = (float)valDL*valDL;
            }else if(valDL < ddl2){
                valDL = ddl2;
                valDLc = (float)valDL*valDL;
            }
            if(valDLc <= vdq) {
                pwas = (float)2*valDL*r;
                xac = (float)valxi - xc;
                yac = (float)valyi - yc;
                xaq = (float)valxi * valxi;
                xacq = (float)xac * xac;
                yacq = (float)yac * yac;
                rcmdlc = (float)rc - valDLc;
                rcpdlc = (float)rc + valDLc;
                zas = (float)xacq + yacq;
                pzas = (float)2 * zas;
                was = (float)((float)pwas - rcpdlc + zas)*((float)rcpdlc + pwas - zas);
                sWas = (float)sqrtf(was);
                numx = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                        (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
                valxi = (float)numx/pzas;
                numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
                valyi = (float)numy/pzas;
//                xbi = (float)xa - valxi;
//                ybi = (float)ya - valyi;
                cont2++;
            }else {
                valxi = xb;
                valyi = yb;
                runwhile = 0;
                cont2++;
            }
        }
    }else {//casoC = 1
        float distX = 0;
        float distY = 0;
        float dx = 0;
        float dy = 0;
        float dlt = 0;
        char stateY = xa >= xc;
        valxi = xa;
        valyi = ya;
        cont1 = 0;
        cont2 = 0;
        valDX = 0;
        valDY = 0;
        distX = xb - xa;
        distY = yb - ya;
        if(ya >= yc) {
            if(yb >= yc) {
                dx = (float)2*((float)distX / ((float)ndt1x + ndt2x));
                ddx1 = (float)dx / ndt1x;
                ddx2 = (float)dx / ndt2x;
                while(cont1 < ndt1x) {
                    valDX = valDX + ddx1;
                    valx = valxi + valDX;
                    valy = yb1(valxi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont1++;
                }
                while(cont2 < ndt2x - 1) {
                    valDX = valDX - ddx2;
                    valx = valxi + valDX;
                    valy = yb1(valxi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont2++;
                }
            }else {
                dy = (float)2*((float)distY / ((float)ndt1x + ndt2x));
                ddy1 = (float)dy / ndt1x;
                ddy2 = (float)dy / ndt2x;
                while(cont1 < ndt1x) {
                    valDY = valDY + ddy1;
                    valy = valyi + valDY;
                    if(stateY)
                        valx = xb1(valyi,rc,xc,yc);
                    else
                        valx = xb2(valyi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont1++;
                }
                while(cont2 < ndt2x - 1) {
                    valDY = valDY - ddy2;
                    valy = valyi + valDY;
                    if(stateY)
                        valx = xb1(valyi,rc,xc,yc);
                    else
                        valx = xb2(valyi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont2++;
                }
            }
        }else {
            if(yb >= yc) {
                dy = (float)2*((float)distY / ((float)ndt1x + ndt2x));
                ddy1 = (float)dy / ndt1x;
                ddy2 = (float)dy / ndt2x;
                while(cont1 < ndt1x) {
                    valDY = valDY + ddy1;
                    valy = valyi + valDY;
                    if(stateY)
                        valx = xb1(valyi,rc,xc,yc);
                    else
                        valx = xb2(valyi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont1++;
                }
                while(cont2 < ndt2x - 1) {
                    valDY = valDY - ddy2;
                    valy = valyi + valDY;
                    if(stateY)
                        valx = xb1(valyi,rc,xc,yc);
                    else
                        valx = xb2(valyi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont2++;
                }
            }else {
                dx = (float)2*((float)distX / ((float)ndt1x + ndt2x));
                ddx1 = (float)dx / ndt1x;
                ddx2 = (float)dx / ndt2x;
                while(cont1 < ndt1x) {
                    valDX = valDX + ddx1;
                    valx = valxi + valDX;
                    valy = yb2(valxi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont1++;
                }
                while(cont2 < ndt2x - 1) {
                    valDX = valDX - ddx2;
                    valx = valxi + valDX;
                    valy = yb2(valxi,rc,xc,yc);
                    dlt = (float)dlt + genDist(valxi,valyi,valx,valy);
                    cont2++;
                }
            }
        }
    }
    send_float_vt((float)cont1);
    send_float_vt((float)contm);
    send_float_vt((float)cont2);
    if(casoC)
        send_float_vt(3.0);
    else
        send_float_vt(1.0);
}
    
void g2(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    g2_um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, feed*1000);
//    g2_um(xa, ya, xb, yb, i, j, feed);
}