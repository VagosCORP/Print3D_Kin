void g1_um(float xa, float ya, float xb, float yb, float dl) { 
    float val_factx = (float)xb - xa;
    float val_facty = (float)yb - ya;
    float insqrt = (float)val_factx*val_factx + (float)val_facty*val_facty;
    float const_val = (float)sqrtf(insqrt);
    float cosA = (float)val_factx / const_val;
    float sinA = (float)val_facty / const_val;
    float dx = 0;
    float dy = 0;
    float valx = xa;
    float valy = ya;
    long cont = 0;
    float delta = 0;
    float runwhile = 1;
    while(runwhile) {
        float dlc = (float)dl*dl;
        dx = (float)dl*cosA;
        dy = (float)dl*sinA;
        calc_DM1(dx, dy);
        calc_DM2(dx, dy);
        valx = (float)valx + dx;
        valy = (float)valy + dy;
        delta = (float)(xb - valx)*(xb - valx) + (yb - valy)*(yb - valy);
        if(dlc > delta)
            runwhile = 0;
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