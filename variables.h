#define LED0  0x01;
#define LED1  0x02;
#define LED2  0x04;
#define LED3  0x08;
#define LED4  0x10;
#define LED5  0x20;
#define LED6  0x40;
#define LED7  0x80;


/////PUERTOS LCD//////////////////////////
                            /* P4.5   P4.4   P4.3   P4.2   P4.1    P4.0         */
#define Ini_dirP4   0x3F;  /*   1      1      1      1      1       1           */
                            /* RS      E     DB7    DB6    DB5     DB4       LCD*/
#define Ini_outP4   0x10 ; /*   0      1      0      0      0       0           */
