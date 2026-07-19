 void GSM_INIT(void)
{
   UART1_OUT_STR("AT\r\n");
   delay_ms(100);
   
   UART1_OUT_STR("AT+CMGF=1\r\n");
   delay_ms(100);
   
   UART1_OUT_STR("AT+CNMI=2,2,0,0,0\r\n");
   delay_ms(100);
   
}

void GSM_SEND_START(void)
{
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
delay_ms(1000);
}

void GSM_SEND_END(void)
{
    delay_ms(100);

    UART1_OUT_INT(0x1A);
    delay_ms(1000);
}

void GSM_SEND_SMS(void)
{
    UART1_OUT_STR("AT+CMGS=\"+916369935060\"\r\n");
    delay_ms(300);
    UART1_OUT_STR("HOME AUTOMATION ENABLED");
    delay_ms(300);
    UART1_TX(0x1A);

}
