
// 		Puerto A:								
//		Pin 0: Tx					
//		Pin 1: Rx
//		Pin 4: DAC 1
//    Pin 5: DAC 2
#include <stdio.h>
#include "stm32f7xx.h"

int display, cont=0, borrar=0;
char envio1[]={"MENSAJE DE PRUEBA\n\r-"};
char envio,menu;
char uesca[255];
float auxr=0;
int j=0,uk[255];
float rampa[255];
float yk,yk1,u,P1[255],rr,rrr,u1,P2[255];
int y,DATO;
char dato1,dato2,dato3,dato4,dato5;
float u_menos1=0,u_menos2=0,y_menos1=0,y_menos2=0;
float u_menos11=0,u_menos22=0,y_menos11=0,y_menos22=0;
float err[255];


void send(int senal){

switch(senal){
	case 1:
		
		for(int i=0;i<255;i++){
   envio=uesca[i];
	 if(envio==0){
		 UART4->TDR='-';
		while ((UART4->ISR &=0x80)==0);
	 UART4->TDR='1';
		while ((UART4->ISR &=0x80)==0);

	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
	 }else{
	 UART4->TDR=envio;
		while ((UART4->ISR &=0x80)==0);

	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		 }
}
		
break;
	case 2:
		
	for(int i=0;i<255;i++){


envio=uesca[i];
	UART4->TDR=envio;
		while ((UART4->ISR &=0x80)==0);

	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);




}
	
break;
	case 3:
		
break;
	
	case 4:
	for(int i=0;i<255;i++){ //enviar señal
   envio=uesca[i];
	 if(envio=='0'){
		 UART4->TDR='-';
		while ((UART4->ISR &=0x80)==0);
	 UART4->TDR='1';
		while ((UART4->ISR &=0x80)==0);

	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
	 }else{
	 UART4->TDR=envio;
		while ((UART4->ISR &=0x80)==0);

	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		 }
}
	
		break;


	case 5:
	for(int i=0;i<255;i++){ //enviar señal
	DATO=P1[i]*10000;

		
		if(DATO<0){
			DATO=DATO*-1;
	dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
		UART4->TDR='-';
		while ((UART4->ISR &=0x80)==0){};
	    UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		}else{//enviar positivo
			dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
			UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		}
		
	
	}


	
		break;
	case 6:
		
	for(int i=0;i<255;i++){ //enviar señal P2
	DATO=P2[i]*10000;

		
		if(DATO<0){
			DATO=DATO*-1;
	dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
		UART4->TDR='-';
		while ((UART4->ISR &=0x80)==0){};
	    UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		}else{//enviar positivo
			dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
			UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		
		}
		
	
	}
		break;
	case 7:
		for(int i=0;i<255;i++){ //enviar señal error
	DATO=err[i]*10000;

		
		if(DATO<0){
			DATO=DATO*-1;
	dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
		UART4->TDR='-';
		while ((UART4->ISR &=0x80)==0){};
	    UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		}else{//enviar positivo
			dato1=((DATO%100000)/10000)+0x30;//diezmil
  dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
			UART4->TDR=dato1;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato2;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0);
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		
		}
		
	
	}
	
	
		break;
	case 8:
		for(int i=0;i<255;i++){ //enviar señal
	DATO=rampa[i]*100;
			
	//dato1=((DATO%100000)/10000)+0x30;//diezmil
  //dato2=((DATO%10000)/1000)+0x30;//mil
  dato3=((DATO%1000)/100)+0x30;//cien
  dato4=((DATO%100)/10)+0x30;//diez
  dato5=(DATO%10)+0x30;//uno
			UART4->TDR=dato3;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR='.';
		while ((UART4->ISR &=0x80)==0){};
      UART4->TDR=dato4;
		while ((UART4->ISR &=0x80)==0){};
			UART4->TDR=dato5;
		while ((UART4->ISR &=0x80)==0){};
			
	UART4->TDR='\n';
		while ((UART4->ISR &=0x80)==0);
		}
		break;

}	
	
	


}

void send_dato(char dt){
	UART4->TDR=dt;
	while ((UART4->ISR &=0x80)==0);//esperar hasta que TXE sea 1
	//dato='0';
}
extern "C"{

	void UART4_IRQHandler(void){
	if(UART4->ISR & 0x20){
	menu=UART4->RDR;
	}
	
	}

}


