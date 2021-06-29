//#define BOTON2 GPIOB_IDR.B5 //Entrada externa PB5
//#define BOTON GPIOC_IDR.B13 //Bot?n de usuario (PC13 pin 23 del CN7)
//#define LED   GPIOA_ODR.B5   //Led de usuario (PA5 pin 11 del CN10)
//#define BOTONActiveA1 GPIOB_IDR.B6
#define BOTONA GPIOA_IDR.B12
#define BOTONB GPIOB_IDR.B12
#define BOTONC GPIOC_IDR.B12

#define LA1 GPIOA_ODR.B0
#define LA2 GPIOA_ODR.B1
#define LA3 GPIOA_ODR.B2
#define LA4 GPIOA_ODR.B3
#define LA5 GPIOA_ODR.B4
#define LA6 GPIOA_ODR.B5
#define LA7 GPIOA_ODR.B6
#define LA8 GPIOA_ODR.B7
#define LA9 GPIOA_ODR.B8
#define LA10 GPIOA_ODR.B9
#define LA11 GPIOA_ODR.B10
#define LB1 GPIOB_ODR.B0
#define LB2 GPIOB_ODR.B1
#define LB3 GPIOB_ODR.B2
#define LB4 GPIOB_ODR.B3
#define LB5 GPIOB_ODR.B4
#define LB6 GPIOB_ODR.B5
#define LB7 GPIOB_ODR.B6
#define LB8 GPIOB_ODR.B7
#define LB9 GPIOB_ODR.B8
#define LB10 GPIOB_ODR.B9
#define LB11 GPIOB_ODR.B10
#define LC1 GPIOC_ODR.B0
#define LC2 GPIOC_ODR.B1
#define LC3 GPIOC_ODR.B2
#define LC4 GPIOC_ODR.B3
#define LC5 GPIOC_ODR.B4
#define LC6 GPIOC_ODR.B5
#define LC7 GPIOC_ODR.B6
#define LC8 GPIOC_ODR.B7
#define LC9 GPIOC_ODR.B8
#define LC10 GPIOC_ODR.B9
#define LC11 GPIOC_ODR.B10

//PROTOTIPOS  DE LAS FUNCIONES
void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
     Proceso();
}
void Conf_maq()
{
     GPIO_Digital_Input(&GPIOA_BASE,_GPIO_PINMASK_12);
     GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_12);
     GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_12);
   //GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_13);    //Entrada externa usando el bot?n de usuario (PC13)
                                                      //(Entrada normalmente en alto y el bot?n se activa en bajo)

   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_5);   //Entrada externa flotante usando un push button en el pin PB5
                                        //(Si es flotante se puede poner como entrada normalmente en bajo (0V) y con el bot?n se activa en
                                        //3.3V. El usuario coloca una resistencia de 1 K ? a tierra.
                                        //Tambi?n si es flotante se puede poner como entrada normalmente en alto (3.3 V) y con el bot?n se
                                        //activa en bajo (0V). El usuario coloca una resistencia de 1 K ? a 3.3V.)
   //GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_6);
   //GPIO_Config(&GPIOB_BASE,
   //           _GPIO_PINMASK_5,
   //           _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_UP);  //Entrada con Pull-up usando el pin PB5 como bot?n
                                                        //(Entrada normalmente en alto y el bot?n se activa en bajo)
   //GPIO_Config(&GPIOB_BASE,
   //           _GPIO_PINMASK_5,
   //           _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN);  //Entrada con Pull-down usando el pin PB5 como bot?n
                                                                                       //(Entrada normalmente en bajo y el bot?n se activa en 3.3V)

    //GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5);    //Salida con push pull por (default)
    GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7|_GPIO_PINMASK_8|_GPIO_PINMASK_9|_GPIO_PINMASK_10);
    GPIO_Digital_Output(&GPIOB_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7|_GPIO_PINMASK_8|_GPIO_PINMASK_9|_GPIO_PINMASK_10);
    GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7|_GPIO_PINMASK_8|_GPIO_PINMASK_9|_GPIO_PINMASK_10);
    //GPIO_Config(&GPIOA_BASE,
    //        _GPIO_PINMASK_, _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_MAX | _GPIO_CFG_OTYPE_PP);
}

