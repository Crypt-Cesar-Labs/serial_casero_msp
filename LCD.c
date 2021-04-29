#include  <msp430.h>

#define BUSFREQ 275    /* para obtener 1 mS con 1.1 Mhz */ 

        
#define fintabla 0x096
#define ELCD_xor (4)  // ref
#define E_LCD  (4)           /*   Enable P4.4 */
#define RS_LCD (5)           /*   RS     P4.5 */

const unsigned char t[]={0x03,0x03,0x02,0x02,0x0C,0x00,0x0C,0x00,0x01,0x00,0x06,fintabla};
// const asigna la variable tipo arreglo en un segmento de flash  
extern unsigned  char bandera;
unsigned char band_exhopr;


void Wait1ms(void){
  unsigned int i;
  i = BUSFREQ ;      /* DCO=1.1mHZ / 4 ciclos / 275 = 1Khz = 1mSeg */
  do (i--);      /* 4 ciclos de maquina efectivos en ensamblador */
  while (i != 0);	
 
}


void WaitNms(int n){
/* This function waits for N ms. */   
  do {n--;
       Wait1ms(); }   /* 4 ciclos de maquina efectivos en ensamblador */
  while (n != 0);	
}



 void Toggle(void){        
/* This function toggles the E line (LCD). */ 
   P4OUT ^=(1<<ELCD_xor);   /* (xor.b #0x20)=0 */
   WaitNms(2);
   P4OUT ^=(1<<ELCD_xor);   /* (xor.b #0x20)=1 */
  
}



void MergePTO(unsigned char dato){
  static unsigned char respt4;
  
   dato &=0x0F;
   respt4 =P4OUT & 0xF0;
   P4OUT = respt4 | dato;
   Toggle();
 
}



void LCD_Init(void)
{ 
/* Inicialización LCD */
	 unsigned char position=0;
	 
	 P4OUT &=~(1<<RS_LCD); /* RS =0 escribe comando */
	 WaitNms(15);
	 
	 while (t[position]!=fintabla)
	    {
         MergePTO(t[position]);  /* Función de asignar dato al nibble menos significativo del PTC */   
         Wait1ms();
         position++;
   		}
         WaitNms(15);  
    
}



void Imprime_cadena(char *str){
/* Funcion de impresion de cadena en forma de String */
   char *strptr;
      
   strptr = str; 
   P4OUT  |=(1<<RS_LCD); /* RS = 1 ESCRIBIR DATO */
   while ((*strptr) != '\0'){
       MergePTO((*strptr) >> 4); /* Escritura parte alta ASCII */
       MergePTO(*strptr);        /* Escritura parte baja ASCII */
       Wait1ms();
       strptr++;
   
   }   
} 



Imprime_numero(unsigned int numero){

  unsigned char unidades;
  unsigned char decenas;
  unsigned char centenas;
  unsigned char unidades_millar;
  unsigned char decenas_millar;
  

  decenas_millar= (numero%100000)/10000;
  unidades_millar= (numero%10000)/1000;
  centenas =  (numero%1000)/100;
  decenas =  (numero%100)/10;
  unidades = (numero%10);
 
  
  P4OUT |= (1<<RS_LCD) ; /* RS = 1 ESCRIBIR DATO */

  if(bandera&BIT1){
  bandera&=~BIT1;

  MergePTO(0x0B);
  MergePTO(0x00);
  Wait1ms();
  }

  if(bandera&BIT2){
  bandera&=~BIT2;

  MergePTO(0x03); /*Decenas de millar DDRAM */
  MergePTO(decenas_millar);
  Wait1ms();
  }


  if(bandera&BIT3){
  bandera&=~BIT3;

  MergePTO(0x03); /*Unidades de millar DDRAM */
  MergePTO(unidades_millar);
  Wait1ms();
  }


  if(bandera&BIT4){
  bandera&=~BIT4;

  MergePTO(0x03); /*Centenas DDRAM */
  MergePTO(centenas);
  Wait1ms(); 
  }

  if(bandera&BIT5){
  bandera&=~BIT5;

  MergePTO(0x02);  // imprime punto decimal
  MergePTO(0x0E);
  Wait1ms();
  }


  if(bandera&BIT6){
  bandera&=~BIT6;

  MergePTO(0x03); /*Decenas DDRAM */
  MergePTO(decenas);
  Wait1ms();
  }
  
  if(bandera&BIT7){
  bandera&=~BIT7;
  
  MergePTO(0x03); /*Unidades DDRAM */
  MergePTO(unidades);
  Wait1ms();
  }
}



void Comando_LCD(unsigned char var_comando){
  
       P4OUT &=~(1<<RS_LCD); /* RS = 0 ESCRIBIR comando */
       MergePTO((var_comando) >> 4);   /* desplaza a la derecha 4 envia parte alta a la baja */
       MergePTO(var_comando);	 /* envía parte baja */
       Wait1ms(); 
}

