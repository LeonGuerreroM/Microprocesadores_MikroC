#define DISPLAY GPIOB_ODR
#define DISPLAY2 GPIOA_ODR
#define LECTADC GPIOC_IDR
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

int i = 0;
const unsigned short int segmentos[] = {CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,OCHO,NUEVE};
float adc_value = 0;
float volt = 0;
unsigned short int decimal = 0;
unsigned short int num = 0;
unsigned short int decimal2 = 0;

void Conf_maq();
void Procesamiento();

void main() {
     Conf_maq();
     while(1)
     Procesamiento();
}

void Conf_maq(){
     GPIO_Config(&GPIOA_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6,_GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ |_GPIO_CFG_OTYPE_PP);
     GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6,_GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ |_GPIO_CFG_OTYPE_PP);
     GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3| _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6,_GPIO_CFG_MODE_INPUT | _GPIO_CFG_SPEED_2MHZ );
}

void Procesamiento(){
     adc_value = LECTADC;
     volt = adc_value*5/256;
     num = floor(volt);
     decimal = (volt-num)*10;
     decimal2 = (volt-num)*100-decimal*10;
     DISPLAY = segmentos[num];
     DISPLAY2 = segmentos[decimal];
}