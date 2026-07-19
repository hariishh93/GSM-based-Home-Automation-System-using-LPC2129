#include<LPC21xx.h>

#define LCD 0xff
#define RS 1<<11
#define E 1<<10

void LCD_INIT(void);
void LCD_COMMAND(unsigned int);
void LCD_DATA(unsigned int);
void LCD_STR(unsigned char*);
void LCD_INT(unsigned int);
void delay_ms(unsigned int);

void LCD_INIT()
{
//PINSEL0 |= 0x00;
IODIR0 |= LCD|RS|E;

LCD_COMMAND(0x01);
LCD_COMMAND(0x02);
LCD_COMMAND(0x0c);
LCD_COMMAND(0x38);
}

void LCD_COMMAND(unsigned int val)
{
IOCLR0 = LCD;
IOSET0 = val;
IOCLR0 = RS;
IOSET0 = E;
delay_ms(2);
  IOCLR0 = E;
}

void LCD_DATA(unsigned int data)
{
IOCLR0 = LCD;

IOSET0 = data;
IOSET0 = RS;
IOSET0 = E;
delay_ms(2);
  IOCLR0 = E;

}

void LCD_STR(unsigned char* s)
{
while(*s)
{
LCD_DATA(*s++);
}

}

/*void LCD_INT(unsigned int p)
{
unsigned int i,arr[5];

for(i=0;p;i++)
{
arr[i]=p%10;
p=p/10;

}

while(i--)
LCD_DATA(arr[i]+48);

}*/

void delay_ms(unsigned int v)
{
unsigned int i=0;
for(;v>0;v--)
for(i= 12000;i>0;i--);

}
