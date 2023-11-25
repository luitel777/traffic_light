#include "traffic.h"
#include "controls.h"

void ext_int_0 () interrupt 0 {
	int a = P2;
	P2 = 0x10;
	display2(5);
	P2 = a;
}
 
void ext_int_1 () interrupt 2 {
	int a = P2;
	P2 = 0x10;
	delay(5);
	P2 = a;
}


int main(){
	P2 = 0x00;
	P1 = 0x0FF;
	
	P3 |= 0x0c; // Configure the INT0 & INT1 pins as Inputs
  EX0 = 1;    // Enable INT0
  EX1 = 1;    // Enable INT1
  EA  = 1;    // Enable Global Interrupt bit
	
	
	while(1){
		if(P1 == DAY_TIME){
			timing_interval = 10;
		}else if(P1 == NIGHT_TIME){
			timing_interval = 7;
		} else if(P1 == BUSY_TIME){
			timing_interval = 5;
		} else{
			timing_interval = 10;
		}

		SSG_PORT = 0xFF;
		P0 = 0xFF;
		
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