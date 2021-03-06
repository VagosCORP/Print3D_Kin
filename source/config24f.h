//#define    FCY    16000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
//#include <libpic30.h>        // __delayXXX() functions macros defined here
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <stdint.h>
//#include <xc.h>
//
//// CONFIG4
//#pragma config DSWDTPS = DSWDTPSB       // DSWDT Postscale Select (1:8,388,608 (2.4 hours))
//#pragma config DSWDTOSC = LPRC          // Deep Sleep Watchdog Timer Oscillator Select (DSWDT uses Low Power RC Oscillator (LPRC))
//#pragma config RTCOSC = LPRC            // RTCC Reference Oscillator Select (RTCC uses Low Power RC Oscillator (LPRC))
//#pragma config DSBOREN = ON             // Deep Sleep BOR Enable bit (BOR enabled in Deep Sleep)
//#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer (DSWDT disabled)
//
//// CONFIG3
//#pragma config WPFP = WPFP63            // Write Protection Flash Page Segment Boundary (Highest Page (same as page 21))
//#pragma config SOSCSEL = IO             // Secondary Oscillator Pin Mode Select (SOSC pins have digital I/O functions (RA4, RB4))
//#pragma config WUTSEL = LEG             // Voltage Regulator Wake-up Time Select (Default regulator start-up time used)
//#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Segmented code protection disabled)
//#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Last page and Flash Configuration words are unprotected)
//#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)
//
//// CONFIG2
//#pragma config POSCMOD = NONE           // Primary Oscillator Select (Primary Oscillator disabled)
//#pragma config I2C1SEL = PRI            // I2C1 Pin Select bit (Use default SCL1/SDA1 pins for I2C1 )
//#pragma config IOL1WAY = OFF            // IOLOCK One-Way Set Enable (The IOLOCK bit can be set and cleared using the unlock sequence)
//#pragma config OSCIOFNC = ON            // OSCO Pin Configuration (OSCO pin functions as port I/O (RA3))
//#pragma config FCKSM = CSDCMD           // Clock Switching and Fail-Safe Clock Monitor (Sw Disabled, Mon Disabled)
//#pragma config FNOSC = FRCPLL           // Initial Oscillator Select (Fast RC Oscillator with Postscaler and PLL module (FRCPLL))
//#pragma config PLL96MHZ = ON            // 96MHz PLL Startup Select (96 MHz PLL Startup is enabled automatically on start-up)
//#pragma config PLLDIV = DIV2            // USB 96 MHz PLL Prescaler Select (Oscillator input divided by 2 (8 MHz input))
//#pragma config IESO = OFF               // Internal External Switchover (IESO mode (Two-Speed Start-up) disabled)
//
//// CONFIG1
//#pragma config WDTPS = PS256            // Watchdog Timer Postscaler (1:256)
//#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
//#pragma config WINDIS = OFF             // Windowed WDT (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
//#pragma config FWDTEN = OFF             // Watchdog Timer (Watchdog Timer is disabled)
//#pragma config ICS = PGx3               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC3/PGED3)
//#pragma config GWRP = OFF               // General Segment Write Protect (Writes to program memory are allowed)
//#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
//#pragma config JTAGEN = ON              // JTAG Port Enable (JTAG port is enabled)
//
//#define delay_us    __delay_us
//#define delay_ms    __delay_ms
//
//
//void config_clock(void) {
//    /////////Configuración de Clock/////////
//    CLKDIVbits.ROI = 0;
//    CLKDIVbits.DOZEN = 0;
//    CLKDIVbits.RCDIV = 0b000;
//    CLKDIVbits.CPDIV = 0b00;
//    CLKDIVbits.PLLEN = 1;
//    
//    /////////Secuencia Cambio de Oscilador/////////
//    //    OSCCONH = 0x78;
//    //    OSCCONH = 0x9A;
//    //    OSCCONbits.NOSC = 0b001;
//    //    OSCCONL = 0x46;
//    //    OSCCONL = 0x57;
//    //    OSCCONbits.OSWEN = 1;
//    //    __delay_ms(500);
//    //    while(OSCCONbits.OSWEN);
//    //////////////////////////////////////////////
//}