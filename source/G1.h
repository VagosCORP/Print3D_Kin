void g1_um(float xa, float ya, float xb, float yb, float deltaXY) {
    float val_factx = (float)xb - xa;
    float val_facty = (float)yb - ya;
    float valM = 0;
    float valnM = 0;
    char dy = 0;
    if(val_factx != 0 && val_facty != 0) {
        valM = (float)val_factx / val_facty;
        valnM = (float)val_facty / val_factx;
    }
    float const_dx = deltaXY;
    float const_dy = (float)const_dx * valM;
    if(val_factx < val_facty) {
        const_dy = deltaXY;
        const_dx = (float)const_dy * valnM;
        dy = 1;
    }
    float valx = xa;
    float valy = ya;
    long cont = 0;
    float delta = 0;
    float runwhile = 1;
    while(runwhile) {
        calc_DM1(const_dx, const_dy);
        calc_DM2(const_dx, const_dy);
        valx = (float)valx + const_dx;
        valy = (float)valy + const_dy;
        delta = (float)xb - valx;
        if(dy)
            delta = (float)yb - valy;
        if(deltaXY > delta)
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