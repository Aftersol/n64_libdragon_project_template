/**
 * @file state1.h
 * @brief Definitions for state1 functions
 */

#ifndef __STATE1_H
#define __STATE1_H

/**
 * @brief Initialize state1
 */
void state1_init(void);

/**
 * @brief Run state1 functions every tick
 */
void state1_fixedloop(float deltaTime);

/**
 * @brief Run state1 functions every frame
 */
void state1_loop(float deltaTime);

/**
 * @brief Cleanup state1
 */
void state1_cleanup(void);

#endif