
void Init_Ptos (void){

    /////////LCD////////////
    P4OUT =   0x10;//Ini_outP4;
    P4DIR =   0x3F;//Ini_dirP4;

    ///SALIDAS PARA LOS LEDS////
    P1DIR = 0xFF;
    P1OUT = 0x00;

    //CONFIGURANDO EL PUERTO 2 COMO SALIDA//////
    P2DIR = 0x00;
    P2OUT = 0x01;       //Salidas en alto
    P2REN = 0x01;        //Se asigna el pull up


}
