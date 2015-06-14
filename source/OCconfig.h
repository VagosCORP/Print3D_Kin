#ifndef OCCONFIG_H
#define	OCCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


void config_OC1(void) {
    OC1RS = 39999;
    OC1R = 3000;
    OC1CON1bits.OCSIDL = 0;
    OC1CON1bits.OCTSEL = 0b100;//100 = timer1
    OC1CON1bits.ENFLT = 0b000;
    OC1CON1bits.TRIGMODE = 1;
    OC1CON2bits.FLTMD = 0;
    OC1CON2bits.FLTOUT = 0;
    OC1CON2bits.FLTTRIEN = 0;
    OC1CON2bits.OCINV = 0;
    OC1CON2bits.DCB = 0b00;
    OC1CON2bits.OC32 = 0;
    OC1CON2bits.OCTRIG = 0;
    OC1CON2bits.OCTRIS = 0;
    OC1CON2bits.SYNCSEL = 0b11111;
    OC1CON1bits.OCM = 0b110;
}
    
void config_OC2(void) {
    OC2RS = 39999;
    OC2R = 3000;
    OC2CON1bits.OCSIDL = 0;
    OC2CON1bits.OCTSEL = 0b100;//100 = timer1
    OC2CON1bits.ENFLT = 0b000;
    OC2CON1bits.TRIGMODE = 1;
    OC2CON2bits.FLTMD = 0;
    OC2CON2bits.FLTOUT = 0;
    OC2CON2bits.FLTTRIEN = 0;
    OC2CON2bits.OCINV = 0;
    OC2CON2bits.DCB = 0b00;
    OC2CON2bits.OC32 = 0;
    OC2CON2bits.OCTRIG = 0;
    OC2CON2bits.OCTRIS = 0;
    OC2CON2bits.SYNCSEL = 0b11111;
    OC2CON1bits.OCM = 0b110;
}

void config_OC3(void) {
    OC3RS = 39999;
    OC3R = 3000;
    OC3CON1bits.OCSIDL = 0;
    OC3CON1bits.OCTSEL = 0b100;
    OC3CON1bits.ENFLT = 0b000;
    OC3CON1bits.TRIGMODE = 1;
    OC3CON2bits.FLTMD = 0;
    OC3CON2bits.FLTOUT = 0;
    OC3CON2bits.FLTTRIEN = 0;
    OC3CON2bits.OCINV = 0;
    OC3CON2bits.DCB = 0b00;
    OC3CON2bits.OC32 = 0;
    OC3CON2bits.OCTRIG = 0;
    OC3CON2bits.OCTRIS = 0;
    OC3CON2bits.SYNCSEL = 0b11111; 
    OC3CON1bits.OCM = 0b110;
}
    

#ifdef	__cplusplus
}
#endif

#endif	/* OCCONFIG_H */

