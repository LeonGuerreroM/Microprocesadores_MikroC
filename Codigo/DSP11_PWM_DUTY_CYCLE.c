unsigned int current_duty1, current_duty2, current_duty3,  old_duty;
unsigned int pwm_period1, pwm_period2,  pwm_period3;

#define LECTADC GPIOC_IDR
#define BTN1   GPIOB_IDR.B10
#define BTN2   GPIOB_IDR.B11
#define BTN3   GPIOB_IDR.B12

 sbit LCD_RS at GPIOA_ODR.B10;
 sbit LCD_EN at GPIOA_ODR.B11;
 sbit LCD_D4 at GPIOA_ODR.B12;
 sbit LCD_D5 at GPIOA_ODR.B13;
 sbit LCD_D6 at GPIOA_ODR.B14;
 sbit LCD_D7 at GPIOA_ODR.B15;

float volt, volt_dec;
float adc_value;
float duty_cycle;
float duty_impresion;
int volt_entero;
int frec = 500;

void InitMain();
void valores(int opcion);



void main() {

  InitMain();
  Lcd_Init();

  current_duty1  = 10;
  current_duty2  = 10;
  current_duty3  = 10;

  pwm_period1 = PWM_TIM2_Init(frec);
  pwm_period2 = PWM_TIM2_Init(frec);
  pwm_period3 = PWM_TIM3_Init(frec);

  PWM_TIM2_Set_Duty(current_duty1, _PWM_NON_INVERTED, _PWM_CHANNEL2);
  PWM_TIM2_Set_Duty(current_duty2, _PWM_NON_INVERTED, _PWM_CHANNEL3);
  PWM_TIM3_Set_Duty(current_duty3, _PWM_NON_INVERTED, _PWM_CHANNEL3);

  while (1) {

    if (BTN1 == 0){
      PWM_TIM2_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM2_CH2_PA1);
      valores(1);
      //duty_cycle = volt_dec*0.2;
      duty_cycle = volt_dec;

      if (GPIOA_IDR.B4) {                         // button on RA4 pressed
        Delay_ms(1);
        PWM_TIM2_Set_Duty(pwm_period1*duty_cycle,  _PWM_NON_INVERTED, _PWM_CHANNEL2); // set newly acquired duty ratio
       }

      Delay_ms(1);                                       // slow down change pace a little
    }

    if (BTN2 == 0){
      PWM_TIM2_Start(_PWM_CHANNEL3,&_GPIO_MODULE_TIM2_CH3_PA2);
      valores(2);
      //duty_cycle = volt_dec*0.2;
      duty_cycle = volt_dec;

      if (GPIOA_IDR.B4) {                         // button on RA4 pressed
        Delay_ms(1);
        PWM_TIM2_Set_Duty(pwm_period2*duty_cycle,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
       }

      Delay_ms(1);                                       // slow down change pace a little
    }

    if (BTN3 == 0){
      PWM_TIM3_Start(_PWM_CHANNEL3,&_GPIO_MODULE_TIM3_CH3_PB0);
      valores(3);
      //duty_cycle = volt_dec*0.2;
      duty_cycle = volt_dec;

      if (GPIOA_IDR.B4) {                         // button on RA4 pressed
        Delay_ms(1);
        PWM_TIM3_Set_Duty(pwm_period3*duty_cycle,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
       }

      Delay_ms(1);                                       // slow down change pace a little
    }

  }
}

void InitMain() {
   GPIO_Digital_Output (&GPIOA_BASE, _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3 | _GPIO_PINMASK_4);
   GPIO_Digital_Output (&GPIOB_BASE, _GPIO_PINMASK_0  );

   GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_11 |
   _GPIO_PINMASK_12 | _GPIO_PINMASK_13 | _GPIO_PINMASK_14 |
   _GPIO_PINMASK_15, _GPIO_CFG_MODE_OUTPUT |
  _GPIO_CFG_SPEED_2MHZ |
   _GPIO_CFG_OTYPE_PP);

  GPIO_Digital_Input (&GPIOB_BASE, _GPIO_PINMASK_10 | _GPIO_PINMASK_11 | _GPIO_PINMASK_12);

  GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 |
  _GPIO_PINMASK_3
 | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7,
 _GPIO_CFG_MODE_INPUT | _GPIO_CFG_SPEED_2MHZ ); //entradas digitales del ADC

}

void valores(int opcion){

  char txt1[] = "Timer 2 en Canal 2";
  char txt2[] = "Timer 2 en Canal 3";
  char txt3[] = "Timer 3 en Canal 3";
  //char txt4[] = "C:";
  //char txt5[] = "F:";
  char txt_frec[5];
  char txt_duty[3];
  char conjunto[18];
  char espacio[] = "  ";
  //char txt_limpiar[] = "                     ";

  Lcd_Cmd(_LCD_CURSOR_OFF);  // Cursor off
  adc_value=LECTADC;
  //volt_dec=adc_value*5/256;
  volt_dec=adc_value/256;
  FloatToStr(volt_dec*0.2,txt_duty);
  FloatToStr(frec,txt_frec);

  //Lcd_Out(2,1,txt_frec);
  Lcd_Out(2,1,txt_duty);

  if(opcion==1) {
     char txt1[] = "Timer 2 en Canal 2";
    //Lcd_Out(1,1,txt1);
    //Lcd_Out(2,1,txt_limpiar);
    //Lcd_Out(2,1,txt4);
    //Lcd_Out(2,1,txt_duty);
    //Lcd_Out(2,16,txt5);
    //Lcd_Out(2,10,txt_frec);
  }

  if(opcion==2) {
     char txt1[] = "Timer 2 en Canal 3";
    //Lcd_Out(1,1,txt2);
    //Lcd_Out(2,1,txt_limpiar);
    //Lcd_Out(2,1,txt4);
    //Lcd_Out(2,1,txt_duty);
    //Lcd_Out(2,16,txt5);
    //Lcd_Out(2,10,txt_frec);
  }

  if(opcion==3) {
     char txt1[] = "Timer 3 en Canal 3";
    //Lcd_Out(1,1,txt3);
    //Lcd_Out(2,1,txt_limpiar);
    //Lcd_Out(2,1,txt4);
    //Lcd_Out(2,1,txt_duty);
    //Lcd_Out(2,16,txt5);
    //Lcd_Out(2,10,txt_frec);
  }
  
  Lcd_Out(1,1,txt1);
  Lcd_Out(2,1,txt_duty);

}