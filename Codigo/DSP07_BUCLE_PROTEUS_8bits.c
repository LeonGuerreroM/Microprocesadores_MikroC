#define LECTADC GPIOA_IDR
#define DAC GPIOC_ODR

float adc_value;

void Conf_maq();
void Procesamiento();

void main() {
     Conf_maq();
     while(1)
     Procesamiento();
}

void Conf_maq(){
     GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7, _GPIO_CFG_MODE_INPUT| _GPIO_CFG_SPEED_2MHZ );
     GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7);
}

void Procesamiento(){
     adc_value = LECTADC;
     DAC = adc_value;
}