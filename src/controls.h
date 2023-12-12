static volatile unsigned int timing_interval = 10;

static char hexvalue[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void delay(unsigned int i);
void delay_ssg(unsigned int i);

// these two function does exact same thing
// but both uses different registers when compiled
// so we don't overwrite old display timer when
// we use interrupt
void display(unsigned int timer);
void display2(unsigned int timer);