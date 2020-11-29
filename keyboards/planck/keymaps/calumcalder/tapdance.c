#include <stddef.h>
#include "tapdance.h"
#include "process_tap_dance.h"

#include "audio.h"
#include "musical_notes.h"

float beep_song[][2] = SONG(Q__NOTE(_C5));


void tapdance_shiftcaps_finish(qk_tap_dance_state_t* state, void* user_data) {
    if (state->count == 3) {
        tap_code(KC_CAPS);
        PLAY_SONG(beep_song);
    } else {
        register_code(KC_LSHIFT);
    }
}

void tapdance_shiftcaps_reset(qk_tap_dance_state_t* state, void* user_data) {
    if (state->count != 3) {
        unregister_code(KC_LSHIFT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFTCAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdance_shiftcaps_finish, tapdance_shiftcaps_reset),
};

