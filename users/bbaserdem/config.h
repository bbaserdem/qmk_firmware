#pragma once

// Unicode entry mode
#define UNICODE_SELECTED_MODES UC_LNX

// Tap dance settings
#ifdef TAP_DANCE_ENABLE
    #define TAPPING_TERM 300
    #define TAPPING_TOGGLE 1
#endif

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
#endif
