#include <xc.h>
#include "mSPI.h"
#include <string.h>

unsigned char data; //casting since data is signed

void SPI_Master_init(char _SPI_Speed, char SCK_Freq)
{

    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    /*MUST set clk 1st then enable last*/
    SPCR |= (SCK_Freq << 0); //clk select
    SPSR |= (_SPI_Speed << 0);//clk speed 

    
    SPCR |= (_Master << MSTR);

    SPCR |= (1 << SPE); //| (1 << SPIE);   //SPI Enable //SPI Interrupt Enable
}

void SPI_Slave_init(char _SPI_Speed, char SCK_Freq)
{

    DDRB |= (1 << MISO);
    SPCR |= (SCK_Freq << 0); //clk select
    SPSR |= (_SPI_Speed << 0);//clk speed 
    
    SPCR |= (1 << SPE); //| (1 << SPIE);   //SPI Enable //SPI Interrupt Enable
    //  SPCR |=  (_Slave<< MSTR);
 
}

void SPI_write(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF))); //Pooling //check flag is back to 1
}

/*
ISR(SPI_STC_vect)
{
    SPI_write('A');
}*/


char SPI_read()
{
    while(!(SPSR & (1 << SPIF)));
    data = SPDR; //signed value need casting 
    return data;
}

void SPI_readString(char *buffer)
{
    for(int i=0 ; i<20; i++)
    {
       buffer[i] = SPI_read(); // *(buffer + i) = SPI_read();
    }
}

int checkData(char * cmpStr)
{
    char buffer[20];
    SPI_readString(buffer);
    int flag = strcmp(buffer, cmpStr); 
    //if matched returns 1
    return flag == 0 ? 1 : 0;
}

/*SPI read protocol*/
/*
 * //sent data : "5Hello"
 void SPI_readString(char *buffer)
{
 * char data size =SPI_read();
 * dataSize -= 48; //minus ascii to get the number
    for(int i=0 ; i<dataSize; i++)
    {
       buffer[i] = SPI_read(); // *(buffer + i) = SPI_read();
    }
 * for(int i=0 ; (SPI_read() != 10) || (SPI_read() != 32) ; i++)//as long as not send enter or space with ascii
    {
       buffer[i] = SPI_read(); // *(buffer + i) = SPI_read();
    }
}*/