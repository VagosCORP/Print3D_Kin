void g2_setup(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    
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
    char siPx = 0;//1 es positivo, 2 es negativo
    char siPy = 0;//1 es positivo, 2 es negativo
    int num = (float)0.5*((float)ndt2x - 1);
    valxi = xa;
    valyi = ya;
    float rad;
    long cont = 0;
    while(cont < ndt1x) {
        valDL = valDL + ddl1;
        pwas = (float)2*valDL*r;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * valxi;
        yacq = (float)yac * yac;
        valDLc = (float)valDL*valDL;
        rcmdlc = (float)rc - valDLc;
        rcpdlc = (float)rc + valDLc;
        zas = (float)xac * xac + yacq;
        pzas = (float)2 * zas;
        was = (float)((float)pwas - rcpdlc + zas)*((float)rcpdlc + pwas - zas);
        sWas = (float)sqrtf(was);
        numx = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx/pzas;
        numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy/pzas;
//        rad = (float)(valxi-xc)*(valxi-xc) + (float)(valyi-yc)*(valyi-yc);
//        send_float_vt(rad);
        xbi = (float)xb - valxi;//negativo => valw <= valii
        ybi = (float)yb - valyi;//positivo =>valw >= valwi
        if(siPx == 0 && siPy == 0) {
            if(xbi < 0)
                siPx = 2;
            else if(xbi > 0)
                siPx = 1;
            if(ybi < 0)
                siPy = 2;
            else if(ybi > 0)
                siPy = 1;
        }
        cont++;
//        send_float_vt(zas);
//        send_float_vt(was);
    }
//    mydelta = (float)xbi*xbi + (float)ybi*ybi;
//    mydelta = (float)sqrtf(mydelta);
//    send_float_vt(num);
//    send_float_vt(valxi);
//    send_float_vt(valyi);
//    send_float_vt(mydelta);
//    valxi = xb;
//    valyi = yb;
//    cont = 0;
//    while(cont < ndt2x) {
//        valDL = valDL + ddl2;
//        pwas = (float)2*valDL*r;
//        xac = (float)valxi - xc;
//        yac = (float)valyi - yc;
//        xaq = (float)valxi * valxi;
//        yacq = (float)yac * yac;
//        valDLc = (float)valDL*valDL;
//        rcmdlc = (float)rc - valDLc;
//        rcpdlc = (float)rc + valDLc;
//        zas = (float)xac * xac + yacq;
//        pzas = (float)2 * zas;
//        was = (float)((float)pwas - rcpdlc + zas)*((float)rcpdlc + pwas - zas);
//        sWas = (float)sqrtf(was);
//        numx3 = (float)xac*rcmdlc - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
//                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
//        valxi = (float)numx3/pzas;
//        numy3 = (float)yac*rcmdlc + (float)sWas*xac + (float)zas*((float)valyi + yc);
//        valyi = (float)numy3/pzas;
//        xbi = (float)xa - valxi;//negativo => valw <= valii
//        ybi = (float)ya - valyi;//positivo =>valw >= valwi
//        cont++;
////        send_float_vt(zas);
////        send_float_vt(was);
//    }
//    mydelta = (float)xbi*xbi + (float)ybi*ybi;
//    mydelta = (float)sqrtf(mydelta);
//    send_float_vt(num);
//    send_float_vt(valxi);//*
//    send_float_vt(valyi);//*
//    send_float_vt(mydelta);
//    valxi = xa;
//    valyi = ya;
//    cont = 0;
//    while(runwhile) {
//        if(state_S1) {
//            if(contState < ndt1x - 1) {
//                valDL = valDL + ddl1;
//                contState++;
//            }else {
//                valDL = dl;
//                contState = 0;
//                state_S1 = 0;
//            }
//        }else {
//            if(delta > mydelta)
//                contState++;
//            else {
//                if(valDL > ddl2)
//                    valDL = valDL - ddl2;
//            }
//        }
//        xaq = (float)valxi * valxi;
//        xac = (float)valxi - xc;
//        yac = (float)valyi - yc;
//        yacq = (float)yac * yac;
//        valDLc = (float)valDL*valDL;
//        rcmdlc = (float)rc - valDLc;
//        rcpdlc = (float)rc + valDLc;
//        zas = /*rc;//*/(float)(float)xac * xac + yacq;
//        pzas = (float)2 * zas;
//        pwas = (float)2*valDL*r;
//        was = (float)((float)pwas - rcpdlc + zas)*((float)pwas + rcpdlc - zas);
//        sWas = (float)sqrtf(was);
//        numx2 = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
//                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
//        valx = (float)numx2/pzas;
//        numy2 = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
//        valy = (float)numy2/pzas;
//        dx = valx - valxi;
//        dy = valy - valyi;
//        calc_DM1(dx, dy);
//        calc_DM2(dx, dy);
//        valxi = valx;
//        valyi = valy;
//        delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
//        delta = (float)sqrtf(delta);
//        if(ddl2 >= delta)
//            runwhile = 0;
//        cont++;
//        send_float_vt(delta);
//        send_float_vt(ddl1);
//        send_float_vt(ddl2);
////        send_float_vt(valx);
////        send_float_vt(valy);
////        __delay_us(50);
//    }
//    dx = xb - valx;
//    dy = yb - valy;
//    calc_DM1(dx, dy);
//    calc_DM2(dx, dy);
//    cont++;
//    send_float_vt(xb);
//    send_float_vt(yb);
    send_float_vt((float)cont);
}
    
void g2(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    g2_um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, feed*1000);
//    g2_um(xa, ya, xb, yb, i, j, feed);
}