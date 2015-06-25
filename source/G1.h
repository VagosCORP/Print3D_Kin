void g1_um(float xa, float ya, float xb, float yb, float feed) {
    float ndt1x = ndt1;
    float ndt2x = ndt2;
    float dl = (float)((float)dt*feed) / ((float)60000000.0);
    float val_factx = (float)xb - xa;
    float val_facty = (float)yb - ya;
    float insqrt = (float)val_factx*val_factx + (float)val_facty*val_facty;
    float dlt = (float)sqrtf(insqrt);
    float cosA = (float)val_factx / dlt;
    float sinA = (float)val_facty / dlt;
    float ddl1 = (float)dl / ndt1x;
    float ddl2 = (float)dl / ndt2x;
    float ndtmx2 = (float)dlt - ndt1x - ndt2x;
    float ndtm = (float)ndtmx2/2.0;
    if(ndtm < 0) {
        float num = (float)ndt1x*dlt;
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
    float dx = 0;
    float dy = 0;
    float valx = xa;
    float valy = ya;
    long cont = 0;
    float delta = 0;
    float runwhile = 1;
    float valDL = 0;
    while(runwhile) {
        if(state_S1) {
            if(contState < ndt1x - 1) {
                valDL = valDL + ddl1;
                contState++;
            }else {
                valDL = valDL + ddl1;
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
                valDL = valDL - ddl2;
                contState++;
            }else {
                valDL = valDL - ddl2;//posible, valDL = ddl2 hasta que se complete la distancia deseada
                runwhile = 0;
                contState = 0;
                state_S2 = 0;
            }
        }
//        float dlc = (float)dlc;
        dx = (float)valDL*cosA;
        dy = (float)valDL*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = (float)(xb - valx)*(xb - valx) + (yb - valy)*(yb - valy);
//        if(dlc > delta)
//            runwhile = 0;
        cont++;
//        putch(13);
//        send_float(valx);
//        putch(10);
//        putch(13);
//        send_float(valy);
//        putch(10);
    }
//    cont++;
//    putch(13);
//    send_float(valx);
//    putch(10);
//    putch(13);
//    send_float(valy);
//    putch(10);
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

void g1(float xa, float ya, float xb, float yb, float deltaXY) {
    g1_um(xa*1000, ya*1000, xb*1000, yb*1000, deltaXY*1000);
}

//const_val = sqrt(val_factx^2+val_facty^2)
//cos(ang) = val_factx / const_val
//sin(ang) = val_facty / const_val
//dl*sin o cos = dy o dx respectivamente ;)