/* 
 * File:   rotary_encoder_fsm.h
 * Author: d00d3
 *
 * Created on November 25, 2023, 7:48 PM
 */

#ifndef ROTARY_ENCODER_FSM_H
#define	ROTARY_ENCODER_FSM_H

#include <stdbool.h>
#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * List of possible detections for rotary-direction.
     */
    typedef enum ROTARY_ENCODER_FSM_DIRECTION {
        ROTARY_ENCODER_FSM_DIRECTION_UNKOWN = 0,
        ROTARY_ENCODER_FSM_DIRECTION_CLOCKWISE,
        ROTARY_ENCODER_FSM_DIRECTION_COUNTERCLOCKWISE,
    } rotary_encoder_fsm_direction_t;

    /**
     * List possible pin-states.
     */
    typedef enum ROTARY_ENCODER_FSM_PINS {
        ROTARY_ENCODER_FSM_PINS_LOW_LOW = 0b00,
        ROTARY_ENCODER_FSM_PINS_LOW_HIGH = 0b01,
        ROTARY_ENCODER_FSM_PINS_HIGH_LOW = 0b10,
        ROTARY_ENCODER_FSM_PINS_HIGH_HIGH = 0b11,
    } rotary_encoder_fsm_pins_t;

    /**
     * Record the state of a rotary-encoder.
     */
    typedef struct rotary_encoder_fsm_state_t {
        rotary_encoder_fsm_direction_t direction;
        rotary_encoder_fsm_pins_t pins;
    } rotary_encoder_fsm_state_t;

    /**
     * Callback function when successfully identified rotation
     * 
     * @param direction
     */
    typedef void (*_rotary_encoder_fsm_callback_t)(rotary_encoder_fsm_direction_t direction);

    /**
     * Detect rotary-direction by keeping a history for state of pin A and pin B
     * 
     * @param transitions
     * @param pin_a
     * @param pin_b
     * @return 
     */
    void rotary_encoder_fsm(rotary_encoder_fsm_state_t *rotary, bool pin_a, bool pin_b, _rotary_encoder_fsm_callback_t callback);

#ifdef	__cplusplus
}
#endif

#endif	/* ROTARY_ENCODER_FSM_H */

