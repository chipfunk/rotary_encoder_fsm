#include "rotary_encoder_fsm.h"

void rotary_encoder_fsm(struct rotary_encoder_fsm_state_t *rotary_encoder, bool pin_a, bool pin_b, _rotary_encoder_fsm_callback_t callback) {
    switch (rotary_encoder->pins) {
        case ROTARY_ENCODER_FSM_PINS_HIGH_HIGH:
            if (!pin_a && pin_b) rotary_encoder->direction = ROTARY_ENCODER_FSM_DIRECTION_CLOCKWISE;
            if (pin_a && !pin_b) rotary_encoder->direction = ROTARY_ENCODER_FSM_DIRECTION_COUNTERCLOCKWISE;
            break;
        case ROTARY_ENCODER_FSM_PINS_HIGH_LOW:
            if (pin_a & pin_b & (rotary_encoder->direction == ROTARY_ENCODER_FSM_DIRECTION_CLOCKWISE)) {
                callback(rotary_encoder->direction);
                rotary_encoder->direction = ROTARY_ENCODER_FSM_DIRECTION_UNKOWN;
            }
            break;
        case ROTARY_ENCODER_FSM_PINS_LOW_HIGH:
            if (pin_a & pin_b & (rotary_encoder->direction == ROTARY_ENCODER_FSM_DIRECTION_COUNTERCLOCKWISE)) {
                callback(rotary_encoder->direction);
                rotary_encoder->direction = ROTARY_ENCODER_FSM_DIRECTION_UNKOWN;
            }
            break;
        case ROTARY_ENCODER_FSM_PINS_LOW_LOW:
            // No change
            break;
    }

    rotary_encoder->pins = pin_a;
    rotary_encoder->pins <<= 1;
    rotary_encoder->pins |= pin_b;
}
