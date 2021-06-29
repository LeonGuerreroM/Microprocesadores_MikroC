#define BOTON GPIOC_IDR.B8
#define DISPLAYA GPIOA_ODR
#define DISPLAYB GPIOB_ODR
#define DISPLAYC GPIOC_ODR
#define CERO 0XC0
#define UNO 0XF9
#define DOS 0XA4
#define TRES 0XB0
#define CUATRO 0X99
#define CINCO 0X92
#define SEIS 0X82
#define SIETE 0XF8
#define OCHO 0X80
#define NUEVE 0X90
#define LED GPIOA_ODR.B10

/*#define CARA 0X88
#define CARB 0X83
#define CARC 0XA7
#define CARD 0XA1
#define CARE 0X86
#define CARF 0X8E
#define CARP 0X8C
#define CARR 0XAF
#define CART 0X87
#define CARI 0XF9
#define CAR 0XFF
#define SEGa 0XFE
#define SEGb 0XFD
#define SEGc 0XFB
#define SEGd 0XF7
#define SEGe 0XEF
#define SEGf 0XDF
#define SEGg 0XBF*/

//Declara variables globales
//const unsigned short int segmentos[]={CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE, OCHO,NUEVE,CARA,CARB,CARC,CARD,CARE,CARF, CARP,CARR,CARA,CARC,CART,CARI,CARC,CARA,DOS };
const unsigned short int segmentos[]={CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,OCHO,NUEVE};
unsigned short int contador_minutos=0, contador_segundos_1=0, contador_segundos_dos=0;
unsigned int contador = 0;
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
  Conf_maq();
  Ini_var();
  while(1) //Bucle principal
  Proceso();
}

void Conf_maq() {
   GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_8); //Entrada flotante usando el botón de usuario (PB8)
                                                   //(ConfiguraR como PULL-UP Entrada normalmente en alto y el botón se activa en bajo)
   GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 , _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);
   GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 , _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);
   GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 , _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);

   GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_10);
}

void Ini_var() {
  contador=0;
  LED = 1;
  DISPLAYC = segmentos[0];
  DISPLAYB = segmentos[0];
  DISPLAYA = segmentos[0];
}

void Proceso() {
     if (BOTON==0) //Verifica si se oprime el boton
     {
       //DISPLAY = segmentos[contador];
       //if(++contador==25) //Para mostrar 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, P,r,A,c,t,I,c,A,2
       //{
        //contador=0;
       //}
       //delay_ms(250);

       if(contador_segundos_dos == 10){
          contador_segundos_dos = 0;
          contador_segundos_1++;
          if(contador_segundos_1 == 6){
              contador_segundos_1 = 0;
              contador_minutos++;
              if(contador_minutos == 10){
                contador_minutos = 0;
              }
              DISPLAYA = segmentos[contador_minutos];
          }
          DISPLAYB = segmentos[contador_segundos_1];
       }
       
       DISPLAYC = segmentos[contador_segundos_dos];
       
       contador_segundos_dos++;
       LED = ~LED;
       delay_ms(100);

     }
}