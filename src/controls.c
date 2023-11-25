#include "controls.h"
#include "traffic.h"

void delay(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 1275; j++);
	}
}

void delay_ssg(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 80; j++);
	}
}


void display (unsigned int timer){
	unsigned int i = 0;
	while(i < timer){
		unsigned int j = 0;
		
		// do this 8 time per digit otherwise very fast
		for(j = 0; j < 8; j++){
			sw2  = 1; // display last digit
			sw1  = 0;
			SSG_PORT = hexvalue[timer % 10];
			
			// wait for some time to render on led
			delay_ssg(50);
			
			sw1  = 1; // display first digit
			sw2  = 0;
			SSG_PORT = hexvalue[timer / 10];
			
			// wait for some time to render on led + add few
			// delay to display the actual number
			delay_ssg(150);
		}
		timer--;
	}
}

void display2 (unsigned int timer){
	unsigned int i = 0;
	while(i < timer){
		unsigned int j = 0;
		
		// do this 8 time per digit otherwise very fast
		for(j = 0; j < 8; j++){
			sw2  = 1; // display last digit
			sw1  = 0;
			SSG_PORT = hexvalue[timer % 10];
			
			// wait for some time to render on led
			delay_ssg(50);
			
			sw1  = 1; // display first digit
			sw2  = 0;
			SSG_PORT = hexvalue[timer / 10];
			
			// wait for some time to render on led + add few
			// delay to display the actual number
			delay_ssg(150);
		}
		timer--;
	}
}