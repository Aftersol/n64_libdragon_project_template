/**
 * @file state.h
 * @brief Definitions for state machine functions
 */

#ifndef __STATE_H
#define __STATE_H

#include "state0.h"
#include "state1.h"

void (*state_void_jump_table[2][2])(void);

void (*state_loop_jump_table[2][2])(float);

// Define your state here
typedef enum State {
    STATE0,
    STATE1
} State;

void state_switch(State new_state);

#endif