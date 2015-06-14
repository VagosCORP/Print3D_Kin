#ifndef TIMER3CONFIG_H
#define	TIMER3CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


long tof = 0;
    
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void) {
    tof++;
    IFS0bits.T3IF = 0; // Clear Timer3 Interrupt Flag}
}
    
void config_T3(void) {
    T3CONbits.TSIDL = 1;
    T3CONbits.TCS = 0;
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b00; //1:1
    PR3 = 65535;
    IPC2bits.T3IP = 3; // Prioridad 2 para inttimer3
    IFS0bits.T3IF = 0; // limpiar flag de interrupcion 3
    IEC0bits.T3IE = 1; // habilitar interrupcion del timer3
    TMR3 = 0;
    T3CONbits.TON = 0;
}


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER3CONFIG_H */

