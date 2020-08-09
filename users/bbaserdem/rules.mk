# Copyright 2019 Batuhan Başerdem <baserdem.batuhan@gmail.com> @bbaserdem
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Common compilation flags
EXTRAFLAGS += -flto     # Used to make code smaller

# These should be enabled in all boards
EXTRAKEY_ENABLE = yes   # OS signals like volume control
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
TAP_DANCE_ENABLE = yes  # Tap dance keys
UNICODEMAP_ENABLE = yes # Used for unicode character emulation
VELOCIKEY_ENABLE = yes  # Modulate speed effects with typing speed
KEY_LOCK_ENABLE = yes   # Allows locking any key. Not used

# These should be disabled in all boards
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
BOOTMAGIC_ENABLE = no   # Access to EEPROM settings, not needed
CONSOLE_ENABLE = no     # Allows console output with a command
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
NKRO_ENABLE = no        # Default is 6KRO which is plenty
FAUXCLICKY_ENABLE = no  # Emulates clicks using speaker, who would want this?
API_SYSEX_ENABLE = no   # Allows OS to send signals.
BLUETOOTH_ENABLE = no   # I don't use bluetooth

# Manually configure these on each keyboard
# BACKLIGHT_ENABLE        # Switch LEDs
# RGBLIGHT_ENABLE         # LED strip
# RGB_MATRIX_ENABLE       # Per-key RGB LED
# AUDIO_ENABLE            # Audio stuff
# ENCODER_ENABLE          # Rotary encoder
# MIDI_ENABLE = no        # Midi driver (untested)

# Disabling this makes it compile, i dont know why
# VARIABLE_TRACE = no     # Allows debugging variables

# Userspace code
SRC += bbaserdem.c

# Macros
SRC += bb-macro.c

# Audio code
ifeq ($(strip $(AUDIO_ENABLE)), yes)
SRC += sbp-audio.c
endif

# Rotary encoder stuff
ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += sbp-rotary.c
endif

# Backlight code
ifeq ($(strip $(BACKLIGHT_ENABLE)), yes)
SRC += sbp-backlight.c
endif

# RGB LED Underglow code
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
SRC += sbp-underglow.c
endif

# RGB LED (Perkey) code
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
SRC += sbp-keylight.c
endif
