#include <msp430.h>
#include "switches.h"
#include "led.h"

static int state1=0;
char switch_state_down, switch_state_changed;
static int variableLimit=4;
/* setup switches */
void 
switch_init()
{  
  P1REN |= SWITCHES;
  P1IE  |=  SWITCHES;             // enables resistors for switches
  P1OUT |= SWITCHES;		// enable interrupts from switches
  P1DIR &= ~SWITCHES;		// turn on switches so we can read them
	 
}

void firstState(void){

  static int count=0;
  count++;
  if(count >= variableLimit && state1==0){
    count=0;
    red_on=1-red_on;
    led_changed=1;
    led_update();
  }
}
void secondState(void){
  static int secondCount=0;
  secondCount++;
  if(secondCount >= variableLimit && state1==1){

    green_on= 1-green_on;
    led_changed=1;
    led_update();
  }
}

void switch_trigger(){

  if(state1 == 0){

    state1= 1;
  }
  else{

    state1= 0;
  }
}

