/**
 * @file state0.h
 * @author You
 * @brief Definitions for state0 functions
 */

#ifndef __STATE0_H
#define __STATE0_H

#if __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize state0
 */
void state0_init(void);

/**
 * @brief Run state0 functions every tick
 */
void state0_fixedloop(float deltaTime);

/**
 * @brief Run state1 functions every frame
 */
void state0_loop(float deltaTime);

/**
 * @brief Cleanup state0
 */
void state0_cleanup(void);

#if __cplusplus
}
#endif

#endif
