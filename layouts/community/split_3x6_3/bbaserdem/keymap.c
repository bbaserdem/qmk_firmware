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
 * ┌───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┐
 * │+ *│ F │ G │ Ğ │ I │ O │         │ D │ R │ N │ H │ P │ Q │
 * ├───┼───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┼───┤
 * │ X │ A │ S │ D │ F │ G │         │ T │ K │ M │ L │ Y │ Ş │
 * ├───┼───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┼───┤
 * │< >│ J │ Ö │ V │ C │ Ç │         │ Z │ S │ B │. :│, ;│ W │
 * └───┴───┴───┴───┼───┼───┼───┐ ┌───┼───┼───┼───┴───┴───┴───┘
 *                 │Esc│Spc│Tab│ │Ent│Bsp│Del│
 *                 └───┴───┴───┘ └───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        _BL1_1_,_BL1_5_,_BR1_5_,_BR1_1_,
        _BL2_1_,_BL2_5_,_BR2_5_,_BR2_1_,
        _BL3_1_,_BL3_5_,_BR3_5_,_BR3_1_,
        _BL4_3_,_BR4_3_
    ),
    [_GAME] = LAYOUT_split_3x6_3(
        _GA1_1_,_GA1_5_,___6___,
        _GA2_1_,_GA2_5_,___6___,
        _GA3_1_,_GA3_5_,___6___,
        _GA4_3_,___3___
    ),
    [_FUNC] = LAYOUT_split_3x6_3(
        xxx1xxx,_FU1_5_,___6___,
        xxx1xxx,_FU2_5_,___6___,
        xxx1xxx,_FU3_5_,___6___,
        _FU4_3_,___3___
    ),
    [_NUMB] = LAYOUT_split_3x6_3(
        xxx1xxx,_NU1_5_,___6___,
        xxx1xxx,_NU2_5_,___6___,
        xxx1xxx,_NU3_5_,___6___,
        _NU4_3_,___3___
    ),
    [_SYMB] = LAYOUT_split_3x6_3(
        xxx1xxx,_SY1_5_,___6___,
        xxx1xxx,_SY2_5_,___6___,
        xxx1xxx,_SY3_5_,___6___,
        _SY4_3_,___3___
    ),
    [_NAVI] = LAYOUT_split_3x6_3(
        ___6___,_NA1_5_,xxx1xxx,
        ___6___,_NA2_5_,xxx1xxx,
        ___6___,_NA3_5_,xxx1xxx,
        ___3___,_NA4_3_
    ),
    [_MEDI] = LAYOUT_split_3x6_3(
        ___6___,_ME1_5_,xxx1xxx,
        ___6___,_ME2_5_,xxx1xxx,
        ___6___,_ME3_5_,xxx1xxx,
        ___3___,_ME4_3_
    ),
    [_MOUS] = LAYOUT_split_3x6_3(
        ___6___,_MO1_5_,xxx1xxx,
        ___6___,_MO2_5_,xxx1xxx,
        ___6___,_MO3_5_,xxx1xxx,
        ___3___,_MO4_3_
    )
};
