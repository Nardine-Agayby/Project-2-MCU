
#include <xc.h>
#include <stdlib.h>
//#include "mUART.h"
char newLine[] = "\t\r";


/*missing clk polarity */
void UART_init(char T_R_Mode, char T_R_State, char Parity_Bit ,char Stop_Bits ,char Char_Size )
{
    UBRRL = 103;  //Baud Rate Registers at baud rate =9600bps  //calculated or from table
    
    if(T_R_State == 10)
    {
        UCSRB |= (1 << TXEN) | (1 << RXEN);// Enable Transmitter AND receiver
    }else
    {
        UCSRB |= (1 << T_R_State); // Enable Transmitter OR receiver
    }
    
    UCSRC |= (1<<URSEL)| (Parity_Bit << 4) | (T_R_Mode << 6)  | (Stop_Bits << 3)  | (Char_Size << 1)  ; 
    
//  UCSRB |= (1 << UDRIE);        // Enable UDRE Interrupt  //use only with USART_UDRE_vect
    UCSRB |= (1 << RXCIE);        // RX Complete Interrupt Enable

}

/*ISR(USART_UDRE_vect) 
{
    UDR = 'A'; // Transmit Data
}*/

/*UART Transmitting*/
void UART_TransmitChar(char data)
{
    /*Pooling*/
    while(!(UCSRA & (1 << UDRE))); //wait loop till DDR is Empty//USART Data Register Empty Flag //default 1
    UDR = data;  
}

void UART_TransmitString(char *data)
{
    for(int i=0 ; data[i] !='\0' ; i++)
    {
        UART_TransmitChar(data[i]);
    }
}

void UART_TransmitValue(int Val)
{
    char buffer[20];
    itoa(Val,buffer,10);
    UART_TransmitString( buffer );
}

void UART_NewLine()
{
    UART_TransmitString( newLine );
}

/*USART receive*/
/*
 ISR(USART_RXC_vect)
{
    char Rec = UDR;
    if ((Rec == 'O') | (Rec == 'o') )
    {
        PORTA |= (1 << LED); //LED ON
    }
    if ((Rec == 'C') | (Rec == 'c') )
    {
        PORTA &= ~(1 << LED); //LED ON
    }
    else{}
}*/


