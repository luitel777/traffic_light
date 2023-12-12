#include "traffic.h"
#include "controls.h"

void ext_int_0 () interrupt 0 {
	p20=0;
	p21=0;
	
	p22=0;
	p23=0;
	
	p24=1;
	
	
	p25=1;
	
	display2(5);
	P2=START_A;
	p25=0;

}
 //bankai! senbonzakura kageyoshi
void ext_int_1 () interrupt 2 {
	p20=0;
	p21=0;
	
	p22=0;
	p23=1;
	
	p24=1;
	p25=1;
	p23=1;
	
	display2(5);
	P2=START_A;
	p25=0;
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
			timing_interval = 15;
		}else if(P1 == NIGHT_TIME){
			timing_interval = 7;
		} else if(P1 == BUSY_TIME){
			timing_interval = 5;
		} else{
			timing_interval = 15;
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