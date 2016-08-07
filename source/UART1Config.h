char dataCont = 0;
char gdataCont = 0;
char dataInit = 0;
char GcodeInit = 0;
char ncG = 0;
char byte1 = 0;
char byte2 = 0;
char error = 0;

char STT_PKG = 'G';

char END_PKG = ';';

typedef union {
    struct {
        char charD;
        float valD;
    };
    struct {
        char charD;
        char valDa;//Lesssifnificant
        char valDb;
        char valDc;
        char valDd;//MostSignificant
    };
}GCODE;

typedef struct {
        float valX;
        float valY;
        float valZ;
        float valE;
        float valF;
        float valS;
}G1CODE;

typedef struct {
        float valX;
        float valY;
        float valI;
        float valJ;
        float valE;
        float valF;
}G2CODE;

typedef struct {
        float valX;
        float valY;
        float valI;
        float valJ;
        float valE;
        float valF;
}G3CODE;

GCODE gcode;

G1CODE g1code = {0,0,0,0,0,0};
G2CODE g2code = {0,0,0,0,0,0};
G3CODE g3code = {0,0,0,0,0,0};

void putch(char val) {
    while(U1STAbits.UTXBF);
    U1TXREG = val;
}

void save_datg1(GCODE gcode) {
    switch(gcode.charD) {
        case('X'): {
            g1code.valX = gcode.valD;
            break;
        }
        case('Y'): {
            g1code.valY = gcode.valD;
            break;
        }
        case('Z'): {
            g1code.valZ = gcode.valD;
            break;
        }
        case('E'): {
            g1code.valE = gcode.valD;
            break;
        }
        case('F'): {
            g1code.valF = gcode.valD;
            break;
        }
        case('S'): {
            g1code.valS = gcode.valD;
            break;
        }
    }
}

void save_datg2(GCODE gcode) {
    switch(gcode.charD) {
        case('X'): {
            g2code.valX = gcode.valD;
            break;
        }
        case('Y'): {
            g2code.valY = gcode.valD;
            break;
        }
        case('I'): {
            g2code.valI = gcode.valD;
            break;
        }
        case('J'): {
            g2code.valJ = gcode.valD;
            break;
        }
        case('E'): {
            g2code.valE = gcode.valD;
            break;
        }
        case('F'): {
            g2code.valF = gcode.valD;
            break;
        }
    }
}

void save_datg3(GCODE gcode) {
    switch(gcode.charD) {
        case('X'): {
            g3code.valX = gcode.valD;
            break;
        }
        case('Y'): {
            g3code.valY = gcode.valD;
            break;
        }
        case('I'): {
            g3code.valI = gcode.valD;
            break;
        }
        case('J'): {
            g3code.valJ = gcode.valD;
            break;
        }
        case('E'): {
            g3code.valE = gcode.valD;
            break;
        }
        case('F'): {
            g3code.valF = gcode.valD;
            break;
        }
    }
}

void startGcode(char type) {
    Gtype = type;
    
}

//char char char float char float char float char float char float char float char => 33 bytes
//G1 X <float> Y <float> Z <float> E <float> F <float> S <float> ;
//G2 X <float> Y <float> I <float> J <float> E <float> F <float> ;
//G3 X <float> Y <float> I <float> J <float> E <float> F <float> ;
void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void) {
    if(dataInit == 0) {
        if(U1RXREG == STT_PKG) {
            GcodeInit = 1;
            dataCont = 0;
            gdataCont = 0;
        }
    }else {
        if(dataCont == 0)
            ncG = U1RXREG;
        else if(gdataCont == 0) {
            gcode.charD = U1RXREG; //Mayor significancia
            if(gcode.charD == END_PKG) {
                error = 0;
                GcodeInit = 0;
            }
        }else if(gdataCont == 1)
            gcode.valDd = U1RXREG; //...M
        else if(gdataCont == 2)
            gcode.valDc = U1RXREG; //...m
        else if(gdataCont == 3)
            gcode.valDb = U1RXREG; //Menor significancia
        else if(gdataCont == 4) {
            gcode.valDa = U1RXREG; //Mayor significancia
            if(ncG == G1)
                save_datg1(gcode);
            else if(ncG == G2)
                save_datg2(gcode);
            else if(ncG == G3)
                save_datg3(gcode);
            else {
                error = 1;
                GcodeInit = 0;
            }
            gdataCont = 0;
        }
        dataCont++;
    }
    IFS0bits.U1RXIF = 0;
}
    
void config_uart1(void) {
    /////////Configuración UART 1/////////
//    U1BRG = 25; //BaudRate = 38400;//24F
//    U1BRG = 8; //BaudRate = 115200;//24F
    //    U1BRG = 259; //BaudRate = 9600;//24H
    U1BRG = 64; //BaudRate = 38400;//24H
    //    U1BRG = 21; //BaudRate = 115200;//24H
    U1MODEbits.UARTEN = 1;
    U1MODEbits.USIDL = 0;
    U1MODEbits.IREN = 0;
    U1MODEbits.RTSMD = 1;
    U1MODEbits.UEN = 0b00;
    U1MODEbits.WAKE = 0;
    U1MODEbits.LPBACK = 0;
    U1MODEbits.ABAUD = 0;
    U1MODEbits.URXINV = 0;//24F ==> borrar U
    U1MODEbits.BRGH = 0;
    U1MODEbits.PDSEL = 0b00;
    U1MODEbits.STSEL = 0;
    U1STAbits.UTXISEL1 = 0;
    U1STAbits.UTXISEL0 = 1;
    U1STAbits.UTXINV = 0;
    U1STAbits.UTXBRK = 0;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXISEL = 0b01;
    U1STAbits.ADDEN = 0;
    U1STAbits.RIDLE = 0;
    IPC2bits.U1RXIP = 1; // Prioridad 1 para inttimer1
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 1;
    //    U1STAbits.UTXBF //recurso, buffer vacio
    //    U1STAbits.URXDA //recurso, datos recibidos
}