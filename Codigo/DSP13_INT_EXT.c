#define BOTON GPIOA_IDR.B1
#define BTNConfig   GPIOB_IDR.B2
#define BTNMovement  GPIOB_IDR.B5

sbit LCD_RS at GPIOC_ODR.B0;
sbit LCD_EN at GPIOC_ODR.B1;
sbit LCD_D4 at GPIOC_ODR.B2;
sbit LCD_D5 at GPIOC_ODR.B3;
sbit LCD_D6 at GPIOC_ODR.B4;
sbit LCD_D7 at GPIOC_ODR.B5;

/*char txt1[]    = "Mora Guerrero Leon Sergio";
char limpiar[] = "                         ";

void Vsync_Int() iv IVT_INT_EXTI2 ics ICS_AUTO {
  EXTI_PR.B2 = 1;       // clear flag
  Lcd_Out(1,1,txt1);
  delay_ms(6000);
  Lcd_Out(1,1,limpiar);
}

void main() {
  GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5);
  GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_2);
  
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  //Setup_Interrupt();

  RCC_APB2ENR|=1<<AFIOEN;
  AFIO_EXTICR1   |= 0x00000100;          // Map external interrupt on PB13,
  EXTI_RTSR          |= 0x00000000;        // Set interrupt on Rising edge
  EXTI_FTSR          |= 0x00000004;        // Set Interrupt on Falling edge
  EXTI_IMR            |= 0x00000004;        // Set mask
  NVIC_IntEnable(IVT_INT_EXTI2);   // Enable External interrupt
  EnableInterrupts();
}     */

char txt1[] = "Mora Guerrero Leon Sergio";
char limpiar[] = "                         ";
char txt2[] = "2021,04,26,Mexico        ";
char puntos[] = ":";
char segundosT[7];
char minutosT[7];
char horasT[7];
char segundosTImpresion[7];
char minutosTImpresion[7];
char horasTImpresion[7];
int segundos = 0;
int minutos = 0;
int horas = 0;
int modoConfig = 0;

void Config();
void segundosP();
void minutosP();
void horasP();

void main() {
     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(2,3,puntos);
     Lcd_Out(2,6,puntos);
     IntToStrWithZeros(minutos, minutosT);
     memcpy(minutosTImpresion,minutosT+4,2);
     Lcd_Out(2,4,minutosTImpresion);
     IntToStrWithZeros(horas, horasT);
     memcpy(horasTImpresion,horasT+4,2);
     Lcd_Out(2,1,horasTImpresion);
     Config();
     
     RCC_APB2ENR|=1<<AFIOEN;
     AFIO_EXTICR1   |= 0x00000100;          // Map external interrupt on PB13,
     EXTI_RTSR          |= 0x00000000;        // Set interrupt on Rising edge
     EXTI_FTSR          |= 0x00000004;        // Set Interrupt on Falling edge
     EXTI_IMR            |= 0x00000004;        // Set mask
     NVIC_IntEnable(IVT_INT_EXTI2);   // Enable External interrupt
     EnableInterrupts();
     
     AFIO_EXTICR1   |= 0x00000100;          // Map external interrupt on PB13,
     EXTI_RTSR          |= 0x00000000;        // Set interrupt on Rising edge
     EXTI_FTSR          |= 0x00000004;        // Set Interrupt on Falling edge
     EXTI_IMR            |= 0x00000004;        // Set mask
     NVIC_IntEnable(IVT_INT_EXTI2);   // Enable External interrupt
     EnableInterrupts();
}



void Config(){
     GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5);
     GPIO_Digital_Input(&GPIOA_BASE,_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3);
     //GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7);

     RCC_APB2ENR|=1<<IOPCEN;
     RCC_APB2ENR|=1<<IOPAEN;

     RCC_APB2ENRbits.TIM1EN=1;
     TIM1_CR1.CEN=0;
     TIM1_PSC=7999;
     //TIM1_ARR=1000;
     TIM1_ARR=200;
     TIM1_DIER.UIE=1;
     NVIC_IntEnable(IVT_INT_TIM1_UP);
     TIM1_CR1.CEN=1;
     EnableInterrupts();
}

void segundosP() iv IVT_INT_TIM1_UP ics ICS_AUTO{
   if(modoConfig == 0){
     TIM1_SRbits.UIF=0;
     IntToStrWithZeros(horas, horasT);
     memcpy(horasTImpresion,horasT+4,2);
     Lcd_Out(2,1,horasTImpresion);
     IntToStrWithZeros(minutos, minutosT);
     memcpy(minutosTImpresion,minutosT+4,2);
     Lcd_Out(2,4,minutosTImpresion);
     IntToStrWithZeros(segundos, segundosT);
     memcpy(segundosTImpresion,segundosT+4,2);
     Lcd_Out(2,7,segundosTImpresion);
     segundos++;
     if(segundos>59){
        segundos = 0;
        minutos++;
     }
     if(minutos>59){
        minutos = 0;
        horas++;
     }

     if(BOTON == 0){
        Lcd_Out(1,1,txt1);
     }else if(BOTON == 1){
        Lcd_Out(1,1,txt2);
     }

     if(BTNConfig == 1)
     modoConfig = 1;

     if(modoConfig == 1){
                   horas = 0;
                   minutos = 0;
                   segundos = 0;
                   IntToStrWithZeros(horas, horasT);
                   memcpy(horasTImpresion,horasT+4,2);
                   Lcd_Out(2,1,horasTImpresion);
                   IntToStrWithZeros(minutos, minutosT);
                   memcpy(minutosTImpresion,minutosT+4,2);
                   Lcd_Out(2,4,minutosTImpresion);
                   IntToStrWithZeros(segundos, segundosT);
                   memcpy(segundosTImpresion,segundosT+4,2);
                   Lcd_Out(2,7,segundosTImpresion);
     }

   }else if(modoConfig == 1){
         if(BTNMovement == 1){
                        horas++;
                        IntToStrWithZeros(horas, horasT);
                        memcpy(horasTImpresion,horasT+4,2);
                        Lcd_Out(2,1,horasTImpresion);
         }

         if(BTNConfig == 1){
                      modoConfig = 2;
         }
   }else if(modoConfig == 2){
        if(BTNMovement == 1){
                        minutos++;
                        IntToStrWithZeros(minutos, minutosT);
                        memcpy(minutosTImpresion,minutosT+4,2);
                        Lcd_Out(2,4,minutosTImpresion);
         }

         if(BTNConfig == 1){
                      modoConfig = 3;
         }
   }else if(modoConfig == 3){
        if(BTNMovement == 1){
                        segundos++;
                        IntToStrWithZeros(segundos, segundosT);
                        memcpy(segundosTImpresion,segundosT+4,2);
                        Lcd_Out(2,7,segundosTImpresion);
         }

         if(BTNConfig == 1){
                      modoConfig = 0;
         }
   }
}

