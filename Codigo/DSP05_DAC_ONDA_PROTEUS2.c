#define DAC GPIOB_ODR
#define BOTONSENO GPIOA_IDR.B0
#define BOTONSIERRA GPIOA_IDR.B1
#define BOTONRECTIFICADA GPIOA_IDR.B2
#define BOTONCUADRADA GPIOA_IDR.B3

const unsigned long int sin[]={127.0000, 175.6008, 216.8026, 244.3327, 254.0000, 244.3327, 216.8026, 175.6008, 127.0000, 78.3992, 37.1974, 9.6673, 0, 9.6673, 37.1974, 78.3992};
const  unsigned long int  sawtooth[]={0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128};
const  unsigned long int rectificada[]={0,25,49,71,91,106,118,126,128,126,118,106,91,71,49,25,0};
const  unsigned long int square[]={0,0,0,0,0,0,0,0,192,192,192,192,192,192,192,192};

int short i;
int limite = 16;
const retraso = 32;

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