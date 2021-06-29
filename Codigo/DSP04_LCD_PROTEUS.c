sbit LCD_RS at GPIOC_ODR.B0;
sbit LCD_EN at GPIOC_ODR.B1;
sbit LCD_D4 at GPIOC_ODR.B2;
sbit LCD_D5 at GPIOC_ODR.B3;
sbit LCD_D6 at GPIOC_ODR.B4;
sbit LCD_D7 at GPIOC_ODR.B5;
char txt1[] = "Mora Guerrero León Sergio";
char limpiar[] = "                 ";
char hora[30];
char segundos[2];
char minutos[2];
char horas[2];
char puntos[] = ":";
#define LED GPIOA_ODR.B0
#define LED2 GPIOA_ODR.B2
#define boton GPIOA_IDR.B1

int i = 0, j = 0, k = 0, a = 0;

void lectura()
{
     char txt[7];
     Lcd_Out(2,1,limpiar);
     
     for(i=0;i<25;i++){
        sprintf(horas,"%d",i);
        for(j=0;j<60;j++){
           sprintf(minutos,"%d",j);
           for(k=0;k<60;k++){
            Lcd_Out(2,1,limpiar);
            for(i=0;i<30;i++){
               hora[i] = '\0';
            }
            strcat(hora,horas);
            strcat(hora,puntos);
            strcat(hora,minutos);
            strcat(hora,puntos);
            sprintf(segundos,"%d",k);
            strcat(hora,segundos);
            Lcd_Out(2,1,limpiar);
            Lcd_Out(2,1,hora);
            LED = ~LED;
            if(boton == 1){
                 LED2 = 0;
                 Delay_ms(10);

           }else{ 
                  LED2 = 1;
                 Delay_ms(1000);
           }
           }
        }
     }
}

void main() {
   //inicialización del lcd
   Lcd_Init();                                            // Initialize LCD
   Lcd_Cmd(_LCD_CLEAR);               // Clear display
   Lcd_Cmd(_LCD_CURSOR_OFF);  // Cursor off
   //Lcd_Out(1,1,txt1);
   
   GPIO_Digital_Output(&GPIOA_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_2);
   GPIO_Digital_Input(&GPIOA_BASE,_GPIO_PINMASK_1);
   GPIO_Digital_Output(&GPIOC_BASE,_GPIO_PINMASK_0|_GPIO_PINMASK_1|_GPIO_PINMASK_2|_GPIO_PINMASK_3|_GPIO_PINMASK_4|_GPIO_PINMASK_5);
   LED2 = 1;

   while(1){
      lectura();
   }
   
}