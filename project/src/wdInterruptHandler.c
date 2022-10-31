#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  switch_state_Machine();
  if (blink_count++ == 10){ //blink faster 
    led_state_advance(); //when in the led state machine to blink back and forth
    blink_count = 0;
  }

  timeStateMachines();
}
