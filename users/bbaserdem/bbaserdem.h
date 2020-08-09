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
#include "quantum.h"
/* Besides loading libraries and definitions, this file has my layout defs
 * LAYOUTS:
 *  This file has a couple layouts I use; so that the general changes can be
 *  propagated by only editing this file.
 */
// Macros to use, this has base level code so not affected by enabled features
#include "bb-macro.h"
// Audio from onboard speakers
#ifdef AUDIO_ENABLE
  #include "bb-audio.h"
#endif
// Underglow using rgb LEDs
#ifdef RGBLIGHT_ENABLE          
    #include "bb-underglow.h"
#endif
// Keycap backlight using non-rgb LEDs
#ifdef BACKLIGHT_ENABLE         
  #include "bb-backlight.h"
#endif
// Keycap backlight using rgb LEDs
#ifdef RGB_MATRIX_ENABLE
    #include "bb-keylight.h"
#endif
// Rotary encoder
#ifdef ENCODER_ENABLE  
    #include "bb-rotary.h"
#endif

// Function definitions that can be accessed through specific keymaps
// Runs before all initialization
void keyboard_pre_init_keymap(void);
// For code that launches once midway through initialization
void matrix_init_keymap(void);
// For code that launches after initialization is finished.
void keyboard_post_init_keymap(void);
// This code also launches on boot; but used after eeprom is available to write
void eeconfig_init_keymap(void);
// These will be delegated to keymap specific stuff (weak definition)
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
// This code runs on every tick
void matrix_scan_keymap(void);
// This code runs after every layer change
layer_state_t layer_state_set_keymap(layer_state_t state);
// This code runs when the default layer changes
layer_state_t default_layer_state_set_keymap (layer_state_t state);
// This code runs to set LED states
void led_set_keymap(uint8_t usb_led);
// For code that runs on suspend
void suspend_power_down_keymap(void);
void suspend_wakeup_init_keymap(void);
// For code that runs on powerdown
void shutdown_keymap(void);

/// Enumerate of layers
enum userspace_layers {
    _BASE = 0,  // Base layer
    _GAME,      // Game layer
    _NUMB,      // Numbers layer
    _SYMB,      // Symbols layer
    _FUNC,      // Function keys layer
    _NAVG,      // Navigation layer
    _MOUS,      // Mouse keys layer
    _MEDI,      // Media layer
    _MUSI,      // Music overlay
    _MIDI       // MIDI mode
};

// Use 7 wide characters for keymaps, to keep things aligned with 4 tabs
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// These defines allow multiple multi-parameter definitions to expand
// for these boards
#define LAYOUT_ortho_4x12_wrapper(...)      LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...)      LAYOUT_ortho_5x15(__VA_ARGS__)
#define LAYOUT_ortho_3x10_wrapper(...)      LAYOUT_ortho_3x10(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)     LAYOUT_split_3x6_3(__VA_ARGS__)

// Masks
#define ___1___ _______
#define ___3___ _______,_______,_______
#define ___5___ _______,_______,_______,_______,_______
#define ___6___ _______,_______,_______,_______,_______,_______
#define _xx1xx_ KC_NO
#define _xx3xx_ KC_NO,  KC_NO,  KC_NO
#define _xx5xx_ KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
#define _xx6xx_ KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
#define _xx1xx_ KC_NO
#define _xx3xx_ KC_NO,  KC_NO,  KC_NO
#define _xx5xx_ KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
#define _xx6xx_ KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO

// Quick macros
#define BB_UNDO    LCTL(KC_Z)
#define BB_REDO    LCTL(KC_Y)
#define BB_COPY    LCTL(KC_C)
#define BB_CUT     LCTL(KC_X)
#define BB_PSTE    LCTL(KC_V)

// Unicode keys
#ifdef UNICODEMAP_ENABLE
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
#else
#define TR_ACIR KC_A
#define TR_CCED KC_C
#define TR_GBRE KC_G
#define TR_ICIR KC_I
#define TR_I_NO KC_I
#define TR_IDOT KC_I
#define TR_ODIA KC_O
#define TR_SCED KC_S
#define TR_UCIR KC_U
#define TR_UDIA KC_U
#define BB_ELLI KC_NO
#define BB_PLNK KC_NO
#define BB_ANGS KC_NO
#define BB_PI   KC_NO
#define BB_BITC KC_NO
#endif

