#define DAC GPIOB_ODR
#define BOTONSENO GPIOA_IDR.B0
#define BOTONSIERRA GPIOA_IDR.B1
#define BOTONRECTIFICADA GPIOA_IDR.B2
#define BOTONCUADRADA GPIOA_IDR.B3

const unsigned short int sin[]={127.0000, 216.8026, 254.0000, 216.8026, 127.0000, 37.1974, 0, 37.1974};
const  unsigned short int  sawtooth[]={0,16,32,48,64,80,96,112};
const  unsigned short int rectificada[]={0,49,91,118,128,118,91,49};
const  unsigned short int square[]={0,0,0,0,192,192,192,192};

int short i;
int limite = 8;
const retraso = 16;

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

      GPIO_Config(&GPIOB_BASE, _GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5|_GPIO_PINMASK_6|_GPIO_PINMASK_7, _GPIO_CFG_MODE_OUTPUT | _GPIO_CFG_SPEED_2MHZ | _GPIO_CFG_OTYPE_PP);
      GPIO_Digital_Input(&GPIOA_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3);

}
void Ini_var(){
     DAC = 0;
     i = 0;

}

void Procesamiento(){
  if(BOTONSENO==1){
     for(i=0;i<=limite;i++){
     DAC = sin[i];
     delay_ms(retraso);
   }
  }
  if(BOTONSIERRA==1){
     for(i=0;i<=limite;i++){
     DAC = sawtooth[i];
     delay_ms(retraso);
   }
  }
  if(BOTONRECTIFICADA==1){
       for(i=0;i<=limite;i++){
       DAC = rectificada[i];
       delay_ms(retraso);
         }
  }
  if(BOTONCUADRADA==1){
         for(i=0;i<=limite;i++){
         DAC = square[i];
         delay_ms(retraso);
       }
  }
}