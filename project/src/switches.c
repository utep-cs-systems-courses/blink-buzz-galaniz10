#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

switch_state = 0;
char switch_state1,switch_state2,switch_state3,switch_state4, switch_changed_state;


 static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  switch_state1 = (p2val & SW1) ? 0 : 1; //defines each button 
  switch_state2 = (p2val & SW2) ? 0 : 1;
  switch_state3 = (p2val & SW3) ? 0 : 1;
  switch_state4 = (p2val & SW4) ? 0 : 1;

  //demo 10
  if (switch_state1) {
    switch_state = 1;
  }
  //demo 7
  if (switch_state2)
    switch_state = 2;

  //both leds on
  if (switch_state3)
    switch_state = 3;

  //buzzer
  if (switch_state4)
    switch_state = 4;

  switch_changed_state = 1; //making sure button was pressed
}
