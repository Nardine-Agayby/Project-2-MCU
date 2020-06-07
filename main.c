/*
 * File:   main.c
 * Author: nagay
 *
 * Created on May 18, 2020, 10:47 PM
 */


#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <avr/io.h>
//#include <util/delay.h>
#include "lcd.h"
#include "mSPI.h"
#include "mUART.h"

char LED1[]="1st LED ";
char LED2[]="2nd LED ";
char ON[]="ON";
char OFF[]="OFF";
char cl[] = "       ";

ISR(USART_RXC_vect)
{
    char LEDcontrol = UDR;  //value received from Bluetooth
    SPI_write(LEDcontrol); 
    
    if(LEDcontrol == 0x01)
        {
            LCD_String_xy(0, 10, cl); //clear state 
            LCD_String_xy(0, 10, ON);
        }
        else if(LEDcontrol == 0x02)
        {
            LCD_String_xy(0, 10, cl); //clear state 
            LCD_String_xy(0, 10, OFF);
        }
    if(LEDcontrol == 0x03)
        {
            LCD_String_xy(1, 10, cl); //clear state 
            LCD_String_xy(1, 10, ON);
        }
        else if(LEDcontrol == 0x04)
        {
            LCD_String_xy(1, 10, cl); //clear state 
            LCD_String_xy(1, 10, OFF);
        }
    _delay_ms(200);
}

int main(void) {

    LCD_Init ();
    LCD_String_xy(0, 0, LED1);
    LCD_String_xy(0, 10, OFF);
    LCD_String_xy(1, 0, LED2);
    LCD_String_xy(1, 10, OFF);
    
    UART_init( _Asynch  ,_Receive, Parity_Dis , Stop_1b , Char_8  ); // Enable Receiver ONLY
    SPI_Master_init( _SPI_X, SCK_Freq_4  );  //send data via SPI
    sei();
    
    while (1) {  
    }
}




