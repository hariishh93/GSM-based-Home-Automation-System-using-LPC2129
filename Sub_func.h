#define LED1 1<<18
#define LED2 1<<19
//#define EN 1<<21
#define INA 1<<22
#define INB 1<<23

void FAN_OFF(void)
{
IODIR0 |= 0xe00000;
//IOCLR0 = EN;
IOCLR0 = INA;
IOCLR0 = INB;
}

void FAN_ON(void)
{
IODIR0 |= 0xe00000;
//IOSET0 = EN;
IOSET0 = INA;
IOCLR0 = INB;
}  

void LIGHT1_OFF(void)
{
     IODIR0|= 0x40000;
IOSET0 = LED1;
}

void LIGHT1_ON(void)
{
     IODIR0|= 0x40000;
IOCLR0 = LED1;
}

void LIGHT2_OFF(void)
{
     IODIR0|= 0x80000;
IOSET0 = LED2;
}

void LIGHT2_ON(void)
{
     IODIR0|= 0x80000;
IOCLR0 = LED2;
}

void ALL_OFF()
{
    FAN_OFF();
LIGHT1_OFF();
LIGHT2_OFF();  
}

void ALL_ON()
{
    FAN_ON();
LIGHT1_ON();
LIGHT2_ON();  
}
