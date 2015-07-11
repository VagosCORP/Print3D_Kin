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
//    float xtri1 = 0;
//    float ytri1 = 0;
//    float xtri2 = 0;
//    float ytri2 = 0;
    
//    float zas1 = 0;
//    float zas2 = 0;
//    float pzas1 = 0;
//    float pzas2 = 0;
//    float xac1 = 0;
//    float yac1 = 0;
//    float xac2 = 0;
//    float yac2 = 0;
//    float xac1q = 0;
//    float yac1q = 0;
//    float xac2q = 0;
//    float yac2q = 0;
//    float xac1 = 0;
//    float yac1 = 0;
//    float xac2 = 0;
//    float yac2 = 0;
//    float xa1q = 0;
//    float xa2q = 0;
//    float rcmdl1c = 0;
//    float rcpdl1c = 0;
//    float rcmdl2c = 0;
//    float rcpdl2c = 0;
//    float was1 = 0;
//    float was2 = 0;
//    float pwas1 = 0;
//    float pwas2 = 0;
//    float sWas1 = 0;
//    float sWas2 = 0;
//    float numx1 = 0;
//    float numy1 = 0;
//    float numx2 = 0;
//    float numy2 = 0;
//    float valxi1 = xa;
//    float valyi1 = ya;
//    float valxi2 = xb;
//    float valyi2 = yb;
//    float valDL1 = ddl1;
//    float valDL2 = ddl2;
//    float valDL1c = (float)ddl1*ddl1;
//    float valDL2c = (float)ddl2*ddl2;
    
    valxi = xa;
    valyi = ya;
    
//    runwhile = 1;
//    while(runwhile) {
//        vdq = genDistq(valxi1, valyi1, valxi2, valyi2);
//        if(cont1 < ndt1x && vdq >= valDL1c) {
//            pwas1 = (float)2*valDL1*r;
//            xac1 = (float)valxi1 - xc;
//            yac1 = (float)valyi1 - yc;
//            xa1q = (float)valxi1 * valxi1;
//            xac1q = (float)xac1 * xac1;
//            yac1q = (float)yac1 * yac1;
//            rcmdl1c = (float)rc - valDL1c;
//            rcpdl1c = (float)rc + valDL1c;
//            zas1 = (float)xac1q + yac1q;
//            pzas1 = (float)2 * zas1;
//            was1 = (float)((float)pwas1 - rcpdl1c + zas1)*((float)rcpdl1c + pwas1 - zas1);
//            sWas1 = (float)sqrtf(was1);
//            numx1 = (float)xac1*rcmdl1c + (float)sWas1*yac1 + (float)xa1q*valxi1 - (float)xa1q*xc -
//                    (float)valxi1*((float)xcq - yac1q) + (float)xc*((float)xcq + yac1q);
//            valxi1 = (float)numx1 / pzas1;
//            numy1 = (float)yac1*rcmdl1c - (float)sWas1*xac1 + (float)zas1*((float)valyi1 + yc);
//            valyi1 = (float)numy1 / pzas1;
//            valDL1 = valDL1 + ddl1;
//            valDL1c = (float)valDL1*valDL1;
//            cont1++;
//        }else {
//            runwhile = 0;
//        }
//        vdq = genDistq(valxi1, valyi1, valxi2, valyi2);
//        if(cont2 < ndt2x && vdq >= valDL2c) {
//            pwas2 = (float)2*valDL2*r;
//            xac2 = (float)valxi2 - xc;
//            yac2 = (float)valyi2 - yc;
//            xa2q = (float)valxi2 * valxi2;
//            xac2q = (float)xac2 * xac2;
//            yac2q = (float)yac2 * yac2;
//            rcmdl2c = (float)rc - valDL2c;
//            rcpdl2c = (float)rc + valDL2c;
//            zas2 = (float)xac2q + yac2q;
//            pzas2 = (float)2 * zas2;
//            was2 = (float)((float)pwas2 - rcpdl2c + zas2)*((float)rcpdl2c + pwas2 - zas2);
//            sWas2 = (float)sqrtf(was2);
//            numx2 = (float)xac2*rcmdl2c - (float)sWas2*yac2 + (float)xa2q*valxi2 - (float)xa2q*xc -
//                    (float)valxi2*((float)xcq - yac2q) + (float)xc*((float)xcq + yac2q);
//            valxi2 = (float)numx2 / pzas2;
//            numy2 = (float)yac2*rcmdl2c + (float)sWas2*xac2 + (float)zas2*((float)valyi2 + yc);
//            valyi2 = (float)numy2 / pzas2;
//            valDL2 = valDL2 + ddl2;
//            valDL2c = (float)valDL2*valDL2;
//            runwhile = 0;
//            cont2++;
//        }
////        if(vdqi > vdq)//baja, luego sube
////            baj = 1;
////        else if(baj)
////            casoC = 1;
////        vdqi = vdq;
//        cont++;
//    }
    
    while(cont < ndt1x) {
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
        valx = (float)numx/pzas;
        numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
        valy = (float)numy/pzas;
//        rad = (float)(valxi-xc)*(valxi-xc) + (float)(valyi-yc)*(valyi-yc);
//        send_float_vt(rad);
//        xbi = (float)xb - valxi;//negativo => valw <= valii
//        ybi = (float)yb - valyi;//positivo =>valw >= valwi
        vdq = genDistq(valx, valy, xb, yb);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdqi > vdq)//baja
            baj = 1;
        else if(baj) {//baja, luego sube => casoC
            casoC = 1;
            cont = ndt1x;
        }
        vdqi = vdq;
        ///////
        valxi = valx;
        valyi = valy;
