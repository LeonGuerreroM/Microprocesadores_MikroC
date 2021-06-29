//#define BOTON GPIOC_IDR.B13 //Botón de usuario (PC13 pin 23 del CN7)
//#define LED   GPIOA_ODR.B5  //Led de usuario (PA5 pin 11 del CN10)
#define BOTON GPIOC_IDR.B12   //Entrada externa PB5
#define LED   GPIOA_ODR.B6    //Salida

//PROTOTIPOS  DE LAS FUNCIONES
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
   GPIO_Digital_Input(&GPIOC_BASE,_GPIO_PINMASK_12);   //Entrada externa flotante usando un push button en el pin PC12
                                        //(Si es flotante se puede poner como entrada normalmente en bajo (0V) y con el botón se activa en
                                        //3.3V. El usuario coloca una resistencia de 1 K ? a tierra.
                                        //También si es flotante se puede poner como entrada normalmente en alto (3.3 V) y con el botón se
                                        //activa en bajo (0V). El usuario coloca una resistencia de 1 K ? a 3.3V.)
    
    GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_6);    //Salida con push pull por (default)
}

void Ini_var()
{
     LED=0;
}
void Proceso()
{
     if(BOTON==0)
     {
           LED=~LED;
           Delay_ms(250); //Delay_us(250);
     }
}
