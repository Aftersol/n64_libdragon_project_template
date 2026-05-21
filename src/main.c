/**
 * @file main.c
 * @brief The entry point which initalizes all of the things for the program
 */

#include <libdragon.h>

#include <stdio.h>
#include <stdint.h>

#include "core.h"
#include "state.h"

/**
 * @brief The entrypoint of the program
 * @return Nothing because the program could never exit
 */
int main(void) {
    /* Init logging */
    debug_init_isviewer();
    debug_init_usblog();

    /* Startup controllers */
    joypad_init();

    /* Startup timer system */
    timer_init();

    /* Start up RDPQ */
    rdpq_init();

    /* Start up audio */
    audio_init(48000, 3);
    mixer_init(32);

    /* Set default state */
    state_switch(STATE0);

    /* Main loop */
    while (1) {
        __global_core_init();
        while (!core_should_cleanup()) {
            __global_core_fixedloop();
            __global_core_loop();
        }
        __global_core_cleanup();
    }
    
    return 0;
}
