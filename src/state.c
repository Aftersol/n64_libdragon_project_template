/**
 * @file state.c
 * @brief Implementation of state machine functions
 */

#include "state.h"
#include "core.h"
#include "stdbool.h"

void state_switch(State new_state) {
    core_init = state_void_jump_table[0][new_state];
    core_cleanup = state_void_jump_table[1][new_state];

    core_fixedloop = state_loop_jump_table[0][new_state];
    core_loop = state_loop_jump_table[1][new_state];

    core_set_should_cleanup(false);
}