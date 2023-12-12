#include <reg51.h>

#define SSG_PORT P0

#define START_A 0x06
#define START_B 0x09
#define START_C 0x06
#define START_D 0x09

#define DAY_TIME 1
#define NIGHT_TIME 1 << 1
#define BUSY_TIME 1 << 2

sbit sw1=P2^7;
sbit sw2=P2^6;

sbit p20=P2^0;
sbit p21=P2^1;

sbit p22=P2^2;
sbit p23=P2^3;

sbit p25=P2^5;
sbit p24=P2^4;
sbit p30=P3^0;