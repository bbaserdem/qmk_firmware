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
#include QMK_KEYBOARD_H
#include "bbaserdem.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Game pad
 * ,-----------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  | Ctl | Alt |  ~  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Tab |  Q  |  W  |  E  |  R  |  T  | |^| |  ;  |  '  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Shf |  A  |  S  |  D  |  F  | <-- | |v| | --> |  ,  |  .  |
 * `-----------------------------------------------------------'
 */
    LAYOUT_ortho_3x10(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,    KC_LCTL,KC_LALT,KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_UP,   KC_SCLN,KC_QUOT,KC_SLSH,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_LEFT,KC_DOWN, KC_RGHT,KC_COMM,KC_DOT
    )
};

void keyboard_post_init_keymap(void) {
    // Set RGB to rainbow mood light
    #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(120,255,255);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_RAINBOW_MOOD);
    #endif
    // Set backlight to a soft light
    #ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(1);
    breathing_enable();
    #endif
}
