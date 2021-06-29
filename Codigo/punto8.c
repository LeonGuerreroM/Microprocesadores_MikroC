#define DAC GPIOC_ODR

//const  unsigned short int  sawtooth[]={0, 31.7500, 63.5000, 95.2500, 127.0000, 158.7500, 190.5000, 222.2500};
//const  unsigned short int rectificada[]={0, 97.2016, 179.6051, 234.6654, 254.0000, 234.6654, 179.6051, 97.2016};
//const  unsigned short int square[]={254, 254, 254, 254, 0, 0, 0, 0};
//const unsigned short int senial[] = {0, 254, 254, 254, 254, 254, 254, 254, 0, 31.7500, 63.5000, 95.2500, 127.0000, 158.7500, 190.5000, 222.2500, 0, 97.2016, 179.6051, 234.6654, 254.0000, 234.6654, 179.6051, 97.2016};

const unsigned short int senial[] = {255.0000, 212.5000, 170.0000, 127.5000, 85.0000, 42.5000, 0, 42.3333, 84.6667, 127.0000, 169.3333, 211.6667, 255.0000, 127.5000, 34.1635, 0, 34.1635, 127.5000};

int short i;
int limite = 18;
//const retraso = 0.9;

void Conf_maq();
void Procesamiento();
void Ini_var();

void main() {
  Conf_maq();
  Ini_var();
  while(1)
  Procesamiento();
}

void Conf_maq(){

      GPIO_Config(&GPIOC_BASE, _GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7, _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);

}
void Ini_var(){
     DAC = 0;
     i = 0;

}

void Procesamiento(){
     for(i=0;i<=limite;i++){
     DAC = senial[i];
     delay_us(900);
   }

}