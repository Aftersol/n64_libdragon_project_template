/**
 * @file state.h
 * @brief Definitions for state machine functions
 */

#ifndef __STATE_H
#define __STATE_H

#if __cplusplus
extern "C" {
#endif

#include "state0.h"
#include "state1.h"

// Define your state here
typedef enum State {
    STATE0,
    STATE1
} State;

void state_switch(State new_state);

#if __cplusplus
}
#endif

#endif
