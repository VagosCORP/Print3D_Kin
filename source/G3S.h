void g3_setup(float xa, float ya, float xb, float yb, float i, float j, float feed) {
    
}

void g3um(float xa, float ya, float xb, float yb, float i, float j, float ext, float feed) {
    float dlt = 0;
    long ndt1x = ndt1;
    long ndt2x = ndt2;
    float xc = (float)xa + i;
    float yc = (float)ya + j;
    float dl = (float)((float)dt*feed) / ((float)60000000.0);
    float dlq = (float)dl*dl;
    float rq = (float)i*i + (float)j*j;
    float r = (float)sqrtf(rq);
    float ddl1 = (float)dl / ndt1x;
    float ddl2 = (float)dl / ndt2x;
    float ddl1q = (float)ddl1*ddl1;
    float ddl2q = (float)ddl2*ddl2;
    float xcq = (float)xc*xc;
    float pzas = 0;
    float zas = 0;
    float was = 0;
    float pwas = 0;
    float sWas = 0;
    float valxi = 0;
    float valyi = 0;
    float valx = 0;
    float valy = 0;
    float xacq = 0;
    float yacq = 0;
    float xac = 0;
    float xaq = 0;
    float yac = 0;
    float rqmdlq = 0;
    float rqpdlq = 0;
    float dx = 0;
    float dy = 0;
    char stateX = 0;
    char stateY = 0;
    char mDXY = 0;
    float numx = 0;
    float numy = 0;
    float valDL = 0; 
    float valDLq = 0;
    char runwhile = 1;
    float xRA = 0;
    float yRA = 0;
    float xRD = 0;
    float yRD = 0;
    char casoC = 0;//true V false;
    long cont = 0;
    long cont1 = 0;
    long contm = 0;
    long cont2 = 0;
    char baj = 0;
    float vdiq = 0;
    float vdq = 0;
    float valDX = 0;
    float valDY = 0;
    float ddx1 = 0;
    float ddy1 = 0;
    float ddx2 = 0;
    float ddy2 = 0;
    
    vdiq = genDistq(xa,ya,xb,yb);
    valxi = xa;
    valyi = ya;
    if(vdiq > 0 && vdiq <= ddl1q)
        casoC = 1;
    while(!casoC && cont1 < ndt1x) {
        valDL += ddl1;
        valDLq = (float)valDL*valDL;
        pwas = (float)2*valDL*r;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * valxi;
        xacq = (float)xac * xac;
        yacq = (float)yac * yac;
        rqmdlq = (float)rq - valDLq;
        rqpdlq = (float)rq + valDLq;
        zas = (float)xacq + yacq;
        pzas = (float)2 * zas;
        was = (float)((float)pwas - rqpdlq + zas)*((float)rqpdlq + pwas - zas);
        sWas = (float)sqrtf(was);
        numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx/pzas;
        numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy/pzas;
        vdq = genDistq(valxi, valyi, xb, yb);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdiq > vdq)//baja
            baj = 1;
        else if(baj)//baja, luego sube => casoC
            casoC = 1;
        vdiq = vdq;
        dlt += valDL;
        cont1++;
    }
    xRA = valxi;
    yRA = valyi;
    
    vdiq = genDistq(xb,yb,xRA,yRA);
    baj = 0;
    valDL = 0;
    valxi = xb;
    valyi = yb;
    if(vdiq <= ddl2q)
        casoC = 1;
    while(!casoC && cont < ndt2x - 1.0) {//-1 porque completo valDL llega a ser dl, dl será parte de rutaM
        valDL += ddl2;
        valDLq = (float)valDL*valDL;
        pwas = (float)2*valDL*r;
        xac = (float)valxi - xc;
        yac = (float)valyi - yc;
        xaq = (float)valxi * valxi;
        xacq = (float)xac * xac;
        yacq = (float)yac * yac;
        rqmdlq = (float)rq - valDLq;
        rqpdlq = (float)rq + valDLq;
        zas = (float)xacq + yacq;
        pzas = (float)2 * zas;
        was = (float)((float)pwas - rqpdlq + zas)*((float)rqpdlq + pwas - zas);
        sWas = (float)sqrtf(was);
        numx = (float)xac*rqmdlq + (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
        valxi = (float)numx/pzas;
        numy = (float)yac*rqmdlq - (float)sWas*xac + (float)zas*((float)valyi + yc);
        valyi = (float)numy/pzas;
        vdq = genDistq(valxi, valyi, xRA, yRA);//(float)xbi*xbi + (float)ybi*ybi;
        if(vdiq > vdq)//baja
            baj = 1;
        else if(baj)//baja, luego sube => casoC
            casoC = 1;
        vdiq = vdq;
        cont++;
    }
    xRD = valxi;
    yRD = valyi;
    
    if(!casoC) {
        valxi = xRA;
        valyi = yRA;
        vdq = genDistq(xRA, yRA, xRD, yRD);
        valDL = dl;
        valDLq = dlq;
        pwas = (float)2*valDL*r;
        rqmdlq = (float)rq - valDLq;
        rqpdlq = (float)rq + valDLq;
        while(valDLq <= vdq) {
            xaq = (float)valxi * valxi;
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            zas = (float)(float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rqpdlq + zas)*((float)pwas + rqpdlq - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valxi = (float)numx/pzas;
            numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
            valyi = (float)numy/pzas;
            vdq = genDistq(valxi, valyi, xRD, yRD);
            dlt += valDL;
            contm++;
        }
        while(runwhile) {
            vdq = genDistq(valxi, valyi, xb, yb);
            if(valDL > ddl2) {
                valDL -= ddl2;
                valDLq = (float)valDL*valDL;
                pwas = (float)2*valDL*r;
                rqmdlq = (float)rq - valDLq;
                rqpdlq = (float)rq + valDLq;
            }
            if(valDLq <= vdq) {
                xac = (float)valxi - xc;
                yac = (float)valyi - yc;
                xaq = (float)valxi * valxi;
                xacq = (float)xac * xac;
                yacq = (float)yac * yac;
                zas = (float)xacq + yacq;
                pzas = (float)2 * zas;
                was = (float)((float)pwas - rqpdlq + zas)*((float)rqpdlq + pwas - zas);
                sWas = (float)sqrtf(was);
                numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                        (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
                valxi = (float)numx/pzas;
                numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
                valyi = (float)numy/pzas;
                dlt += valDL;
                cont2++;
            }else {//último avance para el final ;)
                valDL = sqrtf(vdq);
                valxi = xb;
                valyi = yb;
                runwhile = 0;
                dlt += valDL;
                cont2++;
            }
        }
    }else {//casoC = 1
        stateY = xa >= xc;//funcionará?
        stateX = ya >= yc;//funcionará?
        float distX = 0;
        float distY = 0;
        float dx = 0;
        float dy = 0;
        dlt = 0;
        valxi = xa;
        valyi = ya;
        cont1 = 0;
        cont2 = 0;
        valDX = 0;
        valDY = 0;
        distX = xb - xa;
        distY = yb - ya;
        if(ya >= yc) {
            if(yb >= yc) {//A
                dx = (float)2*((float)distX / ((float)ndt1x + ndt2x));
                ddx1 = (float)dx / ndt1x;
                ddx2 = (float)dx / ndt2x;
                mDXY = 0;
            }else {//B
                dy = (float)2*((float)distY / ((float)ndt1x + ndt2x));
                ddy1 = (float)dy / ndt1x;
                ddy2 = (float)dy / ndt2x;
                mDXY = 1;
            }
        }else {
            if(yb >= yc) {//C
                dy = (float)2*((float)distY / ((float)ndt1x + ndt2x));
                ddy1 = (float)dy / ndt1x;
                ddy2 = (float)dy / ndt2x;
                mDXY = 1;
            }else {//D
                dx = (float)2*((float)distX / ((float)ndt1x + ndt2x));
                ddx1 = (float)dx / ndt1x;
                ddx2 = (float)dx / ndt2x;
                mDXY = 0;
            }
        }
        if(!mDXY) {
            while(cont1 < ndt1x) {
                valDX = valDX + ddx1;
                valx = valxi + valDX;
                if(stateX)
                    valy = circ_yb1(valyi,rq,xc,yc);
                else
                    valy = circ_yb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                valxi = valx;
                valyi = valy;
                dlt += valDL;
                cont1++;
            }
            while(cont2 < ndt2x - 1.0) {
                valDX = valDX - ddx2;
                valx = valxi + valDX;
                if(stateX)
                    valy = circ_yb1(valyi,rq,xc,yc);
                else
                    valy = circ_yb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                valxi = valx;
                valyi = valy;
                dlt += valDL;
                cont2++;
            }
        }else {
            while(cont1 < ndt1x) {
                valDY = valDY + ddy1;
                valy = valyi + valDY;
                if(stateY)
                    valx = circ_xb1(valyi,rq,xc,yc);
                else
                    valx = circ_xb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                valxi = valx;
                valyi = valy;
                dlt += valDL;
                cont1++;
            }
            while(cont2 < ndt2x - 1.0) {
                valDY = valDY - ddy2;
                valy = valyi + valDY;
                if(stateY)
                    valx = circ_xb1(valyi,rq,xc,yc);
                else
                    valx = circ_xb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                valxi = valx;
                valyi = valy;
                dlt += valDL;
                cont2++;
            }
        }
    }
    send_float_vt(dlt);
    send_float_vt((float)cont1);
    send_float_vt((float)contm);
    send_float_vt((float)cont2);
    if(casoC)
        send_float_vt(3.0);
    else
        send_float_vt(1.0);
    flex = gen_FLEX(ext,dlt);
    dlt = 0;
    valDL = 0;
    valDX = 0;
    valDY = 0;
    valxi = xa;
    valyi = ya;
    cont1 = 0;
    if(!casoC) {
        while(cont1 < ndt1x) {
            valDL = valDL + ddl1;
            valDLq = (float)valDL*valDL;
            pwas = (float)2*valDL*r;
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xaq = (float)valxi * valxi;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            rqmdlq = (float)rq - valDLq;
            rqpdlq = (float)rq + valDLq;
            zas = (float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rqpdlq + zas)*((float)rqpdlq + pwas - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valx = (float)numx/pzas;
            numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
            valy = (float)numy/pzas;
            dx = valx - valxi;
            dy = valy - valyi;
            valxi = valx;
            valyi = valy;
            calc_DM1(dx,dy);
            calc_DM2(dx,dy);
            calc_DME(valDL);
            dlt += valDL;
            cont1++;
        }
        cont = 0;
        valDL = dl;
        valDLq = dlq;
        pwas = (float)2*valDL*r;
        rqmdlq = (float)rq - valDLq;
        rqpdlq = (float)rq + valDLq;
        while(cont < contm) {
            xaq = (float)valxi * valxi;
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            zas = (float)(float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rqpdlq + zas)*((float)pwas + rqpdlq - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valx = (float)numx/pzas;
            numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
            valy = (float)numy/pzas;
            dx = valx - valxi;
            dy = valy - valyi;
            valxi = valx;
            valyi = valy;
            calc_DM1(dx,dy);
            calc_DM2(dx,dy);
            calc_DME(valDL);
            dlt += valDL;
            cont++;
        }
        cont = cont2;
        cont2 = 0;
        while(cont2 < cont - 1.0) {
            if(cont2 < ndt2x - 1.0) {
                valDL = valDL - ddl2;
                valDLq = (float)valDL*valDL;
                pwas = (float)2*valDL*r;
                rqmdlq = (float)rq - valDLq;
                rqpdlq = (float)rq + valDLq;
            }
            xac = (float)valxi - xc;
            yac = (float)valyi - yc;
            xaq = (float)valxi * valxi;
            xacq = (float)xac * xac;
            yacq = (float)yac * yac;
            zas = (float)xacq + yacq;
            pzas = (float)2 * zas;
            was = (float)((float)pwas - rqpdlq + zas)*((float)rqpdlq + pwas - zas);
            sWas = (float)sqrtf(was);
            numx = (float)xac*rqmdlq - (float)sWas*yac + (float)xaq*valxi - (float)xaq*xc -
                    (float)valxi*((float)xcq - yacq) + (float)xc*((float)xcq + yacq);
            valx = (float)numx/pzas;
            numy = (float)yac*rqmdlq + (float)sWas*xac + (float)zas*((float)valyi + yc);
            valy = (float)numy/pzas;
            dx = valx - valxi;
            dy = valy - valyi;
            valxi = valx;
            valyi = valy;
            calc_DM1(dx,dy);
            calc_DM2(dx,dy);
            calc_DME(valDL);
            dlt += valDL;
            cont2++;
        }
        valDL = genDist(valxi,valyi,xb,yb);
        dx = xb - valxi;
        dy = yb - valyi;
        valxi = valx;
        valyi = valy;
        calc_DM1(dx,dy);
        calc_DM2(dx,dy);
        calc_DME(valDL);
        dlt += valDL;
        cont2++;
    }else {
        if(!mDXY) {
            while(cont1 < ndt1x) {
                valDX = valDX + ddx1;
                valx = valxi + valDX;
                if(stateX)
                    valy = circ_yb1(valyi,rq,xc,yc);
                else
                    valy = circ_yb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                dx = valx - valxi;
                dy = valy - valyi;
                valxi = valx;
                valyi = valy;
                calc_DM1(dx,dy);
                calc_DM2(dx,dy);
                calc_DME(valDL);
                dlt += valDL;
                cont1++;
            }
            cont2 = 0;
            while(cont2 < ndt2x - 1.0) {
                valDX = valDX - ddx2;
                valx = valxi + valDX;
                if(stateX)
                    valy = circ_yb1(valyi,rq,xc,yc);
                else
                    valy = circ_yb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                dx = valx - valxi;
                dy = valy - valyi;
                valxi = valx;
                valyi = valy;
                calc_DM1(dx,dy);
                calc_DM2(dx,dy);
                calc_DME(valDL);
                dlt += valDL;
                cont2++;
            }
        }else {
            while(cont1 < ndt1x) {
                valDY = valDY + ddy1;
                valy = valyi + valDY;
                if(stateY)
                    valx = circ_xb1(valyi,rq,xc,yc);
                else
                    valx = circ_xb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                dx = valx - valxi;
                dy = valy - valyi;
                valxi = valx;
                valyi = valy;
                calc_DM1(dx,dy);
                calc_DM2(dx,dy);
                calc_DME(valDL);
                dlt += valDL;
                cont1++;
            }
            cont2 = 0;
            while(cont2 < ndt2x - 1.0) {
                valDY = valDY - ddy2;
                valy = valyi + valDY;
                if(stateY)
                    valx = circ_xb1(valyi,rq,xc,yc);
                else
                    valx = circ_xb2(valyi,rq,xc,yc);
                valDL = genDist(valxi,valyi,valx,valy);
                dx = valx - valxi;
                dy = valy - valyi;
                valxi = valx;
                valyi = valy;
                calc_DM1(dx,dy);
                calc_DM2(dx,dy);
                calc_DME(valDL);
                dlt += valDL;
                cont2++;
            }
        }
    }
    send_float_vt(dlt);
    send_float_vt((float)cont1);
    send_float_vt((float)contm);
    send_float_vt((float)cont2);
    if(casoC)
        send_float_vt(3.0);
    else
        send_float_vt(1.0);
}

void g3(float xa, float ya, float xb, float yb, float i, float j, float ext, float feed) {
    flex = 0;
    g3um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, ext, feed*1000);
}