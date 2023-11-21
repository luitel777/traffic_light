static volatile unsigned int timing_interval = 5;

static char hexvalue[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void delay(unsigned int i);
void delay_ssg(unsigned int i);
void display(unsigned int timer);