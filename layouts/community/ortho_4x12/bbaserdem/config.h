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
#pragma once

// Code pertaining to planck rev6
#if defined(KEYBOARD_planck_rev6)
    // RGB Matrix with daughter board

    #ifdef RGB_MATRIX_ENABLE
        /*
        // Reconfigure the RGB DI Pin
        #ifdef RGB_DI_PIN
        #undef RGB_DI_PIN
        #endif
        // Change this later
        #define RGB_DI_PIN A1
        // Reconfigure number of LEDS
        #ifdef DRIVER_LED_TOTAL
        #undef DRIVER_LED_TOTAL
        #endif
        #define DRIVER_LED_TOTAL 48
        //*/
    #endif
    // RGB Underglow with on-board SMD footprints
    #ifdef RGBLIGHT_ENABLE
        // This is for original planck led locations
        // ┌────────────┐
        // │ 6  5  4  3 │
        // │            │
        // │     0      │
        // │ 7  8  1  2 │
        // └────────────┘
        #define RGBLIGHT_LEFT_BEG 5
        #define RGBLIGHT_LEFT_NUM 4
        #define RGBLIGHT_RIGHT_BEG 1
        #define RGBLIGHT_RIGHT_NUM 4
    #endif
#endif

// Let's Split Eh! specific
#ifdef KEYBOARD_lets_split_eh_eh
    #define RGBLIGHT_LEFT_BEG 0
    #define RGBLIGHT_LEFT_NUM 6
    #define RGBLIGHT_RIGHT_BEG 6
    #define RGBLIGHT_RIGHT_NUM 6
#endif

// JJ40 specific
#ifdef KEYBOARD_planck_rev6
    #define RGBLIGHT_LEFT_BEG 0
    #define RGBLIGHT_LEFT_NUM 2
    #define RGBLIGHT_RIGHT_BEG 3
    #define RGBLIGHT_RIGHT_NUM 2
#endif
