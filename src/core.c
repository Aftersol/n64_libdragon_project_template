/**
 * @file core.c
 * @brief Implementation of core functions
 */

#include <libdragon.h>

#include "core.h"

/**
 * @brief Accmulated time between frames
 */
static float accumulator = 0.0f;
float frametime = 0.0f;

/**
 * @brief Variable for deltatime
 */
const static float dt = __CORE_DELTATIME;

/** 
 * @brief Flag for setting up cleanup when requested
 */ 
bool __should_cleanup = false;

/**
 * @brief Check program should start cleaning up
 * @return Whether the program should start cleaning up
 */
bool core_should_cleanup(void) {
    return __should_cleanup;
}

/** 
 * @brief Set when the program should start cleaning up after a frame
 * @param shall_cleanup Controls whether the program will start cleaning up 
 */
void core_set_should_cleanup(bool shall_cleanup) {
    __should_cleanup = shall_cleanup;
}

/**
 *  @brief Setup the state
 */
extern void __global_core_init(void) {
    accumulator = 0.0f;
    core_init();
    core_set_should_cleanup(false);
}

/**
 *  @brief Loop that depends on frame rate
 */ 
extern void __global_core_fixedloop(void) {
    frametime = display_get_delta_time();
    
    /* In order to prevent problems if the game slows down significantly,
     * we will clamp the maximum timestep the simulation can take */
    if (frametime > 0.25f)
        frametime = 0.25f;
    
    accumulator += frametime;
    
    while (accumulator >= __CORE_DELTATIME) {
        core_fixedloop(deltatime);
        accumulator -= __CORE_DELTATIME;
    }
}

/**
 * @brief Loop that doesn't depend on frame rate
 * @param deltaTime delta time
 */
extern void __global_core_loop(void) {
    joypad_poll();
    mixer_try_play();

    core_loop(frametime);
}

/**
 * @brief Cleanup stuff when the state changes
 */ 
extern void __global_core_cleanup(void) {
    core_cleanup();
}
