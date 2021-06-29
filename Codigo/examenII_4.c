
#define LED2   GPIOA_ODR.B6

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

  //Configuraci?n del timer 2
  RCC_APB1ENRbits.TIM2EN=1; //Habilita el timer 2
  TIM2_CR1.CEN=0;     //DETIENE EL CONTADOR
  //TIM2_PSC=7999;      //PRESCALADOR Establece el prescalador APB1/(PSC+1) =1000Hz
  TIM2_PSC=15999;
  TIM2_ARR=0.079;       //ARR=tiempo deseado*FrecContador(500 ms de retardo)
  TIM2_DIER.UIE=1;    //Pedir atenci?n por interrupci?n a la bandera de interrupci?n
  NVIC_IntEnable(IVT_INT_TIM2);//Configura la interrupci?n en el NVIC
  TIM2_CR1.CEN=1;              //EMPIEZA A CONTAR
  EnableInterrupts();

 }

 void Ini_var()
 {
  LED2 = 0;
 }


void Proceso2() iv IVT_INT_TIM2 ics ICS_AUTO{
   TIM2_SRbits.UIF=0;
   LED2=~LED2;
}


