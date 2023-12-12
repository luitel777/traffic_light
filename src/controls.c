#include "controls.h"
#include "traffic.h"

#define constant_time 1

void delay(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 1275; j++);
	}
}

void delay_ssg(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 50 + constant_time; j++);
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
		
		// NOTE: IDK BUT 5 is 3 actktyally
		// basically x-2 idfk
		if(timer < 5){
			p20=0;
			p21=0;
			p22=0;
			p23=0;
			p25=1;
			p30=1;
			
		}else{
			p25=0;
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