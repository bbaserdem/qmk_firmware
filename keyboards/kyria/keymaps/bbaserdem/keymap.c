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
/* F layout
 * ┌───┬───┬───┬───┬───┬───┐                 ┌───┬───┬───┬───┬───┬───┐
 * │+ *│ F │ G │ Ğ │ I │ O │                 │ D │ R │ N │ H │ P │ Q │
 * ├───┼───┼───┼───┼───┼───┤                 ├───┼───┼───┼───┼───┼───┤
 * │ X │ A │ S │ D │ F │ G │                 │ T │ K │ M │ L │ Y │ Ş │
 * ├───┼───┼───┼───┼───┼───┼───┬───┐ ┌───┬───┼───┼───┼───┼───┼───┼───┤
 * │< >│ J │ Ö │ V │ C │ Ç │   │   │ │   │   │ Z │ S │ B │. :│, ;│ W │
 * └───┴───┴───┼───┼───┼───┤Tab│   │ │   │Ent├───┼───┼───┼───┴───┴───┘
 *             │En1│Esc│Spc│   │   │ │Ent│   │Bsp│Del│En2│
 *             └───┴───┴───┴───┴───┘ └───┴───┴───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        _BL1_1_,_BL1_5_,                _BR1_5_,_BR1_1_,
        _BL2_1_,_BL2_5_,                _BR2_5_,_BR2_1_,
        _BL3_1_,_BL3_5_,xxx2xxx,xxx2xxx,_BR3_5_,_BR3_1_,
        KC_MUTE,_BL4_3_,KC_NO,  KC_NO,  _BR4_3_,encoder
    ),
    [_GAME] = LAYOUT(
        _GA1_1_,_GA1_5_,                ___5___,___1___,
        _GA2_1_,_GA2_5_,                ___5___,___1___,
        _GA3_1_,_GA3_5_,xxx2xxx,xxx2xxx,___5___,___1___,
        encoder,_GA4_3_,KC_NO,  KC_NO,  ___3___,encoder
    ),
    [_FUNC] = LAYOUT(
        ___1___,_FU1_5_,                ___5___,___1___,
        ___1___,_FU2_5_,                ___5___,___1___,
        ___1___,_FU3_5_,xxx2xxx,xxx2xxx,___5___,___1___,
        encoder,_FU4_3_,KC_NO,  KC_NO,  ___3___,encoder
    ),
    [_NUMB] = LAYOUT(
        ___1___,_NU1_5_,                ___5___,___1___,
        ___1___,_NU2_5_,                ___5___,___1___,
        ___1___,_NU3_5_,xxx2xxx,xxx2xxx,___5___,___1___,
        encoder,_NU4_3_,KC_NO,  KC_NO,  ___3___,encoder
    ),
    [_SYMB] = LAYOUT(
        ___1___,_SY1_5_,                ___5___,___1___,
        ___1___,_SY2_5_,                ___5___,___1___,
        ___1___,_SY3_5_,xxx2xxx,xxx2xxx,___5___,___1___,
        encoder,_SY4_3_,KC_NO,  KC_NO,  ___3___,encoder
    ),
    [_NAVI] = LAYOUT(
        ___1___,___5___,                _NA1_5_,___1___,
        ___1___,___5___,                _NA2_5_,___1___,
        ___1___,___5___,xxx2xxx,xxx2xxx,_NA3_5_,___1___,
        encoder,___3___,KC_NO,  KC_NO,  _NA4_3_,encoder
    ),
    [_MEDI] = LAYOUT(
        ___1___,___5___,                _ME1_5_,___1___,
        ___1___,___5___,                _ME2_5_,___1___,
        ___1___,___5___,xxx2xxx,xxx2xxx,_ME3_5_,___1___,
        encoder,___3___,KC_NO,  KC_NO,  _ME4_3_,encoder
    ),
    [_MOUS] = LAYOUT(
        ___1___,___5___,                _MO1_5_,___1___,
        ___1___,___5___,                _MO2_5_,___1___,
        ___1___,___5___,xxx2xxx,xxx2xxx,_MO3_5_,___1___,
        encoder,___3___,KC_NO,  KC_NO,  _MO4_3_,encoder
    )
};
