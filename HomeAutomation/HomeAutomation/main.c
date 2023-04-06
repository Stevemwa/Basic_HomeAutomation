/*
 * HomeAutomation.c
 *
 * Created: 06/04/2023 05:01:09
 * Author : Mwas
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/twi.h>
#include <util/delay.h>
#include "I2C.h"
#include "RTC_DS1307.h"
#include "LCD_4bit_PortA.h"

char Convert(unsigned short n);



int main(void)
{
    /* Replace with your application code */
	 I2C_Init();
    LCD_Init ();
    while (1) 
    {
		RTC_Read_Clock(0);
		LCD_Cmd(0x80);
		LCD_String(Convert(hour));
		LCD_String(":");
		LCD_String(Convert(minute));
		LCD_String(":");
		LCD_String(Convert(second));
		LCD_Cmd(0xC0);
		LCD_String("OPEN CURTAINS");
		_delay_ms(2000);
    }
}


char Convert(unsigned short n)
{
	static char bin[17];
	int k=0;

 unsigned char value;
 for(int i=0;i<=4;i++){
	 
	 value =(n &(00100001 << i));
	 if(value == 00000000){
		 k=k+0;
		 }else{
		 k=k +(pow(2,i));
	 }
 }
 itoa(k,bin,10);
 return(bin);
}