void Ini_var()
{
     LA1 = 1;
     LA2 = 1;
     LA3 = 1;
     LA4 = 1;
     LA5 = 1;
     LA6 = 1;
     LA7 = 1;
     LA8 = 1;
     LA9 = 1;
     LA10 = 1;
     LA11 = 1;

     LB1 = 1;
     LB2 = 1;
     LB3 = 1;
     LB4 = 1;
     LB5 = 1;
     LB6 = 1;
     LB7 = 1;
     LB8 = 1;
     LB9 = 1;
     LB10 = 1;
     LB11 = 1;

     LC1 = 1;
     LC2 = 1;
     LC3 = 1;
     LC4 = 1;
     LC5 = 1;
     LC6 = 1;
     LC7 = 1;
     LC8 = 1;
     LC9 = 1;
     LC10 = 1;
     LC11 = 1;
}
void Proceso()
{
     /*if(BOTON==0) //se activa en 0
     {
           //LED=~LED;
           //Delay_ms(100); //Delay_us(250);
     }

     if(BOTON==1){    //porque es como si siemmpre estuviera en 1. Pull up con resistencia a vcc
                  LED=~LED;
                  Delay_ms(100);
     }

     /*if(BOTON2 == 0){
             LED=~LED;
             Delay_ms(200);
     } */

     /*if(BOTONActiveA1 == 1){ //resistencia a tierra es pull down es como si siempre estuviera en 0 y se activa con 1
             LED=~LED;
             Delay_ms(200);
     }*/

     if(BOTONA == 1){
               LA1 = ~LA1;
               Delay_ms(100);
               LA11 = ~LA11;
               Delay_ms(100);
               LA6 = ~LA6;
               Delay_ms(100);
               LA5 = ~LA5;
               Delay_ms(100);
               LA7 = ~LA7;
               Delay_ms(100);
               LA2 = ~LA2;
               Delay_ms(100);
               LA10 = ~LA10;
               Delay_ms(100);
               LA4 = ~LA4;
               Delay_ms(100);
               LA9 = ~LA9;
               Delay_ms(100);
               LA3 = ~LA3;
               Delay_ms(100);
               LA8 = ~LA8;
               Delay_ms(100);
     }

     if(BOTONB == 1){
               LB1 = ~LB1;
               Delay_ms(100);
               LB2 = ~LB2;
               Delay_ms(100);
               LB11 = ~LB11;
               Delay_ms(100);
               LB10 = ~LB10;
               Delay_ms(100);
               LB3 = ~LB3;
               Delay_ms(100);
               LB4 = ~LB4;
               Delay_ms(100);
               LB9 = ~LB9;
               Delay_ms(100);
               LB8 = ~LB8;
               Delay_ms(100);
               LB5 = ~LB5;
               Delay_ms(100);
               LB6 = ~LB6;
               Delay_ms(100);
               LB7 = ~LB7;
               Delay_ms(100);
     }

     if(BOTONC == 1){
               LC1 = ~LC1;
               Delay_ms(100);
               LC2 = ~LC2;
               Delay_ms(100);
               LC3 = ~LC3;
               Delay_ms(100);
               LC4 = ~LC4;
               Delay_ms(100);
               LC5 = ~LC5;
               Delay_ms(100);
               LC6 = ~LC6;
               Delay_ms(100);
               LC7 = ~LC7;
               Delay_ms(100);
               LC8 = ~LC8;
               Delay_ms(100);
               LC9 = ~LC9;
               Delay_ms(100);
               LC10 = ~LC10;
               Delay_ms(100);
               LC11 = ~LC11;
               Delay_ms(100);
     }

}