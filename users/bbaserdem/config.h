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
/* CONFIG
 * Common hardware configuration accross my boards
 */

// Unicode entry mode
#ifdef UNICODEMAP_ENABLE
    #define UNICODE_SELECTED_MODES UC_LNX
#endif

// Tap-hold settings
#define TAPPING_TERM 300
#define PERMISSIVE_HOLD

// Encoder settings
#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTION 4
#endif

// Backlight settings
#ifdef BACKLIGHT_ENABLE
    // Turn on breathing only if audio is not enabled, due to hardware stuff
    #ifndef AUDIO_ENABLE
        #define BACKLIGHT_BREATHING
        #define BREATHING_PERIOD 5
    #endif
#endif

// Enable RGB LED sleep mode
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
#endif

// Audio definitions
#ifdef AUDIO_ENABLE
    // Define songs
    #define STARTUP_SONG    SONG(HOROLOGY)
    #define GOODBYE_SONG    SONG(PEOPLE_VULTURES)
    #define MUSIC_ON_SONG   SONG(NONAGON_INFINITY)
    #define MUSIC_OFF_SONG  SONG(WAH_WAH)
    #define GAME_ON_SONG    SONG(BIG_FIG_WASP)
    #define GAME_OFF_SONG   SONG(POLYGONDWANALAND)
#endif

// For underglow light
#ifdef RGBLIGHT_ENABLE
    // Enable animations
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
    // Enable layer switching code
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_MAX_LAYERS 10
    // If these are not defined; just default to entire board for layer switch
    #ifndef RGBUNDERGLOW_LEFT_BEG
        #define RGBLIGHT_LEFT_BEG 0
    #endif
    #ifndef RGBUNDERGLOW_LEFT_NUM
        #define RGBLIGHT_LEFT_NUM RGBLED_NUM
    #endif
    #ifndef RGBUNDERGLOW_RIGHT_BEG
        #define RGBLIGHT_RIGHT_BEG 0
    #endif
    #ifndef RGBUNDERGLOW_RIGHT_NUM
        #define RGBLIGHT_RIGHT_NUM RGBLED_NUM
    #endif
#endif

// For perkey leds
#ifdef RGB_MATRIX_ENABLE
    // Start using this mode
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_BEACON
    #define RGB_MATRIX_STARTUP_HUE 100
    #define RGB_MATRIX_STARTUP_SAT 255
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    // Some config options
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_KEYRELEASES
    // Disable some animation modes
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define DISABLE_RGB_MATRIX_BAND_RAINDROPS
    #define DISABLE_RGB_MATRIX_BAND_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define DISABLE_RGB_MATRIX
#endif

