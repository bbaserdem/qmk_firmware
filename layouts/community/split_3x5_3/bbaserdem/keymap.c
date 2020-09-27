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
 * ┌───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┐
 * │' "│, <│. >│ P │ Y │         │ F │ G │ C │ R │ L │
 * ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
 * │ A │ O │ E │ U │ I │         │ D │ H │ T │ N │ S │
 * ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
 * │; :│ Q │ J │ K │ X │         │ B │ M │ W │ V │ Z │
 * └───┴───┴───┼───┼───┼───┐ ┌───┼───┼───┼───┴───┴───┘
 *             │Tab│Ent│Esc│ │Del│Spc│Bsp│
 *             └───┴───┴───┘ └───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        _BL1_5_,_BR1_5_,
        _BL2_5_,_BR2_5_,
        _BL3_5_,_BR3_5_,
                _BL4_3_,_BR4_3_
    ),
    [_CHAR] = LAYOUT_split_3x6_3(
        _CL1_5_,_CR1_5_,
        _CL2_5_,_CR2_5_,
        _CL3_5_,_CR3_5_,
                _CL4_3_,_CR4_3_
    ),
    [_GAME] = LAYOUT_split_3x6_3(
        _GA1_5_,___5___,
        _GA2_5_,___5___,
        _GA3_5_,___5___,
                _GA4_3_,___3___
    ),
    [_NAVI] = LAYOUT_split_3x6_3(
        ___5___,_NA1_5_,
        ___5___,_NA2_5_,
        ___5___,_NA3_5_,
        ___3___,_NA4_3_
    ),
    [_NUMB] = LAYOUT_split_3x6_3(
        ___5___,_NU1_5_,
        ___5___,_NU2_5_,
        ___5___,_NU3_5_,
        ___3___,_NU4_3_
    ),
    [_SYMB] = LAYOUT_split_3x6_3(
        ___5___,_SY1_5_,
        ___5___,_SY2_5_,
        ___5___,_SY3_5_,
        ___3___,_SY4_3_
    ),
    [_MEDI] = LAYOUT_split_3x6_3(
        _ME1_5_,___5___,
        _ME2_5_,___5___,
        _ME3_5_,___5___,
        _ME4_3_,___3___
    ),
    [_FUNC] = LAYOUT_split_3x6_3(
        _FU1_5_,___5___,
        _FU2_5_,___5___,
        _FU3_5_,___5___,
        _FU4_3_,___3___
    ),
    [_MOUS] = LAYOUT_split_3x6_3(
        _MO1_5_,___5___,
        _MO2_5_,___5___,
        _MO3_5_,___5___,
        _MO4_3_,___3___
    ),
    [_MUSI] = LAYOUT_split_3x6_3(
        _MU_12_,_MU_12_,_MU_12_,
        _MUL_3_,_MUR_3_
    )
};

// RGB Matrix configuration
#ifdef RGB_MATRIX_ENABLE

// crkbd
#if defined(KEYBOARD_crkbd_rev1)
/* This is left-right for planck light indicator light
 *  - The LED 42 is for spacebar specifically, leave it out of the matrix
 *  - This is how it looks like
 * ┌──┬──┬──┬──┬──┐      ┌──┬──┬──┬──┬──┐
 * │23│18│17│10│09│      │33│34│41│42│47│
 * ├02┼──┼01┼──┼00┤      ├24┼──┼25┼──┼26┤
 * │22│19│16│11│08│      │32│35│40│43│46│
 * ├03┼──┼04┼──┼05┤      ├29┼──┼28┼──┼27┤
 * │21│20│15│12│07│      │31│36│39│44│45│
 * └──┴──┴──┼──┼──┼──┐┌──┼──┼──┼──┴──┴──┘
 *          │14│13│06││30│37│38│
 *          └──┴──┴──┘└──┴──┴──┘
 */
int board_left[24] = {
     0,  1,  2,  3,  4,  5,
     6,  7,  8,  9, 10, 11,
    12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23};
int board_right[24] = {
    27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38,
    39, 40, 41, 42, 43, 44,
    45, 46, 47, 48, 49, 50};
// Sided color-setting
void keylight_set_left(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < 24; i++) {
        rgb_matrix_set_color(board_left[i], red, green, blue);
    }
}
void keylight_set_right(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < 24; i++) {
        rgb_matrix_set_color(board_right[i], red, green, blue);
    }
}
// End of differentiations
#endif

// End of code for the RGB_MATRIX setup
#endif
