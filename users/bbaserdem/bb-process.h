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
/* This header file contains definitons regarding custom keycodes
 */

// Make it so that keymaps can use KEYMAP_SAFE_RANGE for custom keycodes
#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    // Safe stuff
    BB_SAFE = PLACEHOLDER_SAFE_RANGE,
    // Double entry macros
    DBL_ANG,
    DBL_PAR,
    DBL_SQR,
    DBL_BRC,
    // Diagonal mouse movements
    MO_NE,
    MO_NW,
    MO_SE,
    MO_SW,
    MO_S_NE,
    MO_S_NW,
    MO_S_SE,
    MO_S_SW,
    // Macro key
    BB_PGPK,
    // Unicode strings
    BB_LENY,
    BB_TABL,
    TR_FLAG,
    //use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

// Define functions unique to each feature; so their process record
// can be seperated and organized accross different functions

// These will be delegated to keymap specific stuff (weak definition)
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Unicodemap implementation
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
