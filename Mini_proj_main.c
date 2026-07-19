#include<LPC21xx.h>
#include "LCD_driver.h"
#include "Sub_func.h"
#include "UART_driver.h"
#include "GSM_driver.h"

unsigned char in[20];
//unsigned char out[20];
//unsigned char flag=0;
//unsigned char ch[20];

int main(void)
{

   unsigned char arr[8][10] = {"FANOFF", "FANON", "LIGHT1OFF", "LIGHT1ON", "LIGHT2OFF", "LIGHT2ON", "ALLOFF", "ALLON"};
   unsigned char i=0, j=0, c=0;
   signed char k=0;
   unsigned char * str1;
   //unsigned char * str2;

	FAN_OFF();
	//IODIR0 |= 0xe00000;
	//IOCLR0 = (1<<22)|(1<<23);
   //IOCLR0 = INA;
   //IOCLR0 = INB;
   
   LCD_INIT();
   UART1_CONFIG();
   LCD_COMMAND(0x80);
   LCD_STR(" HOME AUTOMATE  ");
   LCD_COMMAND(0xC0);
   LCD_STR("     SYSTEM     ");
   
   UART1_CONFIG();
   delay_ms(2000);
   GSM_INIT();
   GSM_SEND_SMS();

   //FAN_OFF();
   
while(1)
{
while(in[k])
{
in[k] = '\0';
k++;
}
k=0;



do
{
 k=UART1_RX();
}while(k!='*');

k=-1;
do
{
k++;
if(k >= sizeof(in)-1) { k = 0; break; }
in[k] = UART1_RX();
}
while(in[k]!='#');

in[k] = '\0';

k=0;

while(1)
{
     while(in[k]==' ')
 {
      k++;
 }
     //if(arr[i][j]==(in[k]>='a'&&in[k]<='z')?in[k]-32:in[k])
//tst = in[k];
if(arr[i][j]==in[k])
//if(arr[i][j]==(in[k]>='a'&&in[k]<='z')?in[k]-32:in[k])
 {
     j++;
 k++;
 
 if(arr[i][j]=='\0'&&in[k]=='\0')
 {
 LCD_COMMAND(0x01);
 LCD_COMMAND(0x80);
     LCD_STR(in);
 c=1;
 }
 }
 else
 {
     i++;
 j=0;
k=0;
 }

if(i>7)
{
   i=0;
	   LCD_COMMAND(0x01);
	   LCD_COMMAND(0x80);
       LCD_STR("INVALID INPUT");
   str1 = "INVALID INPUT";
 while(*str1)
   UART1_TX(*str1++);
break;
}
 
 if(c==1)
{
 c=0;
 i++;
     break;
}
}


switch(i)
{
    case 1:
     FAN_OFF();
 //if(flag==1)
 
     //str2 = "FAN IS OFF";
   //GSM_SEND_START();
    GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("FAN IS OFF");
    delay_ms(300);
    UART1_TX(0x1A);
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
 
 break;
 
    case 2:
     FAN_ON();
	 GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("FAN IS ON");
    delay_ms(300);
    UART1_TX(0x1A);
 //if(flag==1)
     
     //str2 = "FAN IS ON";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
 
 break;
 
case 3:
     LIGHT1_OFF();
	 GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("LIGHT1 IS OFF");
    delay_ms(300);
    UART1_TX(0x1A);
 //if(flag==1)
 
     //str2 = "LIGHT1 IS OFF";
     //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
 
     break;
 
    case 4:
    LIGHT1_ON();
	GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("LIGHT1 IS ON");
    delay_ms(300);
    UART1_TX(0x1A);
//if(flag==1)
 
     //str2 = "LIGHT1 IS ON";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
 
break;

    case 5:
     LIGHT2_OFF();
	 GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("LIGHT2 IS OFF");
    delay_ms(300);
    UART1_TX(0x1A);
 //if(flag==1)
 
     //str2 = "LIGHT2 IS OFF";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
 
     break;
 
    case 6:
    LIGHT2_ON();
	GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("LIGHT2 IS ON");
    delay_ms(300);
    UART1_TX(0x1A);
//if(flag==1)

     //str2 = "LIGHT2 IS ON";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();

break;
 
    case 7:
    ALL_OFF();
	GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("ALL DEVICES ARE OFF");
    delay_ms(300);
    UART1_TX(0x1A);
//if(flag==1)

     //str2 = "ALL DEVICES ARE OFF";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();

break;

    case 8:
    ALL_ON();
	GSM_INIT();
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("ALL DEVICES ARE ON");
    delay_ms(300);
    UART1_TX(0x1A);
//if(flag==1)
     //str2 = "ALL DEVICES ARE ON";
   //GSM_SEND_START();
 //while(*str2)
     //UART1_TX(*str2++);
//GSM_SEND_END();
break;
}

i=0;
j=0;
k=0;

//delay_ms(3000);

//LCD_COMMAND(0x01);
//LCD_COMMAND(0x80);
//LCD_STR(" HOME AUTOMATE  ");
//LCD_COMMAND(0xC0);
//LCD_STR("     SYSTEM     ");

// UART1_RX();
}
}
