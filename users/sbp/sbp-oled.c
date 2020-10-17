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
#include "sbp-oled.h"
//#include <stdio.h>
/* ROTARY ENCODER
 * This contains my general rotary encoder code
 * Encoders each have a list of different modes they can be in.
 * Each mode also have an on click action as well.
 * Modes can be cycled using either shift-click or ctrl-click
 * Modes can be reset using OS click
 * Some modes are only accessible through some keymap layers
 */  

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria r1.4\n"), false);
    oled_write_P(PSTR("WPM: "), false);
    char wpm_str[4];
    itoa(get_current_wpm(), wpm_str, 10);
    oled_write(wpm_str, false);
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _CHAR:
            oled_write_P(PSTR("Sp. Chars\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _MEDI:
            oled_write_P(PSTR("Media Ctr\n"), false);
            break;
        case _NAVI:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUMB:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Funct Keys\n"), false);
            break;
        case _MOUS:
            oled_write_P(PSTR("Mouse Keys\n"), false);
            break;
        case _MUSI:
            oled_write_P(PSTR("Music Mode\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    oled_write_P((get_mods() & MOD_MASK_SHIFT) ? PSTR("Sft ") : PSTR("    "), false);
    oled_write_P((get_mods() & MOD_MASK_CTRL ) ? PSTR("Ctl ") : PSTR("    "), false);
    oled_write_P((get_mods() & MOD_MASK_ALT  ) ? PSTR("Alt ") : PSTR("    "), false);
    oled_write_P((get_mods() & MOD_MASK_GUI  ) ? PSTR("Gui ") : PSTR("    "), false);
}

void oled_task_user(void) {
    render_status();
}