//        vd = (float)sqrtf(vdq);
        cont++;
        cont1++;
//        send_float_vt(zas);
//        send_float_vt(was);
    }
    xRA = valxi;
    yRA = valyi;
//    mydelta = (float)xbi*xbi + (float)ybi*ybi;
//    mydelta = (float)sqrtf(mydelta);
//    send_float_vt(num);
//    send_float_vt(valxi);
//    send_float_vt(valyi);
//    send_float_vt(mydelta);
//    cont = 0;
    cont = 0;
    vdqi = val_vdiq;
    vdq = val_vdiq;
    valxi = xb;
    valyi = yb;
    baj = 0;
    sub = 0;
    valDL = 0;
    while(cont < ndt2x - 1.0) {//-1 porque completo valDL llega a ser dl, dl será parte de rutaM
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
        valx = (float)numx/pzas;
        numy = (float)yac*rcmdlc + (float)sWas*xac + (float)zas*((float)valyi + yc);
        valy = (float)numy/pzas;
//        xbi = (float)xa - valxi;//negativo => valw <= valii
//        ybi = (float)ya - valyi;//positivo =>valw >= valwi
        vdq = genDistq(valx, valy, xa, ya);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdqi > vdq)//baja
            baj = 1;
        else if(baj) {//baja, luego sube => casoC
            casoC = 1;
            cont = ndt2x;
        }
        vdqi = vdq;
        ///////
        valxi = valx;
        valyi = valy;
//        vd = (float)sqrtf(vdq);
        cont++;
        cont2++;
//        send_float_vt(zas);
//        send_float_vt(was);
    }
    xRD = valxi;
    yRD = valyi;
    vdq = genDistq(xtri1, ytri1, xtri2, ytri2);
    vd = (float)sqrtf(vdq);
//    mydelta = (float)xbi*xbi + (float)ybi*ybi;
//    mydelta = (float)sqrtf(mydelta);
//    send_float_vt(num);
//    send_float_vt(valxi);//*
//    send_float_vt(valyi);//*
//    send_float_vt(mydelta);
    if(!casoC) {
        cont = 0;
        valxi = xRA;
        valyi = yRA;
        vdq = genDistq(xRA, yRA, xRD, yRD);
        valDL = dl;
        valDLc = dlc;
        pwas = (float)2*valDL*r;
        while(valDLc <= vdq) {
            xaq = (float)valxi * valxi;
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            rcmdlc = (float)rc - valDLc;
            rcpdlc = (float)rc + valDLc;
            zas = (float)(float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rcpdlc + zas)*((float)pwas + rcpdlc - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rcmdlc + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valxi = (float)numx/pzas;
            numy = (float)yac*rcmdlc - (float)sWas*xac + (float)zas*((float)valyi + yc);
            valyi = (float)numy/pzas;
//            dx = valx - valxi;
//            dy = valy - valyi;
//            valxi = valx;
//            valyi = valy;
            vdq = genDistq(valxi, valyi, xRD, yRD);
            cont++;
            contm++;
//            send_float_vt(delta);
//            send_float_vt(ddl1);
//            send_float_vt(ddl2);
//            send_float_vt(valx);
//            send_float_vt(valy);
//            __delay_us(50);
        }
        send_float_vt(valxi);
        send_float_vt(valyi);
        send_float_vt(xRD);
        send_float_vt(yRD);
        char fr2 = 1;
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
//                xbi = (float)xa - valxi;//negativo => valw <= valii
//                ybi = (float)ya - valyi;//positivo =>valw >= valwi
//                vd = (float)sqrtf(vdq);
                cont++;
                cont2++;
//                send_float_vt(zas);
//                send_float_vt(was);
                if(fr2)
                    fr2 = 0;
            }else {
//                send_float_vt(valxi);
//                send_float_vt(valyi);
                valxi = xb;
                valyi = yb;
                runwhile = 0;
                cont2++;
            }
        }
//        dx = xb - valx;
//        dy = yb - valy;
//        calc_DM1(dx, dy);
//        calc_DM2(dx, dy);
//        cont++;
//        send_float_vt(xb);
//        send_float_vt(yb);
    }else {//casoC = 1
        
    }
//    send_float_vt(genDistq(xa,ya,xc,yc));
//    send_float_vt(genDistq(xRA,yRA,xc,yc));
//    send_float_vt(genDistq(xRD,yRD,xc,yc));
//    send_float_vt(genDistq(xb,yb,xc,yc));
//    send_float_vt(xb);
//    send_float_vt(yb);
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