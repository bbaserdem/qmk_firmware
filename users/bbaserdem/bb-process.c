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
/* PROCESS FILE
 * This file has my macros/unicodes
 * Hooks for other functionality to inject itself into the process_record
 */
#include "bb-process.h"

// Unicode definitions
const uint32_t PROGMEM unicode_map[] = {
    [ELLIPSIS]   = 0x2026,  // …
    [UPC_A_CIRC] = 0x00C2,  // Â
    [UPC_C_CEDI] = 0x00C7,  // Ç
    [UPC_G_BREV] = 0x011E,  // Ğ
    [UPC_I_CIRC] = 0x00CE,  // Î
    [UPC_I_DOTL] = 0x0049,  // I
    [UPC_I_DOTT] = 0x0130,  // İ
    [UPC_O_DIAE] = 0x00D6,  // Ö
    [UPC_S_CEDI] = 0x015E,  // Ş
    [UPC_U_CIRC] = 0x00DB,  // Û
    [UPC_U_DIAE] = 0x00DC,  // Ü
    [LOW_A_CIRC] = 0x00E2,  // â
    [LOW_C_CEDI] = 0x00E7,  // ç
    [LOW_G_BREV] = 0x001F,  // ğ
    [LOW_I_CIRC] = 0x00EE,  // î
    [LOW_I_DOTL] = 0x0131,  // ı
    [LOW_I_DOTT] = 0x0069,  // i
    [LOW_O_DIAE] = 0x00F6,  // ö
    [LOW_S_CEDI] = 0x015F,  // ş
    [LOW_U_CIRC] = 0x00FB,  // û
    [LOW_U_DIAE] = 0x00FC,  // ü
    [PLANCK_CON] = 0x210F,  // ℏ
    [ANGSTROM]   = 0x212B,  // Å
    [MATHPI]     = 0x03C0,  // π
    [BITCOIN]    = 0x20BF   // ₿
};

// Unicode shortcuts for turkish lower-upper case letters
#define TR_ACIR XP(LOW_A_CIRC, UPC_A_CIRC)
#define TR_CCED XP(LOW_C_CEDI, UPC_C_CEDI)
#define TR_GBRE XP(LOW_G_BREV, LOW_G_BREV)
#define TR_ICIR XP(LOW_I_CIRC, LOW_I_CIRC)
#define TR_I_NO XP(LOW_I_DOTL, LOW_I_DOTL)
#define TR_IDOT XP(LOW_I_DOTT, LOW_I_DOTT)
#define TR_ODIA XP(LOW_O_DIAE, LOW_O_DIAE)
#define TR_SCED XP(LOW_S_CEDI, LOW_S_CEDI)
#define TR_UCIR XP(LOW_U_CIRC, LOW_U_CIRC)
#define TR_UDIA XP(LOW_U_DIAE, LOW_U_DIAE)
#define BB_ELLI X(ELLIPSIS)
#define BB_PLNK X(PLANCK_CON)
#define BB_ANGS X(ANGSTROM)
#define BB_PI   X(MATHPI)
#define BB_BITC X(BITCOIN)

// Weak defines to hook into the main process_record
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // Keymap custom keycodes
    return true;
}
__attribute__ ((weak))
bool process_record_audio(uint16_t keycode, keyrecord_t *record) {
    // Audio functionality
    return true;
}
__attribute__ ((weak))
bool process_record_mouse(uint16_t keycode, keyrecord_t *record) {
    // Extra mouse controller buttons
    return true;
}
__attribute__ ((weak))
bool process_record_keylight(uint16_t keycode, keyrecord_t *record) {
    // RGB Perkey light hooks
    return true;
}

// Keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Special macros
    switch (keycode) {
        case BB_PGPK:
            // My public PGP key
            if (record->event.pressed) {
                SEND_STRING("0B7151C823559DD8A7A04CE36426139E2F4C6CCE");
            }
            return false; break;
        case TR_FLAG:
            // Turkish flag
            if (record->event.pressed) {
                send_unicode_string("🇹🇷");
            }
            return false; break;
        case BB_LENY:
            // Lenny face
            if (record->event.pressed) {
                send_unicode_string("( ͡° ͜ʖ ͡°)");
            }
            return false; break;
        case BB_TABL:
            // Table flip
            if (record->event.pressed) {
                send_unicode_string("┻━┻︵ \\(°□°)/ ︵ ┻━┻");
            }
            return false; break;
        case DBL_ANG:
            // Double angular bracket
            if (record->event.pressed) {
                SEND_STRING("<>"SS_TAP(X_LEFT));
            }
            return false; break;
        case DBL_PAR:
            // Double paranthesis
            if (record->event.pressed) {
                SEND_STRING("()"SS_TAP(X_LEFT));
            }
            return false; break;
        case DBL_SQR:
            // Double square brackets
            if (record->event.pressed) {
                SEND_STRING("[]"SS_TAP(X_LEFT));
            }
            return false; break;
        case DBL_BRC:
            // Double curly brackets
            if (record->event.pressed) {
                SEND_STRING("{}"SS_TAP(X_LEFT));
            }
            return false; break;
    }
    // Return after running through all individual hooks
    return process_record_keymap(keycode, record)   &&
    process_record_audio(keycode, record)           &&
    process_record_mouse(keycode, record);
}
