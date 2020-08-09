# Manually configure these on each keyboard
# BACKLIGHT_ENABLE        # Switch LEDs
# RGBLIGHT_ENABLE         # LED strip
# RGB_MATRIX_ENABLE       # Per-key RGB LED
# AUDIO_ENABLE            # Audio stuff
# MIDI_ENABLE = no        # Midi driver (untested)

# These should be enabled in general
EXTRAKEY_ENABLE = yes   # OS signals like volume control
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
TAP_DANCE_ENABLE = yes  # Tap dance keys
UNICODEMAP_ENABLE = yes # Used for unicode character emulation
VELOCIKEY_ENABLE = yes  # Modulate speed effects with typing speed
KEY_LOCK_ENABLE = yes   # Allows locking any key. Not used

# These should be disabled in general
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
BOOTMAGIC_ENABLE = no   # Access to EEPROM settings, not needed
CONSOLE_ENABLE = no     # Allows console output with a command
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
NKRO_ENABLE = no        # Default is 6KRO which is plenty
FAUXCLICKY_ENABLE = no  # Emulates clicks using speaker, who would want this?
API_SYSEX_ENABLE = no   # Allows OS to send signals.
BLUETOOTH_ENABLE = no   # I don't use bluetooth

# Disabling this makes it compile, i dont know why
# VARIABLE_TRACE = no     # Allows debugging variables

EXTRAFLAGS += -flto     # Used to make code smaller

# Use the userspace code unless explicitly disabled
ifndef DISABLE_USERSPACE
  # Add the extra c files for compilation
  SRC += bb-macro.c
  ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += sbp-audio.c
  endif
  ifeq ($(strip $(BACKLIGHT_ENABLE)), yes)
    SRC += sbp-backlight.c
  endif
  ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += sbp-underglow.c
  endif
  ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += sbp-keylight.c
  endif
  # Userspace code
  SRC += bbaserdem.c
endif # DISABLE_USERSPACE
