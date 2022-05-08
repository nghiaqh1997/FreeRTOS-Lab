#ifndef FSM_FSM_H_
#define FSM_FSM_H_
#include "stdint.h"
extern uint16_t ledTimer;
void ledRedStateMachineUpdate(void);
void ledGreenStateMachineUpdate(void);
extern uint8_t redCounter;
extern uint8_t greenCounter;
extern uint8_t redFlag;
extern uint8_t greenFlag;
#endif
