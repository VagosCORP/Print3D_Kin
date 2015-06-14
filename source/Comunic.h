typedef struct floatData {
    union {
        struct {
            char floata : 8;//m
            char floatb : 8;
            char floatc : 8;
            char floatd : 8;//M
        };
        struct {
            float floatdat;
        };
  };
}FLOATDATA;

typedef struct int32Data {
    union {
        struct {
            char int32a : 8;//m
            char int32b : 8;
            char int32c : 8;
            char int32d : 8;//M
        };
        struct {
            int int32dat;
        };
  };
}INT32DATA;

typedef struct int16Data {
    union {
        struct {
            char int16a : 8;//m
            char int16b : 8;//M
        };
        struct {
            short int16dat;
        };
  };
}INT16DATA;
    
void putch(char val);
    
void send_float(float valFloat){//funcion pensada para enviar los diferentes elementos de una variable tipo flotante de 3 bytes
//    signed char i;
//    for(i = 3; i >= 0; i--){
//        char byte = *((unsigned char *) & valFloat + i);
//        putch(byte);
//    }
    FLOATDATA floatdata;
    floatdata.floatdat = valFloat;
    putch(floatdata.floatd);
    putch(floatdata.floatc);
    putch(floatdata.floatb);
    putch(floatdata.floata);
}

void send_int32(long valLong){
//    signed char i;
//    for(i = 3; i >= 0; i--){
//        char byte = *((unsigned char *) & valLong + i);
//        putch(byte);
//    }
    INT32DATA data;
    data.int32dat = valLong;
    putch(data.int32d);
    putch(data.int32c);
    putch(data.int32b);
    putch(data.int32a);
}

void send_int16(int valShort){////funcion pensada para enviar los diferentes elementos de una variable int (2 bytes)
//    signed char i;
//    for(i = 1; i >= 0; i--){
//        char byte = *((unsigned char *) & valShort + i);
//        putch(byte);
//    }
    INT16DATA data;
    data.int16dat = valShort;
    putch(data.int16b);
    putch(data.int16a);
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
    data.floatd = byte3;
    data.floatc = byte2;
    data.floatb = byte1;
    data.floata = byte0;
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
    data.int32d = byte3;
    data.int32c = byte2;
    data.int32b = byte1;
    data.int32a = byte0;
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
    data.int16b = byte1;
    data.int16a = byte0;
    return data.int16dat;
}