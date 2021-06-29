unsigned int current_duty1, current_duty2, current_duty3;
unsigned int pwm_period1, pwm_period2, pwm_period3;

void InitMain() {
  GPIO_Digital_Input (&GPIOA_BASE, _GPIO_PINMASK_3 | _GPIO_PINMASK_4); // configure PORTA pins as input
  GPIO_Digital_Output (&GPIOA_BASE, _GPIO_PINMASK_1| _GPIO_PINMASK_2); // configure PORTA pins as output
  GPIO_Digital_Output (&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_10);
}

void main() {
  InitMain();
  current_duty1  = 10;                        // initial value for current_duty1,2 and 3
  current_duty2  = 10;
  current_duty3  = 10;

  pwm_period1 = PWM_TIM2_Init(500);
  pwm_period2 = PWM_TIM2_Init(500);
  pwm_period3 = PWM_TIM3_Init(500);

  PWM_TIM2_Set_Duty(current_duty1,  _PWM_NON_INVERTED, _PWM_CHANNEL2);  // Set current duty for PWM_TIM
  PWM_TIM2_Set_Duty(current_duty2,  _PWM_NON_INVERTED, _PWM_CHANNEL3);
  PWM_TIM3_Set_Duty(current_duty3,  _PWM_NON_INVERTED, _PWM_CHANNEL3);

  PWM_TIM2_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM2_CH2_PA1);
  PWM_TIM2_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM2_CH3_PA2);
  PWM_TIM3_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM3_CH3_PB0);

  while (1) {                                // endless loop
    if (GPIOA_IDR.B3) {           // button on RA3 pressed
      Delay_ms(1);
      current_duty1 = current_duty1 + 5;          // increment current_duty
      if (current_duty1 > pwm_period1) {      // if we increase current_duty greater then possible pwm_period1 value
        current_duty1 = 0;                                // reset current_duty value to zero
      }
      PWM_TIM2_Set_Duty(current_duty1,  _PWM_NON_INVERTED, _PWM_CHANNEL2); // set newly acquired duty ratio
     }

    if (GPIOA_IDR.B4) {                         // button on RA4 pressed
      Delay_ms(1);
      current_duty1 = current_duty1 - 5;       // decrement current_duty
      if (current_duty1 > pwm_period1) {   // if we decrease current_duty greater then possible pwm_period1 value (overflow)
        current_duty1 = pwm_period1;         // set current_duty to max possible value
      }
      PWM_TIM2_Set_Duty(current_duty1,  _PWM_NON_INVERTED, _PWM_CHANNEL2); // set newly acquired duty ratio
     }



    if (GPIOA_IDR.B3) {           // button on RA3 pressed
      Delay_ms(1);
      current_duty2 = current_duty2 + 5;          // increment current_duty
      if (current_duty2 > pwm_period2) {      // if we increase current_duty greater then possible pwm_period1 value
        current_duty2 = 0;                                // reset current_duty value to zero
      }
      PWM_TIM2_Set_Duty(current_duty2,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
     }

    if (GPIOA_IDR.B4) {                         // button on RA4 pressed
      Delay_ms(1);
      current_duty2 = current_duty2 - 5;       // decrement current_duty
      if (current_duty2 > pwm_period2) {   // if we decrease current_duty greater then possible pwm_period1 value (overflow)
        current_duty2 = pwm_period2;         // set current_duty to max possible value
      }
      PWM_TIM2_Set_Duty(current_duty2,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
     }


    if (GPIOA_IDR.B3) {           // button on RA3 pressed
      Delay_ms(1);
      current_duty3 = current_duty3 + 5;          // increment current_duty
      if (current_duty3 > pwm_period3) {      // if we increase current_duty greater then possible pwm_period1 value
        current_duty3 = 0;                                // reset current_duty value to zero
      }
      PWM_TIM3_Set_Duty(current_duty3,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
     }

    if (GPIOA_IDR.B4) {                         // button on RA4 pressed
      Delay_ms(1);
      current_duty3 = current_duty3 - 5;       // decrement current_duty
      if (current_duty3 > pwm_period3) {   // if we decrease current_duty greater then possible pwm_period1 value (overflow)
        current_duty3 = pwm_period3;         // set current_duty to max possible value
      }
      PWM_TIM3_Set_Duty(current_duty3,  _PWM_NON_INVERTED, _PWM_CHANNEL3); // set newly acquired duty ratio
     }
    Delay_ms(1);
  }
}