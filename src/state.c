/**
 * @file state.c
 * @author You
 * @brief Implementation of state machine functions
 */

#include "state.h"
#include "core.h"
#include "stdbool.h"

/**
 * @brief Jump table for running functions upon state change
 */
void (*state_void_jump_table[2][2])(void) = {
    {state0_init, state0_cleanup},
    {state1_init, state1_cleanup}
};

/**
 * @brief Jump table for loop functions
 */
void (*state_loop_jump_table[2][2])(float) = {
    {state0_fixedloop, state0_loop},
    {state1_fixedloop, state1_loop}
};

/**
 * @brief Sets the new state and start cleaning up stuff from previous state
 */
void state_switch(State new_state) {
    core_init = state_void_jump_table[new_state][0];
    core_cleanup = state_void_jump_table[new_state][1];

    core_fixedloop = state_loop_jump_table[new_state][0];
    core_loop = state_loop_jump_table[new_state][1];

    core_set_should_cleanup(false);
}
