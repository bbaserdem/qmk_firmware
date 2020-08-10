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
#include "bb-keylight.h"
/* Code relating to per-key RGB LED stuff
 */

// These are keyboard, (and matrix), specific so they need to be defined there
// BUT these are made to take HSV arguments; so their color is controlled here
__attribute__ ((weak))
void keylight_set_left(uint8_t red, uint8_t green, uint8_t blue) { }
__attribute__ ((weak))
void keylight_set_right(uint8_t red, uint8_t green, uint8_t blue) { }

// Allow hooking into the RGB matrix indications using keymap code
__attribute__ ((weak)) void rgb_matrix_indicators_keymap(void) { }
// Set RGB state depending on layer
void rgb_matrix_indicators_keylight(void) {
    // Do each layer seperately
    switch (biton32(layer_state)) {
        case _CHAR:
            rgb_matrix_set_color_all(RGB_CHARTREUSE);
            break;
        case _GAME:
            keylight_set_left(RGB_PURPLE);
            break;
        case _FUNC:
            keylight_set_left(RGB_CORAL);
            break;
        case _NUMB:
            keylight_set_left(RGB_AZURE);
            break;
        case _SYMB:
            keylight_set_left(RGB_TURQUOISE);
            break;
        case _NAVI:
            keylight_set_right(RGB_GOLD);
            break;
        case _MEDI:
            keylight_set_right(RGB_TEAL);
            break;
        case _MOUS:
            keylight_set_right(RGB_SPRINGGREEN);
            break;
        case _MUSI:
            rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
        case _MIDI:
            rgb_matrix_set_color_all(RGB_GOLDENROD);
            break;
    }
    // Load keymap hooks
    rgb_matrix_indicators_keymap();
}

// Hook into shutdown code to make all perkey LED's red on hitting reset
void shutdown_keylight(void) {
    // Flash all the key LED's red on shutdown
    uint16_t timer_start = timer_read();
    rgb_matrix_set_color_all(RGB_RED);
    // Delay until this registers
    while(timer_elapsed(timer_start) < 250) {wait_ms(1);}
}

// Hook into suspend code
void suspend_power_down_keylight(void) {
    rgb_matrix_set_suspend_state(true);
}
void suspend_wakeup_init_keylight(void) {
    rgb_matrix_set_suspend_state(false);
}
