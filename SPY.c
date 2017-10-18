// FOR STUDENTS
// SPY.c
// version 29/08/2017

#include "stm32f4xx_hal_conf.h"
#include "stm32f429_Discovery_conf.h"

TIM_HandleTypeDef TimerAcqu;
ADC_HandleTypeDef hadc;

int SPY_x=0;

// to clear window 1 2 or 3
void SPY_ClearWindow(int n){
	int x0,y0,x1,y1;
	if(n>0 && n<4){
		x0=0;
		y0=160+(n-1)*53;
		x1=240;
		y1=160+(n)*53-1;
		SCREEN_DrawFilledRectangle(x0,y0,x1,y1, SCREEN_COLOR_WHITE);
	}
}

// to draw a pixel in a window (1, 2 or 3) in portrait
// x is the horizontal position of the pixel (0 to 240)
// y is the value of the vertical position in the window
// from 0 to ech (maximum value of y in the window)
void SPY_DrawPixel(int x, int y, int ech, int n){
	int i,j,col;
	// i--> 
	// j|
	switch(n){
		case 1:
			col=SCREEN_COLOR_BLACK;
			break;
		case 2:
			col=SCREEN_COLOR_RED;
			break;
		case 3:
			col=SCREEN_COLOR_BLACK;
			break;
		default:
			return;
	}
	if(x<0 || x>240)
		return;
	i=x;
	if(y<0 || y>ech)
		return;
	j=160+n*53-3-((y*50)/ech);
	SCREEN_DrawPixel(i,j,col);		
}

void SPY_Init(){
	//#25 #26 #27 #28
	//GPIO_InitTypeDef GPIO_InitStruct;

}

void TIM5_IRQHandler(void){

}

