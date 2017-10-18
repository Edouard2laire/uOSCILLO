
// FOR STUDENTS
// principal.c
// version 29/08/2017

#include "stm32f4xx_hal_conf.h"
#include "stm32f429_Discovery_conf.h"

// for #22
//extern unsigned short int SCREEN_Font11x18 [];
//extern SCREEN_FontDef_t SCREEN_FormatFont_11x18;

// #8 Call of "IncTick" Handler
//void SysTick_Handler(){
//	HAL_IncTick();
//}


void PRINCIPAL_Init(){
	LED_Init();
	//declaration for #9
	//volatile int f1,f2;
	//#23 : display of f1 and f2 using printf 
}

void test01(){
	PRINCIPAL_Init();
	// #05 Tests LED_Dispxxx
	while(1){
		LED_DispRed(1);
		LED_DispGreen(1);
		LED_DispRed(0);
		LED_DispGreen(0);

	}

}

int main(){
	// QUESTION 01
	test01();
	return 0;
}

