/*
Copyright 2019 Batuhan Başerdem <baserdem.batuhan@gmail.com> @bbaserdem
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "sbp-audio.h"

float tone_game[][2]    = SONG(GAME_ON_SONG);
float tone_return[][2]  = SONG(PEOPLE_VULTURES);
global uint8_t bb_game_flag = false;

// Audio playing when layer changes
uint32_t layer_state_set_audio(uint32_t state) {
    // Get this layer
    uint8_t current_layer = biton32(state);

    if (layer_state_cmp(state, _GAME)) {
        stop_all_notes();
        PLAY_SONG(GAME_ON_SONG);
    }

    return state;
}

// Audio layer switch; add the music layer on top of this
bool process_record_audio(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MU_TOG:
            if (record->event.pressed) {
                // On press, exit music mode if enabled
                if (layer_state_cmp(state, _MUSI)) {
                    layer_off(_MU);
                // If not enabled; turn off all layers and load music layer
                } else {
                    layer_clear();
                    layer_on(_MUSI);
                }
            }
            return true;
            break;
    }
    return true;
}
