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
/* LAYOUTS:
 *  This file has a couple layouts I use; so that the general changes can be
 *  propagated by only editing this file.
 */

// Use 7 wide characters for keymaps, to keep things aligned with 4 tabs
#define _______ KC_TRNS
#define XXX     KC_NO

// These defines allow multiple multi-parameter definitions to expand
// for these boards
#define LAYOUT_ortho_4x12_wrapper(...)      LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...)      LAYOUT_ortho_5x15(__VA_ARGS__)
#define LAYOUT_planck_wrapper(...)          LAYOUT_planck_grid(__VA_ARGS__)

/* Base layout; Using DVORAK
 * ,------------------------------------ ------------------------------------.
 * | = + | ' " | , < | . > |  P  |  Y  | |  F  |  G  |  C  |  R  |  L  |     |
 * |-----+-----+-----+-----+-----+-----+ +-----+-----+-----+-----+-----+-----|
 * | ? / |  A  |  O  |  E  |  U  |  I  | |  D  |  H  |  T  |  N  |  S  | - _ |
 * |-----+--o--+--o--+--o--+--o--+-----+ +-----+--o--+--o--+--o--+--o--+-----|
 * | \ | | ; : |  Q  |  J  |  K  |  X  | |  B  |  M  |  W  |  V  |  Z  | < > |
 * |-----+--o--+-----+-----+-----+-----+ +-----+-----+-----+-----+--o--+-----|
 *                   | Esc |Space| Tab | |Enter|Bkspc| Del |
 *                   `--o-----o-----o--' `--o-----o-----o--'
 * The thing about this layout is that these will fit most boards I have.
 */

#define __BASE_ROW1_LEFT_6__ \
    KC_EQL, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC, \
    KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, \
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,  \
    KC_RALT,KC_LCTL,KC_LGUI,KC_LALT,K_NU_GA,KC_SPC, KC_SPC, K_SE_MO,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT

/* Game layer
 * ,------------------------------------------------------------------------.
 * |     |     |     |     |     |     ||     |     |     |  ^  |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     ||     |     |  <  |  v  |  >  |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     ||     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |            |     |     |     |     |     |
 * `------------------------------------------------------------------------'
 */
#define GAME \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_UP,  _______,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______

/* Symbols layer
 * ,------------------------------------------------------------------------.
 * |     | ` ~ | Del | Ins | Home| End ||Pg Dn|Pg Up| __ | - _ | = + |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     | 1 ! | 2 @ | 3 # | 4 $ | 5 % || 6 ^ | 7 & | 8 * | 9 ( | 0 ) | / ? |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     | < > | `` | '' | () | <> || [] | {} | "" | [ { | ] } |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |            |CapsL|     |     |     |     |
 * `------------------------------------------------------------------------'
 */
#define NUMBERS \
    _______,KC_GRV, KC_DEL, KC_INS, KC_HOME,KC_END, KC_PGDN,KC_PGUP,DBL_USC,KC_MINS,KC_EQL, _______, \
    _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSLS, \
    _______,KC_NUBS,XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    XXX,    KC_LBRC,KC_RBRC,_______, \
    _______,_______,_______,_______,_______,_______,_______,KC_CAPS,_______,_______,_______,_______

/* Settings layer
 * ,------------------------------------------------------------------------.
 * |     |  F1 |  F2 |  F3 |  F4 | Lin || Woke| Blt |Brthg| Mode| Tog |Reset|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  F5 |  F6 |  F7 |  F8 | Win ||PrtSc| Lira|Hue +|Sat +|Bri +|     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  F9 | F10 | F11 | F12 |Vol -||Vol +| BTC |Hue -|Sat -|Bri -|     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | MUS |    Mute    |     | Prev| Stop|TogMu| Next|
 * `------------------------------------------------------------------------'
 */
#define SETTINGS \
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  UC_M_LN,KC_WAKE,BL_STEP,BL_BRTG,RGB_MOD,RGB_TOG,RESET,   \
    _______,KC_F5,  KC_F6,  KC_F7,  KC_F8,  UC_M_WC,KC_PSCR,CUR_LIR,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI, \
    _______,KC_F9,  KC_F10, KC_F11, KC_F12, KC_VOLD,KC_VOLU,CUR_BIT,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD, \
    _______,_______,_______,_______,MU_TOG, KC_MUTE,KC_MUTE,_______,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT

/* Mouse layer
 * ,------------------------------------------------------------------------.
 * |Ulock|  \  |  ^  |  /  | Sec | Sec || Sec | Sec | |\|.| |^| | |/|.|     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  <  |.....|  >  |Btn L|Btn 4||Btn 5|Btn R| <-- |.....| --> |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  /  |  v  |  \  |.....|.....||.....|.....| |/| | |v| | |\| |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | LCK |   MidClk   |     |Accl0|Accl1|Accl2|     |
 * `------------------------------------------------------------------------'
 */
#define MOUSE \
    _______,MO_NW,  MO_N,   MO_NE,  SECRET1,SECRET2,SECRET3,SECRET4,MO_S_NW,MO_S_N, MO_S_NE,_______, \
    _______,MO_W,   XXX,    MO_E,   MO_CL_L,MO_CL_4,MO_CL_5,MO_CL_R,MO_S_W, XXX,    MO_S_E, _______, \
    _______,MO_SW,  MO_S,   MO_SE,  XXX,    XXX    ,XXX,    XXX,    MO_S_SW,MO_S_S, MO_S_SE,_______, \
    _______,_______,_______,_______,K_LOCK, MO_CL_M,MO_CL_M,_______,MO_AC_0,MO_AC_1,MO_AC_2,_______

/* Music layer
 * ,------------------------------------------------------------------------.
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * | slow| fast| rec | stop| togg|    Play    | Mode|.....|.....|.....|.....|
 * `------------------------------------------------------------------------'
 */
#define MUSIC \
    MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK, \
    MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK, \
    MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK,MU_MASK, \
    MU_SLOW,MU_FAST,MU_REC, MU_STOP,MU_TOG, MU_PLAY,MU_PLAY,MU_MOD, MU_MASK,MU_MASK,MU_MASK,MU_MASK

