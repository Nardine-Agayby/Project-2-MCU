/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DIO
#define	DIO

#define OUT  1
#define IN   0

#define portA  1
#define portB  2
#define portC  3
#define portD  4

//set specific pins in port as High 
void setPORTA(int data);
void setPORTB(int data);
void setPORTC(int data);
void setPORTD(int data);

//direction OUT ,IN
void PORTAas(int dir);
void PORTBas(int dir);
void PORTCas(int dir);
void PORTDas(int dir);

//set specific pin direction as output or input
void PINAas(int pinNum,int dir);
void PINBas(int pinNum,int dir);
void PINCas(int pinNum,int dir);
void PINDas(int pinNum,int dir);

//Returns status of input pin
int isPressedA(int pinNum);
int isPressedB(int pinNum);
int isPressedC(int pinNum);
int isPressedD(int pinNum);

//set o/p pin as HIGH 
void setPIN(int pinNum, char port);
//reset o/p pin to LOW
void resetPIN(int pinNum, char port);
//toggle status of pin from low to high and vise versa
void togglePIN(int pinNum, char port);


//set output port to HIGH or reset to LOW
void setPORT(char port);
void resetPORT(char port);
//toggle all port pins
void togglePORT(char port);


/*void setPINA(int pinNum);
void setPINB(int pinNum);
void setPINC(int pinNum);
void setPIND(int pinNum);
void _setPIN(int pinNum);
void _resetPIN(int pinNum);*/

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

