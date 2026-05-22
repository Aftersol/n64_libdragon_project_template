/**
 * @file state.c
 * @author You
 * @brief Implementation of state machine functions
 */

#include "state.h"
#include "core.h"
#include "stdbool.h"

/**
 * @brief Enum for state machine functions
 */
typedef enum state_func_t{
    /**
     * @brief Index to initialization function
     */
    STATE_INIT = 0,

    /**
     * @brief Index to cleanup function
     */
    STATE_CLEANUP = 1,

    /**
     * @brief Index to fixed loop function
     */
    STATE_FIXED_LOOP = 0,

    /**
     * @brief Index to loop function
     */
    STATE_LOOP = 1
};

/**
 * @brief Jump table for running functions upon state change
 */
void (*state_void_jump_table[3][2])(void) = {
    {init_init, init_cleanup},
    {state0_init, state0_cleanup},
    {state1_init, state1_cleanup}
};

/**
 * @brief Jump table for loop functions
 */
void (*state_loop_jump_table[3][2])(float) = {
    {init_fixedloop, init_loop},
    {state0_fixedloop, state0_loop},
    {state1_fixedloop, state1_loop}
};

/**
 * @brief Sets the new state and start cleaning up stuff from previous state
 */
void state_switch(State new_state) {
    core_init = state_void_jump_table[new_state][STATE_INIT];
    core_cleanup = state_void_jump_table[new_state][STATE_CLEANUP];

    core_fixedloop = state_loop_jump_table[new_state][STATE_FIXED_LOOP];
    core_loop = state_loop_jump_table[new_state][STATE_LOOP];

    core_set_should_cleanup(false);
}
