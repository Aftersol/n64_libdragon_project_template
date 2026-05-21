/**
 * @file core.h
 * @author You
 * @brief Declarations of core functions
 */

#ifndef __CORE_H
#define __CORE_H

#if __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/* Functions that run when the state is changed */

/**
 * @brief Check program should start cleaning up
 * @return Whether the program should start cleaning up
 */
bool core_should_cleanup(void);

/** 
 * @brief Set when the program should start cleaning up after a frame
 * @param shall_cleanup Controls whether the program will start cleaning up 
 */
void core_set_should_cleanup(bool shall_cleanup);

/* Function pointers for core functions */

/**
 * @brief This function is called by __global_core_init to run user-defined
 * @brief initialization code upon start of the state.
 */
extern void (*core_init)(void);

/**
 * @brief This function is called by __global_core_fixedloop to run user-defined
 * @brief code every tick.
 */
extern void (*core_fixedloop)(float);

/**
 * @brief This function is called by __global_core_loop to run user-defined
 * @brief code every frame.
 */
extern void (*core_loop)(float);

/**
 * @brief This function is called by __global_core_cleanup to run user-defined
 * @brief cleanup code when the state changes.
 */
extern void (*core_cleanup)(void);

/* Internal Functions */

/**
 *  @brief Setup the state
 */
extern void __global_core_init(void);

/**
 *  @brief Loop that depends on frame rate
 */ 
extern void __global_core_fixedloop(void);

/**
 * @brief Loop that doesn't depend on frame rate
 * @param deltaTime delta time
 */
extern void __global_core_loop(void);

/**
 * @brief Cleanup stuff when the state changes
 */ 
extern void __global_core_cleanup(void);

/**
 * @brief Tickrate per second
 */
#define TICKRATE 15

/**
 * @brief Deltatime for running fixed loop functions
 */
#define __CORE_DELTATIME 1.0f / (float)TICKRATE

#if __cplusplus
}
#endif

#endif