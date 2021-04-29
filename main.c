#include "msp430.h"
#include "funciones_inicio.h"
#include "LCD.h"
#include "variables.h"
#include "funciones_programa.h"

unsigned int i = 0;         //Creamos la variable contador

void main(void){
    WDTCTL = WDTPW + WDTHOLD;
    Init_Ptos();
    LCD_Init();


    Imprime_cadena("Pantalla");
    Comando_LCD(0xC0);
    Imprime_cadena("Ok");
    Comando_LCD(0x01);

    for(;;){

        //secuencia_leds_1(1);
        Imprime_cadena("  UaRT");
        Comando_LCD(0xC0);
        Imprime_cadena("Comunicando ... ");

        if (!(P2IN&BIT1)){      //Se detecta el primer bit

            if(i<7){            //Comprueba que no se ha llegado al final de la cuneta en 8
                if(P2IN&BIT1){  //detecta un alto
                    enciendeLed();      //prende un led
                    i=i+1;              //suma el contador
                    Comando_LCD(0xC0);  //se imprime en pantalla la cuenta
                    Imprime_numero(i);
                }else{
                    apagaLed()          //Si hay un bajo, se apaga el led y no suma la cuenta
                }

            }else{                      //Si se llego a la cuenta en 7 se regresa a uno el contador
                i==0;

            }

        }
    }



}
