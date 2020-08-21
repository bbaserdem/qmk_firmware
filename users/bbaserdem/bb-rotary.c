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
#include "bb-rotary.h"
/* ROTARY ENCODER
 * This contains my general rotary encoder code
 * It is layer adaptive
 */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // First encoder
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _CHAR:
                // Base layer; adjusts volume
                //  This should correspond to either mute button;
                //  or music mode toggle if the board has audio
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _GAME:
                // Game layer; adjusts volume
                //  Keypress should correspond to muting
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _NAVI:
                // Navigation layer; move pointer up/down
                //  Keypress should correspond to leftclick
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_MS_D);
                } else {
                    tap_code(KC_MS_U);
                }
                #endif
                break;
            case _NUMB:
                // Number layer; move laterally
                //  Keypress should correspond to backspace
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case _SYMB:
                // Symbol layer; move vertically
                //  Keypress should correspond to backspace
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _MOUS:
                // Mouse layer; move pointer left/right
                //  Keypress should correspond to rightclick
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                }
                #endif
                break;
            case _MEDI:
                // Media layer; increase/decrease rgb brightness
                //  Keypress should toggle RGB light
                if (clockwise) {
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_increase_val();
                    #endif
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_increase_val_noeeprom();
                    #endif
                } else {
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_decrease_val_noeeprom();
                    #endif
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_decrease_val_noeeprom();
                    #endif
                }
                break;
            case _FUNC:
                // Function layer; scroll vertically
                //  Keypress should correspond to middle mouse button
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                #endif
                break;
            case _MUSI:
                // Audio layer; increase/decrease playback speed
                #ifdef AUDIO_ENABLE
                if (clockwise) {
                    tap_code(MU_FAST);
                } else {
                    tap_code(MU_SLOW);
                }
                #endif
                break;
        }
    } else if (index == 1) {
        // Second encoder
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _CHAR:
                // Base layer; scroll up and down using mousekey emulation
                //  Should correspond to middle mouse click
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _GAME:
                // Game layer; lateral movement
                //  Keypress should be forward arrow
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case _NAVI:
                // Navigation layer; move pointer left/right
                //  press should be rightclick
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                }
                #endif
                break;
            case _NUMB:
                // Number layer; move vertically
                //  Keypress should correspond to enter
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case _SYMB:
                // Symbol layer; insert space/delete characters
                //  Keypress should correspond to delete
                if (clockwise) {
                    tap_code(KC_SPC);
                } else {
                    tap_code(KC_BSPC);
                }
                break;
            case _MOUS:
                // Mouse layer; move pointer up/down
                //  Press should give some mouse button
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_MS_U);
                } else {
                    tap_code(KC_MS_D);
                }
                #endif
                break;
            case _MEDI:
                // Media layer; change RGB mode
                //  Press should default RGB to rainbow
                if (clockwise) {
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_step();
                    #endif
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_step_noeeprom();
                    #endif
                } else {
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_step_reverse();
                    #endif
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_step_reverse_noeeprom();
                    #endif
                }
                break;
            case _FUNC:
                // Function layer; scroll laterally
                //  Keypress should not correspond
                #ifdef MOUSEKEY_ENABLE
                if (clockwise) {
                    tap_code(KC_WH_R);
                } else {
                    tap_code(KC_WH_L);
                }
                #endif
                break;
            case _MUSI:
                // Audio layer; increase/decrease playback volume???
                //  on press; should change music mode
                #ifdef AUDIO_ENABLE
                if (clockwise) {
                    tap_code(MU_FAST);
                } else {
                    tap_code(MU_SLOW);
                }
                #endif
                break;
        }
    }
}