/* Base layout; Using DVORAK
 * ,-----------------------------.             ,-----------------------------.
 * | ' " | , < | . > |  P  |  Y  | ` ~     / ? |  F  |  G  |  C  |  R  |  L  |
 * |-----+-----+-----+-----+-----+             +-----+-----+-----+-----+-----+
 * |  A  |  O  |  E  |  U  |  I  | \ |     - _ |  D  |  H  |  T  |  N  |  S  |
 * |--o--+--o--+--o--+--o--+-----+             +-----+--o--+--o--+--o--+--o--+
 * | ; : |  Q  |  J  |  K  |  X  | < >     = + |  B  |  M  |  W  |  V  |  Z  |
 * `-----+--o--+-----+-----+-----+-----. ,-----+-----+-----+-----+-----+--o--'
 *                   | Esc |Space| Tab | |Enter|Bkspc| Del |
 *                   `--o-----o-----o--' `--o-----o-----o--'
 * The thing about this layout is that these will fit most boards I have.
 */
#define _BL1_5_ DV_QUOT,DV_COMM,DV_DOT, DV_P,   DV_Y
#define _BL1_1_ DV_GRV
#define _BR1_5_ DV_F,   DV_G,   DV_C,   DV_R,   DV_L
#define _BR1_1_ DV_GRV
#define _BL2_5_ DV_A,   DV_O,   DV_E,   DV_U,   DV_I
#define _BL2_1_ DV_BSLS
#define _BR2_5_ DV_D,   DV_H,   DV_T,   DV_N,   DV_S
#define _BR2_1_ DV_MINS
#define _BL3_5_ DV_SCLN,DV_Q,   DV_J,   DV_K,   DV_X
#define _BL3_1_ KC_NUBS
#define _BR3_5_ DV_B,   DV_M,   DV_W,   DV_V,   DV_Z
#define _BR3_1_ DV_EQL
#define _BL4_3_ 
#define _BR4_3_ 

/* Game layer; just assume dvorak here
 * ,-----------------------------.
 * |  Q  |  W  |  E  |  R  |  T  | ` ~
 * |-----+-----+-----+-----+-----+
 * |  A  |  S  |  D  |  F  |  G  | Tab
 * |-----+-----+-----+-----+-----+
 * |  Z  |  X  |  C  |  V  |  B  |Shift
 * `-----+-----+-----+-----+-----+-----.
 *                   | Esc |Space|Enter|
 *                   `--o-----o-----o--'
 */
#define _GA1_5_ KC_Q,   KC_W,   KC_E,   KC_R,   KC_T
#define _GA1_1_ KC_GRV
#define _GA2_5_ DV_A,   DV_S,   DV_D,   DV_F,   DV_G
#define _GA2_1_ KC_TAB
#define _GA3_5_ KC_Z,   KC_X,   KC_C,   KC_V,   KC_B
#define _GA3_1_ KC_LSFT
#define _GA4_3_ KC_ESC, KC_SPC, KC_ENT

/* Numbers layer
 * ,-----------------------------.
 * |  `  |  7  |  8  |  9  |  0  |
 * |-----+-----+-----+-----+-----|
 * | Mod |  4  |  5  |  6  | [ ] |
 * |--o--+--o--+--o--+--o--+-----|
 * |     |  1  |  2  |  3  | ( ) |
 * `-----+--o--+-----+-----+-----+-----.
 *                   |  0  |  [  |  ]  |
 *                   `--o-----o-----o--'
 */
#define _NU1_5_ DV_GRV, DV_7,   DV_8,   DV_9,   DV_0
#define _NU2_5_ _______,DV_4,   DV_5,   DV_6,   DBL_BRC
#define _NU3_5_ _xx1xx_,DV_1,   DV_2,   DV_3,   DBL_PAR
#define _NU4_3_ DV_0,   DV_LBRC,DV_RBRC

/* Symbols layer
 * ,-----------------------------.
 * |  ~  |  &  |  *  |  (  |  )  |
 * |-----+-----+-----+-----+-----|
 * | Mod |  $  |  %  |  ^  | { } |
 * |--o--+--o--+--o--+--o--+-----|
 * | ... |  !  |  @  |  #  | < > |
 * `-----+--o--+-----+-----+-----+-----.
 *                   |  )  |  {  |  }  |
 *                   `--o-----o-----o--'
 */
#define _SY1_5_ DV_TILD,DV_AMPR,DV_ASTR,DV_LPRN,DV_RPRN
#define _SY2_5_ XXXXXXX,DV_DLR, DV_PERC,DV_CIRC,DBL_CBR
#define _SY3_5_ BB_ELLI,DV_EXLM,DV_AT,  DV_HASH,DBL_ANG
#define _SY4_3_ DV_RPRN,DV_LCBR,DV_RCBR

