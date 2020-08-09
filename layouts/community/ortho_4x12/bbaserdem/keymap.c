/*
 * Most of the code is in the "user" directory.
 * Check qmk_firmware/users/bbaserdem for the main part of the code
 */

#include "planck.h"
#include "bbaserdem.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Main layer
    [_BA] = LAYOUT_planck_wrapper(BASE),
    // Gaming layer
    [_GA] = LAYOUT_planck_wrapper(GAME),
    // Numbers layer
    [_NU] = LAYOUT_planck_wrapper(NUMBERS),
    // Settings layer
    [_SE] = LAYOUT_planck_wrapper(SETTINGS),
    // Mouse emulation layer
    [_MO] = LAYOUT_planck_wrapper(MOUSE),
    // Music mode
    [_MU] = LAYOUT_planck_wrapper(MUSIC),
};

/*---PLANCK LIGHT
 * This is left-right for planck light indicator light
 */
#ifdef RGB_MATRIX_ENABLE
// The LED 42 is for spacebar specifically
int planck_light_left[24] = {
     0,  1,  2,  3,  4,  5,
    12, 13, 14, 15, 16, 17,
    24, 25, 26, 27, 28, 29,
    36, 37, 38, 39, 40, 41};
int planck_light_right[24] = {
     6,  7,  8,  9, 10, 11,
    18, 19, 20, 21, 22, 23,
    30, 31, 32, 33, 34, 35,
    43, 44, 45, 46, 47, 48};
// Sided color-setting
void keylight_set_left(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < 24; i++) {
        rgb_matrix_set_color(planck_light_left[i], red, green, blue);
    }
}
void keylight_set_right(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < 24; i++) {
        rgb_matrix_set_color(planck_light_right[i], red, green, blue);
    }
}
#endif
