/**
 * @file state.h
 * @author You
 * @brief Definitions for state machine functions
 */

#ifndef __STATE_H
#define __STATE_H

#if __cplusplus
extern "C" {
#endif

#include "init.h"

#include "state0.h"
#include "state1.h"

// Define your state here
typedef enum State {
    INIT,
    STATE0,
    STATE1
} State;

/**
 * @brief Sets the new state and start cleaning up stuff from previous state
 */
void state_switch(State new_state);

#if __cplusplus
}
#endif

#endif