/* Function layer
 * ,-----------------------------.
 * |PrScr| F07 | F08 | F09 | F10 |
 * |-----+-----+-----+-----+-----|
 * |CpsLk| F04 | F05 | F06 | F11 |
 * |--o--+--o--+--o--+--o--+-----|
 * |Break| F01 | F02 | F03 | F12 |
 * `-----+--o--+-----+-----+-----+-----.
 *                   | Esc |Space| Tab |
 *                   `--o-----o-----o--'
 */
#define _SY1_5_ KC_PSCR.KC_F7,  KC_F8,  KC_F9,  KC_10
#define _SY2_5_ KC_CAPS,KC_F4,  KC_F5,  KC_F6,  KC_11
#define _SY3_5_ KC_BRK, KC_F1,  KC_F2,  KC_F3,  KC_F12
#define _SY4_3_ KC_ESC, KC_SPC, KC_TAB

/* Navigation layer
 *       ,-----------------------------.
 *       |Redo |Undo |Yank | Cut |Paste|
 *       |-----+-----+-----+-----+-----|
 *       |CpsLk|  <  |  v  |  ^  |  >  |
 *       |-----+-----+-----+-----+-----|
 *       | Ins |Home |PgDwn|PgUp | End |
 * ,-----+-----+-----+-----+-----+-----'
 * |Enter|Bkspc| Del |
 * `-----------------'
 */
#define _NA1_5_ BB_REDO,BB_UNDO,BB_YANK,BB_CUT, BB_PSTE
#define _NA2_5_ KC_CAPS,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
#define _NA3_5_ KC_INS, KC_HOME,KC_PGDN,KC_PGUP,KC_END
#define _NA4_3_ KC_ENT, KC_BSPC,KC_DEL

/* Media layer
 *       ,-----------------------------.
 *  RGB: | Tog | Mod | Hue | Sat | Bri |
 *       |-----+-----+-----+-----+-----|
 *       |CpsLk|Prev.|VolDn|VolUp|Next |
 *       |-----+-----+-----+-----+-----|
 *  Led: | Tog |Brth.| Val | Spd | Vel |
 * ,-----+-----+-----+-----+-----+-----'
 * |Stop | Tog |VlOff|
 * `-----------------'
 */
#define _ME1_5_ RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI
#define _ME2_5_ KC_CAPS,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT
#define _ME3_5_ BL_TOGG,BL_BRTG,BL_STEP,RGB_SPD,VLK_TOG
#define _ME4_3_ KC_MSTP,KC_MPLY,KC_MUTE

/* Mouse layer
 *       ,-----------------------------.
 *       | Sp1 |     | Bt4 | Bt5 |RESET|
 *       |-----+-----+-----+-----+-----|
 *       | Sp2 | |<| | |v| | |^| | |>| |
 *       |-----+-----+-----+-----+-----|
 *       | Sp3 | <<< | vvv | ^^^ | >>> |
 * ,-----+-----+-----+-----+-----+-----'
 * |Right| Mid | Lft |
 * `-----------------'
 */
#define _MO1_5_ KC_ACL0,XXXXXXX,KC_BTN4,KC_BTN5,RESET
#define _MO2_5_ KC_ACL1,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
#define _MO3_5_ KC_ACL2,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R
#define _MO4_3_ KC_BTN1,KC_BTN2,KC_BTN3

/* Music layer: This is rotary encoder thing
 * ,------------------------------------------------------------------------.
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |.....|.....|.....|.....|.....|.....||.....|.....|.....|.....|.....|.....|
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * | Off | Rec |Stop |Play | Mod |.....||.....|.....|.....|.....|.....|.....|
 * `------------------------------------------------------------------------'
 */
// Rename music keys for readability
#ifdef AUDIO_ENABLE
#define MU_REC  KC_LCTL
#define MU_STOP KC_LALT
#define MU_PLAY KC_LGUI
#define MU_FAST KC_UP
#define MU_SLOW KC_DOWN
#define MU_MASK KC_NO
#else
#define MU_REC  KC_NO
#define MU_STOP KC_NO
#define MU_PLAY KC_NO
#define MU_FAST KC_NO
#define MU_SLOW KC_NO
#define MU_MASK KC_NO
#endif
#define _MUS_5_ MU_OFF, MU_REC, MU_STOP,MU_PLAY,MU_MOD
#define MU_MASK KC_A
