	  void UART1_CONFIG(void)
{
    PINSEL0 |= 0x50000;
 U1LCR = 0x83;
 U1DLL=97;
 U1LCR=0x03;
}

unsigned char UART1_RX(void)
{
   while ((U1LSR & 1)==0);
   return U1RBR;
}

void UART1_TX(unsigned char a)
{
//while((U0LSR&1<<5)==0);
while(((U1LSR>>5)&1)==0);
U1THR=a;
}

void UART1_OUT_STR(unsigned char* temp)
{
while(*temp)
     UART1_TX(*temp++);
}

void UART1_OUT_INT(unsigned char t)
{
UART1_TX(t);
}
