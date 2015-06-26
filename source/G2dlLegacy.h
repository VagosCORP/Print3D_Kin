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
    float difXa = (float)xa - xc;
    float difYa = (float)ya - yc;
    float difXb = (float)xb - xc;
    float difYb = (float)yb - yc;
    float cosAngA = (float)difXa / r;
    float cosAngB = (float)difXb / r;
    float angA = (float)acosf(cosAngA);
    if(difYa < 0) {
        if(difXa < 0)
            angA += (float)pi/2;
        else
            angA += pi;
    }
    float angB = (float)acosf(cosAngB);
    if(difYb < 0) {
        if(difXb < 0)
            angB += (float)pi/2;
        else
            angB += pi;
    }
    float dAngT = angA - angB;
    if(dAngT <= 0)
        dAngT = (float)dAngT + (float)2.0*pi;
    float cosdAng = (float)1.0 - ((float)dlc / ((float)2.0*rc));
    float dAng = (float)acosf(cosdAng);
    float ddAng1 = (float)dAng / ndt1x;
    float ddAng2 = (float)dAng / ndt2x;
    float sumNdt = (float)((float)2.0*dAngT)/dAng;
    float ndtmx2 = (float)sumNdt - ndt1x - ndt2x;
    float ndtm = (float)ndtmx2/2.0;
    if(ndtm < 0) {
        float num = (float)ndt1x*sumNdt;
        float constR = (float)ndt2x/ndt1x;
        float den = (float)1.0 + constR;
        float insq = (float)num/den;
        ndt1x = (float)sqrtf(insq);
        ndt2x = (float)ndt1x*constR;
        ndtm = 0;
    }
    char state_S1 = 1;
    char state_SM = 1;
    char state_S2 = 1;
    int contState = 0;
    float cosAp = 0;//(float)1 - (float)(((float)dlc) / ((float)2*rc));
    float Z = 0;
    float valxi = xa;
    float valyi = ya;
    float valx = 0;
    float valy = 0;
    float dx = 0;
    float dy = 0;
    float W = rc/*(float)(xc-valx)*(xc-valx) + (float)(yc-valy)*(yc-valy)*/;//Teoricamente sería r^2
    float constinsqrt = 0;
    float numx = 0;
    float numy = 0;
    float valAng = 0;  
    char runwhile = 1;
    float delta = 0;
//    float mydelta = (float)dl*dl;
    long cont = 0;
    while(runwhile) {
        if(state_S1) {
            if(contState < ndt1x - 1) {
                valAng = valAng + ddAng1;
                cosAp = (float)cosf(valAng);
                contState++;
            }else {
                valAng = valAng + ddAng1;
                cosAp = (float)cosf(valAng);
                contState = 0;
                state_S1 = 0;
            }
        }else if(state_SM) {
            if(contState < ndtm - 1)
                contState++;
            else {
                contState = 0;
                state_SM = 0;
            }
        }else if(state_S2) {
            if(contState < ndt2x - 1) {
                valAng = valAng - ddAng2;
                cosAp = (float)cosf(valAng);
                contState++;
            }else {
                valAng = valAng - ddAng2;//posible, valAng = ddAng2 hasta que se complete la distancia deseada
                cosAp = (float)cosf(valAng);
                runwhile = 0;
                contState = 0;
                state_S2 = 0;
            }
        }
        Z = (float)2*cosAp - 1.0;
        constinsqrt = (float)W*rc*((float)4 - Z*2) - (float)Z*Z*rc*rc - (float)W*W;
        numx = (float)(valy-yc)*sqrtf(constinsqrt) - (float)Z*rc*(xc-valx) + (float)W*(xc+valx);
        numy = (float)(xc-valx)*sqrtf(constinsqrt) - (float)Z*rc*(yc-valy) + (float)W*(yc+valy);
        valx = (float)numx / ((float)2*W);
        valy = (float)numy / ((float)2*W);
        dx = valx - valxi;
        dy = valy - valyi;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        valxi = valx;
        valyi = valy;
        delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
//        if(mydelta > delta)
//            runwhile = 0;
        cont++;
//        send_float_vt(valx);
//        send_float_vt(valy);
    }
//    cont++;
//    send_float_vt(valx);
//    send_float_vt(valy);
    send_float_vt((float)cont);
}
    
void g2(float xa, float ya, float xb, float yb, float i, float j, float dl) {
    g2_um(xa*1000, ya*1000, xb*1000, yb*1000, i*1000, j*1000, dl*1000);
}

//float rc = (float)i*i + (float)j*j;
//float xc = (float)xa + i;
//float yc = (float)ya + j;
//float valx = xa;
//float valy = ya;
//char runwhile = 1;
//float mydelta = 0;
//float delta = 0;
//float dx = 0;
//float dy = 0;
//long cont = 0;
//while(runwhile) {
//    if(valy > yc) {
//        dx = vdx;
//        dy = (float)yc - valy + (float)sqrtf(rc - (float)(valx + dx - xc)*(valx + dx - xc));
//    }else if(valy < yc) {
//        dx = -vdx
//        dy = (float)yc - valy - (float)sqrtf(rc - (float)(valx + dx - xc)*(valx + dx - xc));
//    }else {
//        if(valx > xc) {
//            dx = -vdx;
//            dy = (float)yc - valy - (float)sqrtf(rc - (float)(valx + dx - xc)*(valx + dx - xc));
//        }else if(valx < xc) {
//            dx = vdx;
//            dy = (float)yc - valy + (float)sqrtf(rc - (float)(valx + dx - xc)*(valx + dx - xc));
//        }
//    }
//    valx = valx + dx;
//    valy = valy + dy;
//    mydelta = (float)dx*dx + dy*dy;
//    delta = (float)(xb-valx)*(xb-valx) + (float)(yb-valy)*(yb-valy);
//    if(mydelta > delta)
//        runwhile = 0;
//    cont++;
//}