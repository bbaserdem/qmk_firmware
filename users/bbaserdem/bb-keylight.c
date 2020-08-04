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

// These are keyboard, and matrix, specific so they need to be defined there
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
    switch ( biton32(layer_state) ) {
        case _GAME:
            keylight_set_left(RGB_PURPLE);
            break;
        case _NUMB:
            keylight_set_left(RGB_TEAL);
            break;
        case _SYMB:
            keylight_set_left(RGB_PINK);
            break;
        case _FUNC:
            keylight_set_left(RGB_GOLD);
            break;
        case _NAVG:
            keylight_set_right(RGB_SPRINGGREEN);
            break;
        case _MOUS:
            keylight_set_right(RGB_AZURE);
            break;
        case _MEDI:
            keylight_set_right(RGB_CORAL);
            break;
        case _MUSI:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case _MIDI:
            rgb_matrix_set_color_all(RGB_TURQUOISE);
            break;
    }
    // Load keymap hooks
    rgb_matrix_indicators_keymap();
}

// Hook into shutdown code to make perkey LED's red on shutdown
void shutdown_keylight(void) {
    // Flash all the key LED's red on shutdown
    uint16_t timer_start = timer_read();
    rgb_matrix_set_color_all( 0xFF, 0x00, 0x00 );
    while(timer_elapsed(timer_start) < 250) {wait_ms(1);}
}
