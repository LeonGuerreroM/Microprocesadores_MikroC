#define LECTADC GPIOB_IDR
#define DAC GPIOC_ODR

sbit RC at GPIOB_IDR.B12;

unsigned short int i = 0;
float adc_value, adc_value2, volt, num1, num2, num3;

void Conf_maq();
void Procesamiento();



void main() {
     Conf_maq();
     while(1)
              Procesamiento();
}

void Conf_maq(){
     GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7| _GPIO_PINMASK_8| _GPIO_PINMASK_9| _GPIO_PINMASK_10| _GPIO_PINMASK_11);
     GPIO_Digital_Input(&GPIOB_BASE,_GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7| _GPIO_PINMASK_8| _GPIO_PINMASK_9| _GPIO_PINMASK_10| _GPIO_PINMASK_11| _GPIO_PINMASK_12);
     GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3
      | _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7| _GPIO_PINMASK_8| _GPIO_PINMASK_9
      | _GPIO_PINMASK_10| _GPIO_PINMASK_11| _GPIO_PINMASK_12, _GPIO_CFG_MODE_INPUT | _GPIO_CFG_PULL_DOWN );
}
      
void Procesamiento(){
     if(RC==1){
               adc_value = LECTADC;
               DAC = adc_value;
     }
}