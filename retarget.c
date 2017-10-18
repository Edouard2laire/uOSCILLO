// FOR STUDENTS
// retarget.c
// version 29/08/2017

#include <stdio.h>

#include "stm32f429_Discovery_conf.h"
// to use fonts from SCREEN_fonts
extern unsigned short int SCREEN_Font11x18[];
extern SCREEN_FontDef_t SCREEN_FormatFont_11x18;
// insert your own global variables here to manage the cursor
int posCursor_x=0;
int posCursor_y=0;

struct __FILE
{
  int handle;
  /* Whatever you require here. If the only file you are using is */
  /* standard output using printf() for debugging, no file handling */
  /* is required. */
};
/* FILE is typedef’d in stdio.h. */
FILE __stdout;

int fputc(int ch, FILE *f) {
  /* Your implementation of fputc(). */
	// #23 improve the code to display more characters
	//#23: you can modify the condition to display more characters
		if( (ch>='a' && ch <='z') || (ch>='A' && ch <='Z') ||
     (ch>='0' && ch <='9') ){
					//#23: you can modify the colors
					SCREEN_putc(posCursor_x, posCursor_y, (char) ch, &SCREEN_FormatFont_11x18, SCREEN_COLOR_BLUE, SCREEN_COLOR_YELLOW);
					//#23: you can modify the values 15: this is the width between 2 characters
					posCursor_x=(posCursor_x+15)%240;
			}

	return ch;
}

int ferror(FILE *f)
{
  /* Your implementation of ferror(). */
  return 0;
}

// #23 it can be useful to set the position in your main application
void set_cursor(int x, int y){
	posCursor_x=x;
	posCursor_y=y;
}

void set_cursor_y(int y){
	posCursor_y=y;
}

