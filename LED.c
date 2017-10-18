// FOR STUDENTS
// LED.c
// version 29/08/2017

#include "stm32f4xx_hal_conf.h"
#include "stm32f429_Discovery_conf.h"

// for #10
//TIM_HandleTypeDef TimerLED;
// for #13 : TIM2 Handler global variable
//int LED_Tim2Count=0;
void LED_Init(){
	 //GPIO_InitTypeDef GPIO_InitStruct;
	// #02 enable ports
	int *px=(int*)(0x40023800+0x30);
	*px |= 1<<6;

	// #03 configuration of G13
	
	/* Methode avec les poiteurs 
	*	int *px_GPIOG=(int*) 0x40021800 ; // Adresse de GPIOG
	*(px_GPIOG+0x0) &= 0xF3FFFFFF;      // Modification du registre GPIOG_MODER
	*(px_GPIOG+0x0) |=  1 << 26 ;
	*(px_GPIOG+0x04) &= 0xDFFF;         //Modification du registre GPIOG_OTYPER
	*(px_GPIOG+0x04) &=  0xF3FFFFFF;    // Modification du registre GPIOG_OSPEEDR
	*(px_GPIOG+0x0C) &= 0xF3FFFFFF;     // Modification du registre GPIOG_PUPDR
	*/
	
	/* Methode avec les structures */
	GPIOG->MODER &= 0xF3FFFFFF;
	GPIOG->MODER |=  1 << 26 ;	
	GPIOG->OTYPER &= 0xDFFF;
	GPIOG->OSPEEDR &=  0xF3FFFFFF; 
	GPIOG->PUPDR &= 0xF3FFFFFF;
	
	// #04 configuration of G14

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Speed= GPIO_SPEED_LOW;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Pin = GPIO_PIN_14;
	HAL_GPIO_Init(GPIOG,&GPIO_InitStruct);
	// #09 enable Timer2

	// #12 config IT TIM2	: enable interrupt
}
void LED_DispRed(int val){
	if(val==1){
		GPIOG->ODR |= 1<<14;
	}else{
		GPIOG->ODR &= 0xBFFF;
	}
}

void LED_DispGreen(int val){
	if(val==1){
		GPIOG->ODR |= 1<<13;
	}else{
		GPIOG->ODR &= 0xDFFF;
	}
}

void LED_Disp1LED(int val){

}

// for #13
//void TIM2_IRQHandler(void){
	// Don't forget to erase request #13
	
	// #13 Make the LED blink!

//}

//for #16
//void LED_SetFreqGreen(int f){
//}

