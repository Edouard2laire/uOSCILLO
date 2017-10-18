#include "stm32f4xx_hal_conf.h"
#include "stm32f429_Discovery_conf.h"

void SIGNALS_init(){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//initialisation de PE3
	__GPIOE_CLK_ENABLE();
	
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	
}

void SIGNALS_toggle_PE3(){
	int PE3;
	PE3= ( (GPIOE->IDR) & (1<<3) ) >> 3;
	PE3=(PE3+1)%2;
	if(PE3==0)
		GPIOE->ODR = GPIOE->ODR & ~(1<<3);
	else
		GPIOE->ODR = GPIOE->ODR | (1<<3);
}

