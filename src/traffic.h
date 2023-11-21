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

sbit sw1=P2^7;
sbit sw2=P2^6;
