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
#include "bbaserdem.h"
#include "sendstring_dvorak.h"
/* This header file contains definitons regarding custom keycodes.
 * - Both regular and unicode macros are dealt with in this file
 */

// These will be delegated to keymap specific stuff (weak definition)
bool process_record_macro(uint16_t keycode, keyrecord_t *record);

// Make it so that keymaps can use KEYMAP_SAFE_RANGE for custom keycodes
#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

// Define short macros
#define BB_UNDO    LCTL(KC_Z)
#define BB_REDO    LCTL(KC_Y)
#define BB_COPY    LCTL(KC_C)
#define BB_CUT     LCTL(KC_X)
#define BB_PSTE    LCTL(KC_V)

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    BB_SAFE = PLACEHOLDER_SAFE_RANGE,
    // Double entry macros
    DBL_ANG,
    DBL_PAR,
    DBL_SQR,
    DBL_BRC,
    // Diagonal mouse movements
    #ifdef MOUSEKEY_ENABLE
    MO_NE,
    MO_NW,
    MO_SE,
    MO_SW,
    MO_S_NE,
    MO_S_NW,
    MO_S_SE,
    MO_S_SW,
    #endif
    // Macro key
    BB_PGPK,
    // Unicode strings
    #ifdef UNICODEMAP_ENABLE
    BB_LENY,
    BB_TABL,
    TR_FLAG,
    #endif
    //use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

// Unicodemap implementation
#ifndef UNICODEMAP_ENABLE
enum userspace_unicodemap {
    UPC_A_CIRC,
    UPC_C_CEDI,
    UPC_G_BREV,
    UPC_I_CIRC,
    UPC_I_DOTL,
    UPC_I_DOTT,
    UPC_O_DIAE,
    UPC_S_CEDI,
    UPC_U_CIRC,
    UPC_U_DIAE,
    LOW_A_CIRC,
    LOW_C_CEDI,
    LOW_G_BREV,
    LOW_I_CIRC,
    LOW_I_DOTL,
    LOW_I_DOTT,
    LOW_O_DIAE,
    LOW_S_CEDI,
    LOW_U_CIRC,
    LOW_U_DIAE,
    ELLIPSIS,
    PLANCK_CON,
    ANGSTROM,
    MATHPI,
    BITCOIN
};
#else
// Mask these keycodes if required features are not enabled
#define BB_LENY KC_NO
#define BB_TABL KC_NO
#define TR_FLAG KC_NO
#endif

// Mask the diagonal movement; if mousekeys are not enabled
#ifndef MOUSEKEY_ENABLE
#define MO_NE   KC_NO
#define MO_NW   KC_NO
#define MO_SE   KC_NO
#define MO_SW   KC_NO
#define MO_S_NE KC_NO
#define MO_S_NW KC_NO
#define MO_S_SE KC_NO
#define MO_S_SW KC_NO
#endif
