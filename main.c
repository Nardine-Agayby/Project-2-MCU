/*
 * File:   newavr-main.c
 * Author: nagay
 *
 * Created on May 18, 2020, 10:26 PM
 */


#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "mSPI.h"
#include "BoardConfig.h"
#include "DIO.h"


int main(void) {
    
    SPI_Slave_init( _SPI_X, SCK_Freq_4  );
    unsigned char data = 0;
    
    PINCas(LED1,OUT);
    PINDas(LED2,OUT);
    PINAas(CheckLED,OUT);
    
    resetPIN(LED1,portC);
    resetPIN(LED2,portD);

    setPIN(CheckLED,portA);  //LED to check power connection
    
    while (1) {
        data = SPI_read();
        
        if(data == 0x01)
        {
            setPIN(LED1,portC);  
        }
        else if(data == 0x02)
        {
            resetPIN(LED1,portC);
        }
        
        if(data == 0x03)
        {
            setPIN(LED2,portD);
        }
        else if(data == 0x04)
        {
            resetPIN(LED2,portD);
        }
                
    }
}
