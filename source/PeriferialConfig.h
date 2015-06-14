#ifndef PERIFERIALCONFIG_H
#define	PERIFERIALCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


void config_Periferials(void) {
    ///////////Asignaci�n de Pines////////////
    OSCCON = 0x46; //Desbloqueo Fase 1
    OSCCON = 0x57; //Desbloqueo Fase 2
    OSCCONbits.IOLOCK = 0; //Desbloqueo Fase 3
    RPINR3bits.T3CKR= 7; //Asignaci�n Input T3CK a RP7
    RPINR4bits.T5CKR = 8; //Asignaci�n Input T5CK a RP8
    RPINR18bits.U1RXR = 10; //Asignaci�n Input U1RX a RP10
    RPOR5bits.RP11R = 3; //Asignaci�n Output RP11 a U1TX
    RPOR0bits.RP0R = 18; //Asignaci�n Output RP0 a OC1
    RPOR0bits.RP1R = 19; //Asignaci�n Output RP1 a OC2
    RPOR1bits.RP2R = 20; //Asignaci�n Output RP2 a OC3
    OSCCON = 0x46; //Rebloqueo Fase 1
    OSCCON = 0x57; //Rebloqueo Fase 2
    OSCCONbits.IOLOCK = 1; //Rebloqueo Fase 3
}


#ifdef	__cplusplus
}
#endif

#endif	/* PERIFERIALCONFIG_H */

