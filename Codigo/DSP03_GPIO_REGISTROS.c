#define BOTONLED GPIOB_IDR.B0
#define BOTONDISPLAY GPIOC_IDR.B0

#define LA0 GPIOB_ODR.B1
#define LA1 GPIOB_ODR.B2
#define LA2 GPIOB_ODR.B3
#define LA3 GPIOB_ODR.B4
#define LA4 GPIOB_ODR.B5
#define LA5 GPIOB_ODR.B6
#define LA6 GPIOB_ODR.B7
#define LA7 GPIOB_ODR.B8
#define LA8 GPIOB_ODR.B9

#define DISPLAY GPIOC_ODR

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
#define CARA 0X88
#define CARB 0X83
#define CARC 0XA7
#define CARD 0XA1
#define CARE 0X86
#define CARF 0X8E

const unsigned short int segmentos[]={CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE, OCHO,NUEVE,CARA,CARB,CARC,CARD,CARE,CARF};
unsigned int contador = 0;


void Conf_maq();
void Ini_var();
void Proceso();

void main() {
     Conf_maq();
     Ini_var();
     while(1) //Bucle principal
        Proceso();
}

void Conf_maq()
{
 //limpiadno y configurante entradas
 RCC_APB2ENR|=1<<IOPBEN;
 RCC_APB2ENR|=1<<IOPCEN;
 
 GPIOB_CRL&=~(15uL<<(0*4));
 GPIOB_CRL|=(4uL<<(0*4));

 GPIOC_CRL&=~(15uL<<(0*4));
 GPIOC_CRL|=(4uL<<(0*4));

 //limpiando y configurando salidas de leds
 GPIOB_CRL&=(~(2ul<<(1*4))|~(2uL<<(2*4))|~(2uL<<(3*4))|~(2uL<<(4*4))|~(2uL<<(5*4))|~(2uL<<(6*4))|~(2uL<<(7*4)));
 GPIOB_CRH&=~(15uL<<(0*4));
 GPIOB_CRL|=((2ul<<(1*4))|(2uL<<(2*4))|(2uL<<(3*4))|(2uL<<(4*4))|(2uL<<(5*4))|(2uL<<(6*4))|(2uL<<(7*4)));
 GPIOB_CRH|=(2uL<<(0*4));



 //limpiando y configurando salidas de display
 GPIOC_CRL&=(~(2ul<<(1*4))|~(2uL<<(2*4))|~(2uL<<(3*4))|~(2uL<<(4*4))|~(2uL<<(5*4))|~(2uL<<(6*4))|~(2uL<<(7*4)));
 GPIOC_CRL|=((2ul<<(1*4))|(2uL<<(2*4))|(2uL<<(3*4))|(2uL<<(4*4))|(2uL<<(5*4))|(2uL<<(6*4))|(2uL<<(7*4)));

}

void Ini_var()
{
     contador = 0;

     LA0 = 1;
     LA1 = 1;
     LA2 = 1;
     LA3 = 1;
     LA4 = 1;
     LA5 = 1;
     LA6 = 1;
     LA7 = 1;
     LA8 = 1;

     DISPLAY = segmentos[0];

}

void Proceso()
{
    if(BOTONLED == 1)
    {
               LA0 = ~LA0;
               Delay_ms(200);
               LA0 = ~LA0;
               LA1 = ~LA1;
               Delay_ms(200);
               LA1 = ~LA1;
               LA2 = ~LA2;
               Delay_ms(200);
               LA2 = ~LA2;
               LA3 = ~LA3;
               Delay_ms(200);
               LA3 = ~LA3;
               LA4 = ~LA4;
               Delay_ms(200);
               LA4 = ~LA4;
               LA5 = ~LA5;
               Delay_ms(200);
               LA5 = ~LA5;
               LA6 = ~LA6;
               Delay_ms(200);
               LA6 = ~LA6;
               LA7 = ~LA7;
               Delay_ms(200);
               LA7 = ~LA7;
               LA8 = ~LA8;
               Delay_ms(200);
               LA8 = ~LA8;
               LA7 = ~LA7;
               Delay_ms(200);
               LA7 = ~LA7;
               LA6 = ~LA6;
               Delay_ms(200);
               LA6 = ~LA6;
               LA5 = ~LA5;
               Delay_ms(200);
               LA5 = ~LA5;
               LA4 = ~LA4;
               Delay_ms(200);
               LA4 = ~LA4;
               LA3 = ~LA3;
               Delay_ms(200);
               LA3 = ~LA3;
               LA2 = ~LA2;
               Delay_ms(200);
               LA2 = ~LA2;
               LA1 = ~LA1;
               Delay_ms(200);
               LA1 = ~LA1;
               LA0 = ~LA0;
               Delay_ms(100);
               LA0 = ~LA0;
    }

    if(BOTONDISPLAY == 1){
                      DISPLAY = segmentos[contador]<<1;
                      contador++;
                      if(contador > 15)
                      contador = 0;
                      Delay_ms(200);
    }
}