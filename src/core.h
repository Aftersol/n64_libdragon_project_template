/**
 * @file core.h
 * @brief Declarations of core functions
 */

#ifndef __CORE_H
#define __CORE_H

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

extern void (*core_init)(void);
extern void (*core_fixedloop)(float);
extern void (*core_loop)(float);
extern void (*core_cleanup)(void);

/* Internal Functions */

extern void __global_core_init(void);
extern void __global_core_fixedloop(void);
extern void __global_core_loop(void);
extern void __global_core_cleanup(void);

/**
 * @brief Tickrate per second
 */
#define TICKRATE = 15

/**
 * @brief Deltatime for running fixed loop functions
 */
#define __CORE_DELTATIME 1.0f / (float)TICKRATE

#endif // __CORE_HPP