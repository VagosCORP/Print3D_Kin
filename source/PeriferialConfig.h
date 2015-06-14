#ifndef PERIFERIALCONFIG_H
#define	PERIFERIALCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


void config_Periferials(void) {
    ///////////Asignación de Pines////////////
    OSCCON = 0x46; //Desbloqueo Fase 1
    OSCCON = 0x57; //Desbloqueo Fase 2
    OSCCONbits.IOLOCK = 0; //Desbloqueo Fase 3
    RPINR3bits.T3CKR= 7; //Asignación Input T3CK a RP7
    RPINR4bits.T5CKR = 8; //Asignación Input T5CK a RP8
    RPINR18bits.U1RXR = 10; //Asignación Input U1RX a RP10
    RPOR5bits.RP11R = 3; //Asignación Output RP11 a U1TX
    RPOR0bits.RP0R = 18; //Asignación Output RP0 a OC1
    RPOR0bits.RP1R = 19; //Asignación Output RP1 a OC2
    RPOR1bits.RP2R = 20; //Asignación Output RP2 a OC3
    OSCCON = 0x46; //Rebloqueo Fase 1
    OSCCON = 0x57; //Rebloqueo Fase 2
    OSCCONbits.IOLOCK = 1; //Rebloqueo Fase 3
}


#ifdef	__cplusplus
}
#endif

#endif	/* PERIFERIALCONFIG_H */

