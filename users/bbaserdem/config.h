#pragma once

// Unicode entry mode
#define UNICODE_SELECTED_MODES UC_LNX

// Tap dance settings
#define TAPPING_TERM 300
#define TAPPING_TOGGLE 1

// RGB light settings
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
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

