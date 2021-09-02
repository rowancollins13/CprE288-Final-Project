/*
 * adc.c
 *
 *  Created on: Mar 19, 2021
 *      Author: jgortiz
 */
#include "adc.h"
#include "lcd.h"
#include "Timer.h"
#include "resetSimulation.h"
#include<math.h>

/*
 * Responsible for initialization of the ADC
 */
void ADC0_InitSWTriggerSeq3_Ch10(void){
    SYSCTL_RCGCADC_R |= 0x0001;   // 1) activate ADC0
    SYSCTL_RCGCGPIO_R |= 0x02;    // 2) activate clock for Port B
    while((SYSCTL_PRGPIO_R&0x02) != 0x02){};  // 3 for stabilization
   // GPIO_PORTB_DIR_R &= ~0x10;    // 4) make PE4 input
    GPIO_PORTB_AFSEL_R |= 0x10;   // 5) enable alternate function on PE4
    GPIO_PORTB_DEN_R &= ~0x10;    // 6) disable digital I/O on PE4
    GPIO_PORTB_AMSEL_R |= 0x10;   // 7) enable analog functionality on PE4
//    ADC0_PC_R &= ~0xF;
//    ADC0_PC_R |= 0x1;             // 8) configure for 125K samples/sec
//    ADC0_SSPRI_R = 0x0123;        // 9) Sequencer 3 is highest priority
    ADC0_ACTSS_R &= ~0x0001;      // 10) disable sample sequencer 3
    ADC0_EMUX_R &= ~0xF000;       // 11) seq3 is software trigger
   // ADC0_SSMUX3_R &= ~0x000F;
    ADC0_SSMUX0_R = 0xA;           // 12) set channel
    ADC0_SSCTL0_R |= 0x0006;       // 13) no TS0 D0, yes IE0 END0
    //ADC0_IM_R &= ~0x0001;         // 14) disable SS3 interrupts
    ADC0_ACTSS_R |= 0x0001;       // 15) enable sample sequencer 3
}

/*
 * Responsible for returning the value of the IR sensor
 */
uint32_t ADC0_InSeq3(void){
    uint32_t result;
    ADC0_PSSI_R = 0x0001; // 1) initiate SS3
    while((ADC0_RIS_R&0x01)==0){}; // 2) wait for conversion done
    result = (int) ADC0_SSFIFO0_R; // 3) read result
    //ADC0_ISC_R = 0x0008; // 4) acknowledge completion
    return result;
}
