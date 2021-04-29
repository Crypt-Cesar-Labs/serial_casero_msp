/////////////FUNCION DELAY/////////////
void Ciclo1ms(void)
{
    __delay_cycles(16000);
}

void DelayNms (int n)
{
    do
    {
        n--;
        Ciclo1ms();
    }
    while (n != 0);
}

////////SECUENCIA DE LEDS///////////////
void secuencia_leds_1 (int setTime){

    P1OUT |= LED0;
    DelayNms(setTime);
    P1OUT &=~ LED0;
    DelayNms(setTime);
    P1OUT |= LED1;
    DelayNms(setTime);
    P1OUT &=~ LED1;
    DelayNms(setTime);
    P1OUT |= LED2;
    DelayNms(setTime);
    P1OUT &=~ LED2;
    DelayNms(setTime);
    P1OUT |= LED3;
    DelayNms(setTime);
    P1OUT &=~ LED3;
    DelayNms(setTime);
    P1OUT |= LED4;
    DelayNms(setTime);
    P1OUT &=~ LED4;
    DelayNms(setTime);
    P1OUT |= LED5;
    DelayNms(setTime);
    P1OUT &=~ LED5;
    DelayNms(setTime);
    P1OUT |= LED6;
    DelayNms(setTime);
    P1OUT &=~ LED6;
    DelayNms(setTime);
    P1OUT |= LED7;
    DelayNms(setTime);
    P1OUT &=~ LED7;
    DelayNms(setTime);

}


/////ENCIENDE LED 0
void enciendeLed(void){
    P1OUT |= LED0;
    DelayNms(2);
}

//APAGA LED 0
void apagaLed(void){
    P1OUT &=~ LED0;
    DelayNms(2);
}
