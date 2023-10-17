#include <reg51.h>

#define SSG_PORT P0

#define START_A 0x09
#define START_B 0x06
#define START_C 0x09
#define START_D 0x06
#define CROSSWALK 0x00 // Fixme: 0x00 sets all bits to 0 which puts crosswalk bit to 0 as well kekw
sbit cross = P2 ^4;

#define DAY_TIME 1
#define NIGHT_TIME 1 << 1
#define BUSY_TIME 1 << 2
#define PEASANT_WALK 1 << 3

#define MAX 10


sbit sw1=P2^6;
sbit sw2=P2^7;

int counter_1;

char hexvalue[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//char hexvalue[MAX] = {0x6F,0x7F,0x07,0x7D,0x6D,0x66,0x4F,0x5B,0x06,0x3F};
char cnt=20;
int i;

void delay(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 1275; j++);
	}
}

void delay_ssg(unsigned int i){
	unsigned int j = 0, k = 0;
	for(k = 0; k < i; k++){
		for(j = 0; j < 100; j++);
	}
}


int timing_interval = 2;

void display (unsigned int time){
	unsigned int b = time;
	for(i=0;i<=b;i++){
		int j = 0;
		for(j = 0; j < 7; j++){
			delay_ssg(50);
			SSG_PORT = hexvalue[b % 10];
			sw1  = 1;
			sw2  = 0;
		
			SSG_PORT = hexvalue[b%10];
			delay_ssg(50);
			sw2  = 1;
			sw1  = 0;

			SSG_PORT = hexvalue[b / 10];
			delay_ssg(50);;
		}
		b--;
	}
}


void ext_int_0 () interrupt 0 {
	P2 = START_A;
	display(4);

}
 
void ext_int_1 () interrupt 2 {
	P2 = START_B;
	display(4);
}


int main(){
	cross = 0;
	P2 = 0x00;
	P1 = 0x0FF;
	P3 |= 0x0c; // Configure the INT0 & INT1 pins as Inputs
    EX0 = 1;    // Enable INT0
    EX1 = 1;    // Enable INT1
    EA  = 1;    // Enable Global Interrupt bit
	
	
	while(1){
		
		if(P1 == DAY_TIME){
			timing_interval = 1;
		}else if(P1 == NIGHT_TIME){
			timing_interval = 2;
		} else if(P1 == BUSY_TIME){
			timing_interval = 3;
		} else{
			timing_interval = 2;
		}

		SSG_PORT = 0xFF;
		P0 = 0xFF;
		
		if(P1 == PEASANT_WALK){
			//P2 = CROSSWALK;
			cross = 1;
			display(3);
		}
		
		P2 = START_A;
		display(timing_interval);
		P2 = START_B;
		display(timing_interval);
		P2 = START_C;
		display(timing_interval);
		P2 = START_D;
		display(timing_interval);
		

	}
	
}
