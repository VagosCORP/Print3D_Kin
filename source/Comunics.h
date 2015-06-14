typedef struct floatData {
    union {
        struct {
            char floata : 8;
            char floatb : 8;
            char floatc : 8;
            char floatd : 8;
        };
        struct {
            float floatdat;
        };
  };
}FLOATDATA;

typedef struct int32Data {
    union {
        struct {
            char int32a : 8;
            char int32b : 8;
            char int32c : 8;
            char int32d : 8;
        };
        struct {
            int int32dat;
        };
  };
}INT32DATA;

typedef struct int16Data {
    union {
        struct {
            char int16a : 8;
            char int16b : 8;
        };
        struct {
            short int16dat;
        };
  };
}INT16DATA;
    
void putch(char val) {
    while(U1STAbits.UTXBF);
    U1TXREG = val;
}
    
void send_float(float valFloat){//funcion pensada para enviar los diferentes elementos de una variable tipo flotante de 3 bytes
    FLOATDATA floatdata;
    floatdata.floatdat = valFloat;
    putch(floatdata.floata);
    putch(floatdata.floatb);
    putch(floatdata.floatc);
    putch(floatdata.floatd);
//    signed char i;
//    for(i = 3; i >= 0; i--){
//        char byte = *((unsigned char *) & valFloat + i);
//        putch(byte);
//    }
}

void send_int32(long valLong){
    INT32DATA data;
    data.int32dat = valLong;
    putch(data.int32a);
    putch(data.int32b);
    putch(data.int32c);
    putch(data.int32d);
//    signed char i;
//    for(i = 3; i >= 0; i--){
//        char byte = *((unsigned char *) & valLong + i);
//        putch(byte);
//    }
}

void send_int16(int valShort){////funcion pensada para enviar los diferentes elementos de una variable int (2 bytes)
    INT16DATA data;
    data.int16dat = valShort;
    putch(data.int16a);
    putch(data.int16b);
//    signed char i;
//    for(i = 1; i >= 0; i--){
//        char byte = *((unsigned char *) & valShort + i);
//        putch(byte);
//    }
}

float genFloat(char byte3, char byte2, char byte1, char byte0) { //a lo java!!!
//    float floatRes;
//    unsigned char * val3 = (unsigned char *) & floatRes + 3; //Mayor significancia
//    unsigned char * val2 = (unsigned char *) & floatRes + 2; //Media mayor
//    unsigned char * val1 = (unsigned char *) & floatRes + 1; //Media menor
//    unsigned char * val0 = (unsigned char *) & floatRes + 0; //Menor significancia
//    *val3 = byte3;
//    *val2 = byte2;
//    *val1 = byte1;
//    *val0 = byte0;
//    return floatRes;
    FLOATDATA data;
    data.floata = byte3;
    data.floatb = byte2;
    data.floatc = byte1;
    data.floatd = byte0;
    return data.floatdat;
}

long genLong(char byte3, char byte2, char byte1, char byte0) { //a lo java!!!
//    long longRes;
//    unsigned char * val3 = (unsigned char *) & longRes + 3; //Mayor significancia
//    unsigned char * val2 = (unsigned char *) & longRes + 2; //Media mayor
//    unsigned char * val1 = (unsigned char *) & longRes + 1; //Media menor
//    unsigned char * val0 = (unsigned char *) & longRes + 0; //Menor significancia
//    *val3 = byte3;
//    *val2 = byte2;
//    *val1 = byte1;
//    *val0 = byte0;
//    return longRes;
    INT32DATA data;
    data.int32a = byte3;
    data.int32b = byte2;
    data.int32c = byte1;
    data.int32d = byte0;
    return data.int32dat;
}

short genShort(char byte1, char byte0) { //a lo java!!!
//    short shortRes;
//    unsigned char * val1 = (unsigned char *) & shortRes + 1; //Media menor
//    unsigned char * val0 = (unsigned char *) & shortRes + 0; //Menor significancia
//    *val1 = byte1;
//    *val0 = byte0;
//    return shortRes;
    INT16DATA data;
    data.int16a = byte1;
    data.int16b = byte0;
    return data.int16dat;
}