int main(void){
RCC->AHB1ENR |=(1UL<<0);//CLOCK PTA
RCC->AHB1ENR |=(1UL<<1);//CLOCK PTB
RCC->AHB1ENR |=(1UL<<2);//CLOCK PTC


//RCC->APB2ENR|=(1UL<<14);//SYSTEM CONFIGURATION ENABLE
RCC->APB1ENR|=(1UL<<19); //HABILITAR UART4 
//***********************PUERTO B********************************	
GPIOB->MODER=0X10004001;//PB0, PB7 Y PB14 OUTPUT
GPIOB->OTYPER=0;
GPIOB->OSPEEDR=0X10004001;
GPIOB->PUPDR=0X10004001;

//***********************PUERTO A**********************************
GPIOA->MODER|=0X52550;//PA6 A PA9 COMO SALIDA Y PA10 A PA12 Y PA15 COMO ENTRADA
GPIOA->OTYPER=0;
GPIOA->OSPEEDR=0X82AAA000;//VELOCIDAD ALTA PINES DE ENTRADA
GPIOA->PUPDR=0X82A52550;
GPIOA->ODR &=0; //INICIALIZA EL POLLING EN 0
	

//**********************PUERTO C*********************************
GPIOC->MODER |=  (2UL << 2*10);  //pines PC10 en modo alterno (TX)
GPIOC->MODER |=  (2UL << 2*11);  //pines PC11 en modo alterno (RX)
GPIOC->AFR[1] |= 0x8800;    // PC10 -> AF8=UART7 TX, AF8=1000 en AFR8 -- PC11 -> AF8=UART7 RX, AF8=1000 en AFR8 

//**********************UART 4*********************************
UART4->BRR=0X683; //9600 BAUDIOS
UART4->CR1|=0X2C; //Tx Rx HABILITADOS
UART4->CR1|=0x1; //HABILITAR SERIAL

NVIC_EnableIRQ(UART4_IRQn); //HABILITAR INTERRUPCION
 


while(true){

			
		
	
switch(menu){
	case 'a': //servo-pulso
		
		for(int i=0;i<255;i++){ //construir señal escalon
		if (j<=50){
		uesca[i]='1';
		uk[i]=1;
		j++;
		}
		if(j>50){
		uesca[i]='0';
		uk[i]=0;
		j++;
	  if(j>100){
		j=0;
		}
		}
		
		
		
		}//for
	
		
		send(1);
		GPIOB->ODR|=(1UL<<0);
break;
	case 'b': //servo-rampa
		
		
		
		GPIOB->ODR|=(1UL<<7);
break;
	case 'c': //servo-seno
		GPIOB->ODR|=(1UL<<14);
break;
	case 'd': //LGR-pulso
		
		for(int i=0;i<255;i++){ //construir señal escalon
		if (j<=50){
		uesca[i]='1';
		uk[i]=1;
		j++;
		}
		if(j>50){
		uesca[i]='0';
		uk[i]=0;
		j++;
	  if(j>100){
		j=0;
		}
		}
		}//for
		send(4); //enviar entrada pulso
		for(int h=0;h<255;h++){
		u_menos2=u_menos1;
		u_menos1=u;
		u=uk[h];
	  y_menos2=y_menos1;
		y_menos1=yk;
		yk=(4008.559*u)-(4008.559*u_menos1)+(1.977/10000000*u_menos2)+(0.956011*y_menos1)+(0.043988*y_menos2);
		rr=yk/4000;
		P1[h]=rr;
		}
		send(5);//enviar respuesta P1
		
		for(int h=0;h<255;h++){
		u_menos22=u_menos11;
		u_menos11=u1;
		u1=uk[h];
	  y_menos22=y_menos11;
		y_menos11=yk1;
		yk1=(298.0303*u)-(478.0303*u_menos1)+(298.0303*u_menos2)+(0.6396*y_menos1)+(0.3603*y_menos2);
		rrr=(yk1/-2574);
		P2[h]=rrr;
		}
		send(6);//enviar respuesta Planta2
		
		for(int x=0;x<255;x++){
		err[x]=uk[x]-P1[x];
		}
		send(7);//enviar señal de error
		
		GPIOB->ODR &=~(1UL<<0);
break;
		
	case 'e': //LGR-rampa
  for(int i=0;i<255;i++){ //construir señal rampa
		rampa[i]=auxr;
		auxr=auxr+0.01;
		}//for
	send(8);//enviar señal rampa
		
		for(int h=0;h<255;h++){//Planta11
		u_menos2=u_menos1;
		u_menos1=u;
		u=rampa[h];
	  y_menos2=y_menos1;
		y_menos1=yk;
		yk=(4008.559*u)-(4008.559*u_menos1)+(1.977/10000000*u_menos2)+(0.956011*y_menos1)+(0.043988*y_menos2);
		rr=yk/4000;
		P1[h]=rr;
		}
		send(5);//enviar respuesta Planta1
		
		for(int h=0;h<255;h++){//P2
		u_menos22=u_menos11;
		u_menos11=u1;
		u1=rampa[h];
	  y_menos22=y_menos11;
		y_menos11=yk1;
		yk1=(298.0303*u)-(478.0303*u_menos1)+(298.0303*u_menos2)+(0.6396*y_menos1)+(0.3603*y_menos2);
		rrr=(yk1/10038);
		P2[h]=rrr;
		}
		send(6);//enviar respuesta Planta2
		
		for(int x=0;x<255;x++){
		err[x]=rampa[x]-P1[x];
		}
		send(7);//enviar señal de error
		
	GPIOB->ODR &=~(1UL<<7);
	
break;
		
		
	case 'f': //LGR-seno
		send_dato('L');
		GPIOB->ODR&=~(1UL<<14);
break;
	case 'g'://Reset
		for(int x=0;x<255;x++){
		err[x]=0;
		rampa[0]=0;
    uk[x]=0;
    P1[x]=0;
    P2[x]=0;
		
		}
		
		u_menos1=0;
		u_menos2=0;
		y_menos1=0;
		y_menos2=0;
    u_menos11=0;
		u_menos22=0;
		y_menos11=0;
		y_menos22=0;
		auxr=0;
		u=0;
		u1=0;
		yk=0;
		yk1=0;
		break;
}	

	



}//Cierra while
}//cierra main