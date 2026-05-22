/**
 * @file init.h
 * @author You
 * @brief Declaration of initialization state functions for starting up the game
 */

#ifndef __INIT_H
#define __INIT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize initialization state
 */
void init_init(void);

/**
 * @brief Run initialization functions every tick
 */
void init_fixedloop(float deltaTime);

/**
 * @brief Run initialization functions every frame
 */
void init_loop(float deltaTime);

/**
 * @brief Cleanup stuff left by initialization
 */
void init_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif