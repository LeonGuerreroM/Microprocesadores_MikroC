#define LED1   GPIOA_ODR.B5
#define LED2   GPIOA_ODR.B6
#define LED3   GPIOA_ODR.B7

#define BOTON1   GPIOA_IDR.B12
#define BOTON2   GPIOA_IDR.B13
#define BOTON3   GPIOA_IDR.B14

void Conf_maq();
void Ini_var();
void Proceso1();
void Proceso2();
void Proceso3();

void main() {
     Conf_maq();
     Ini_var();
}

void Conf_maq()
{
  RCC_APB2ENR|=1<<IOPAEN; //HABILITA EL RELOJ DEL PUERTO A
  GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7);    //Salida con push pull
  GPIO_Digital_Input(&GPIOA_BASE,_GPIO_PINMASK_12|_GPIO_PINMASK_13|_GPIO_PINMASK_14);
  
  //Configuración del timer 4
  RCC_APB2ENRbits.TIM1EN=1;
  TIM1_CR1.CEN=0;     //DETIENE EL CONTADOR
  TIM1_PSC=7999;      //PRESCALADOR Establece el prescalador APB1/(PSC+1) =1000Hz
  TIM1_ARR=200;       //ARR=tiempo deseado*FrecContador(500 ms de retardo)
  TIM1_DIER.UIE=1;    //Pedir atenci?n por interrupci?n a la bandera de interrupci?n
  NVIC_IntEnable(IVT_INT_TIM1_UP);//Configura la interrupci?n en el NVIC
  TIM1_CR1.CEN=1;              //EMPIEZA A CONTAR
  EnableInterrupts();

  //Configuración del timer 2
  RCC_APB1ENRbits.TIM2EN=1; //Habilita el timer 2
  TIM2_CR1.CEN=0;     //DETIENE EL CONTADOR
  TIM2_PSC=7999;      //PRESCALADOR Establece el prescalador APB1/(PSC+1) =1000Hz
  TIM2_ARR=400;       //ARR=tiempo deseado*FrecContador(500 ms de retardo)
  TIM2_DIER.UIE=1;    //Pedir atención por interrupción a la bandera de interrupción
  NVIC_IntEnable(IVT_INT_TIM2);//Configura la interrupción en el NVIC
  TIM2_CR1.CEN=1;              //EMPIEZA A CONTAR
  EnableInterrupts();
  
  //Configuración del timer 3
  RCC_APB1ENRbits.TIM3EN=1;
  TIM3_CR1.CEN=0;
  TIM3_PSC=7999;
  TIM3_ARR=800;
  TIM3_DIER.UIE=1;
  NVIC_IntEnable(IVT_INT_TIM3);
  TIM3_CR1.CEN=1;
  EnableInterrupts();

 }

 void Ini_var()
 {
  LED1 = 1;
  LED2 = 1;
  LED3 = 1;
 }

void Proceso1() iv IVT_INT_TIM1_UP ics ICS_AUTO{
 if (BOTON1 == 1){
   TIM1_SRbits.UIF=0;
   LED1=~LED1;
 }
}

void Proceso2() iv IVT_INT_TIM2 ics ICS_AUTO{
 if (BOTON2 == 1){
   TIM2_SRbits.UIF=0;
   LED2=~LED2;
 }
}

void Proceso3() iv IVT_INT_TIM3 ics ICS_AUTO{
 if (BOTON3 == 1){
   TIM3_SRbits.UIF=0;
   LED3=~LED3;
 }
}


