#ifndef CONFIGTIMER2_H
#define	CONFIGTIMER2_H

#ifdef	__cplusplus
extern "C" {
#endif


void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void) {
    
    IFS0bits.T1IF = 0; // Clear Timer2 Interrupt Flag}
}
    
void config_T1(void) {
/////////Configuración timer 2/////////
    T1CONbits.TSIDL = 0;
    T1CONbits.TCS = 0; //clock source, 0 = core
    T1CONbits.TGATE = 0;
    T1CONbits.TCKPS = 0b01; //1:8 PreScaller
    PR1 = 65535;
    IPC0bits.T1IP = 3; // Prioridad 1 para inttimer1
    IFS0bits.T1IF = 0; // limpiar flag de interrupcion 1
    IEC0bits.T1IE = 0; // habilitar interrupcion del timer1
    TMR1 = 0;
    T1CONbits.TON = 1; // iniciar timer 1
}
  

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGTIMER2_H */

