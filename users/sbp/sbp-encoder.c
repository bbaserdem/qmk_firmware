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
#include "sbp-encoder.h"
/* ROTARY ENCODER
 * This contains my general rotary encoder code
 * Encoders each have a list of different modes they can be in.
 * Each mode also have an on click action as well.
 * Modes can be cycled using either shift-click or ctrl-click
 * Modes can be reset using OS click
 * Some modes are only accessible through some keymap layers
 */
//encoder_state_t encoder_state[NUMBER_OF_ENCODERS];
encoder_state_t encoder_state[2];
// Default state for the encoders
void reset_encoder_state(void) {
//    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    for (int i = 0; i < 2; i++) {
        encoder_state[i].base = i;
        encoder_state[i].rgb = i;
        encoder_state[i].point = i;
    }
}

// Initialize the encoder state beginning
void keyboard_post_init_encoder(void) {
    reset_encoder_state();
}

// Oled string printing for given layer and index; ONLY for OLED
#ifdef OLED_DRIVER_ENABLE
void oled_encoder_state_5char(uint8_t index, uint8_t layer) {
    // Get the layer straight from the main function
    switch (layer) {
        // If RGB control mode is enabled
        #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case _MEDI:
            switch (encoder_state[index].rgb) {
                case 0:
                    oled_write_P(PSTR(" mode"), false);
                    break;
                case 1:
                    oled_write_P(PSTR(" hue "), false);
                    break;
                case 2:
                    oled_write_P(PSTR("satur"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("value"), false);
                    break;
                case 4:
                    oled_write_P(PSTR("speed"), false);
                    break;
                default:
                    oled_write_P(PSTR("!oob!"), false);
                    break;
            }
            break;
        #endif
        // If pointer control is enabled
        #ifdef MOUSEKEY_ENABLE
        case _MOUS:
            switch (encoder_state[index].point) {
                case 0:
                    oled_write_P(PSTR("m.lat"), false);
                    break;
                case 1:
                    oled_write_P(PSTR("m.ver"), false);
                    break;
                case 2:
                    oled_write_P(PSTR("s.ver"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("s.lat"), false);
                    break;
                default:
                    oled_write_P(PSTR("!oob!"), false);
                    break;
            }
            break;
        #endif
        default:
            switch (encoder_state[index].base) {
                case 0:
                    oled_write_P(PSTR(" volm"), false);
                    break;
                case 1:
                    oled_write_P(PSTR(" song"), false);
                    break;
                case 2:
                    oled_write_P(PSTR(" sink"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("s.vol"), false);
                    break;
                case 4:
                    oled_write_P(PSTR(" src "), false);
                    break;
                case 5:
                    oled_write_P(PSTR(" L/R "), false);
                    break;
                case 6:
                    oled_write_P(PSTR(" U/D "), false);
                    break;
                case 7:
                    oled_write_P(PSTR("pgU/D"), false);
                    break;
                case 8:
                    oled_write_P(PSTR(" del "), false);
                    break;
                default:
                    oled_write_P(PSTR("!oob!"), false);
                    break;
            }
            break;
    }
}
#endif

// Encoder scroll functionality
void encoder_update_user(uint8_t index, bool clockwise) {
    // Differentiate layer roles
    switch (get_highest_layer(layer_state)) {
        #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case _MEDI:
            switch(encoder_state[index].rgb) {
                case 0: // Effect the RGB mode
                    if (clockwise) {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_step_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_step_noeeprom();
                        #endif
                    } else {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_step_reverse_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_step_reverse_noeeprom();
                        #endif
                    }
                    break;
                case 1: // Effect the RGB hue
                    if (clockwise) {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_increase_hue_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_increase_hue_noeeprom();
                        #endif
                    } else {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_decrease_hue_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_decrease_hue_noeeprom();
                        #endif
                    }
                    break;
                case 2: // Effect the RGB saturation
                    if (clockwise) {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_increase_sat_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_increase_sat_noeeprom();
                        #endif
                    } else {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_decrease_sat_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_decrease_sat_noeeprom();
                        #endif
                    }
                    break;
                case 3: // Effect the RGB brightness
                    if (clockwise) {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_increase_val_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_increase_val_noeeprom();
                        #endif
                    } else {
                        #ifdef RGBLIGHT_ENABLE
                        rgblight_decrease_val_noeeprom();
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_decrease_val_noeeprom();
                        #endif
                    }
                    break;
                case 4: // Effect the RGB effect speed
                    if (clockwise) {
                        #ifdef RGBLIGHT_ENABLE
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_increase_speed_noeeprom();
                        #endif
                    } else {
                        #ifdef RGBLIGHT_ENABLE
                        #endif
                        #ifdef RGB_MATRIX_ENABLE
                        rgb_matrix_decrease_speed_noeeprom();
                        #endif
                    }
                    break;
            }
            break;
        #endif
        #ifdef MOUSEKEY_ENABLE
        case _MOUS:
            switch(encoder_state[index].point) {
                case 0: // Move mouse on horizontal axis
                    if (clockwise) {
                        tap_code(KC_MS_R);
                    } else {
                        tap_code(KC_MS_L);
                    }
                    break;
                case 1: // Move mouse on vertical axis
                    if (clockwise) {
                        tap_code(KC_MS_D);
                    } else {
                        tap_code(KC_MS_U);
                    }
                    break;
                case 2: // Move mouse wheel on vertical axis
                    if (clockwise) {
                        tap_code(KC_WH_D);
                    } else {
                        tap_code(KC_WH_U);
                    }
                    break;
                case 3: // Move mouse on horizontal axis
                    if (clockwise) {
                        tap_code(KC_WH_R);
                    } else {
                        tap_code(KC_WH_L);
                    }
                    break;
            }
            break;
        #endif
        default:
            switch(encoder_state[index].base) {
                case 0: // Volume
                    if (clockwise) {
                        tap_code16(KC_VOLU);
                    } else {
                        tap_code16(KC_VOLD);
                    }
                    break;
                case 1: // Song change
                    if (clockwise) {
                        tap_code16(KC_MNXT);
                    } else {
                        tap_code16(KC_MPRV);
                    }
                    break;
                case 2: // Move to audio sink
                    if (clockwise) {
                        tap_code16(KC_F13);
                    } else {
                        tap_code16(S(KC_F13));
                    }
                    break;
                case 3: // Volume of source
                    if (clockwise) {
                        tap_code16(S(KC_VOLU));
                    } else {
                        tap_code16(C(KC_VOLD));
                    }
                    break;
                case 4: // Move to audio source
                    if (clockwise) {
                        tap_code16(C(KC_F13));
                    } else {
                        tap_code16(C(S(KC_F13)));
                    }
                    break;
                case 5: // Left-right
                    if (clockwise) {
                        tap_code16(KC_RGHT);
                    } else {
                        tap_code16(KC_LEFT);
                    }
                    break;
                case 6: // Up-down
                    if (clockwise) {
                        tap_code16(KC_DOWN);
                    } else {
                        tap_code16(KC_UP);
                    }
                    break;
                case 7: // Page Up-down
                    if (clockwise) {
                        tap_code16(KC_PGDN);
                    } else {
                        tap_code16(KC_PGUP);
                    }
                    break;
                case 8: // Delete 
                    if (clockwise) {
                        tap_code16(KC_DEL);
                    } else {
                        tap_code16(KC_BSPC);
                    }
                    break;
            }
            break;
    }
}

void encoder_click_action(uint8_t index) {
    // Differentiate layer roles
    switch (get_highest_layer(layer_state)) {
        #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case _MEDI:
            switch(encoder_state[index].rgb) {
                case 0: // Return to no animation
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                    #endif
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                    #endif
                    break;
                case 1:
                case 2:
                case 3: // Toggle
                    #ifdef RGBLIGHT_ENABLE
                    rgblight_increase_val_noeeprom();
                    #endif
                    #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_increase_val_noeeprom();
                    #endif
                    break;
                case 4: // Toggle velocikey
                    #ifdef VELOCIKEY_ENABLE
                    velocikey_toggle();
                    #endif
                    break;
            }
            break;
        #endif
        #ifdef MOUSEKEY_ENABLE
        case _MOUS:
            switch(encoder_state[index].point) {
                case 0: // Left click
                    tap_code16(KC_BTN1);
                    break;
                case 1: // Right click
                    tap_code16(KC_BTN2);
                    break;
                case 2:
                case 3: // Middle click
                    tap_code16(KC_BTN2);
                    break;
            }
            break;
        #endif
        default:
            switch(encoder_state[index].base) {
                case 0: // Toggle mute
                case 2:
                    tap_code16(KC_MUTE);
                    break;
                case 1: // Pause
                    tap_code16(KC_MPLY);
                    break;
                case 3: // Mute source
                case 4:
                    tap_code16(A(KC_MUTE));
                    break;
                case 5: // Insert
                    tap_code16(KC_INS);
                    break;
                case 6: // Capslock
                    tap_code16(KC_CAPS);
                    break;
                case 7: // Redo
                    tap_code16(BB_REDO);
                    break;
                case 8: // Undo
                    tap_code16(BB_UNDO);
                    break;
            }
            break;
    }
}

bool process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    // Check if and which encoder
    int encoder_index = -1;
    switch (keycode) {
        case BB_ENC0:
            encoder_index = 0;
            break;
        case BB_ENC1:
            encoder_index = 1;
            break;
    }
    // Activate encoder function of button
    if ((encoder_index >= 0) & (!record->event.pressed)) {
        // If shifted, move mode one point forward
        if (get_mods() & MOD_MASK_SHIFT) {
            switch (get_highest_layer(layer_state)) {
                #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
                case _MEDI:
                    encoder_state[encoder_index].rgb =
                        (encoder_state[encoder_index].rgb   + 1) % 5;
                    break;
                #endif
                #ifdef MOUSEKEY_ENABLE
                case _MOUS:
                    encoder_state[encoder_index].point =
                        (encoder_state[encoder_index].point + 1) % 4;
                    break;
                #endif
                default:
                    encoder_state[encoder_index].base =
                        (encoder_state[encoder_index].base  + 1) % 9;
                    break;
            }
        // If ctrl is active, move mode one point backwards
        } else if (get_mods() & MOD_MASK_CTRL) {
            switch (get_highest_layer(layer_state)) {
                #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
                case _MEDI:
                    encoder_state[encoder_index].rgb =
                        (encoder_state[encoder_index].rgb   + 5 - 1) % 5;
                    break;
                #endif
                #ifdef MOUSEKEY_ENABLE
                case _MOUS:
                    encoder_state[encoder_index].point =
                        (encoder_state[encoder_index].point + 4 - 1) % 4;
                    break;
                #endif
                default:
                    encoder_state[encoder_index].base =
                        (encoder_state[encoder_index].base  + 9 - 1) % 9;
                    break;
            }
        // If meta is active, reset the encoder states
        } else if (get_mods() & MOD_MASK_GUI) {
            reset_encoder_state();
        // If nothing else; just perform the click action
        } else {
            encoder_click_action(encoder_index);
        }
    }
    return true;
}
