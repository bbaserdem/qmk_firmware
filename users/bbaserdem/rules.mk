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
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
EXTRAKEY_ENABLE = yes   # OS signals like volume control
UNICODEMAP_ENABLE = yes # Used for unicode character emulation
KEY_LOCK_ENABLE = yes   # Allows locking any key. Not used in general
TAP_DANCE_ENABLE = yes 	# Tap dance keys; i don't use tap dance but I use tap-hold
VELOCIKEY_ENABLE = no   # Modulate speed effects with typing speed

# These should be disabled in all boards
BOOTMAGIC_ENABLE = no   # Access to EEPROM settings, not needed
CONSOLE_ENABLE = no     # Allows console output with a command
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
NKRO_ENABLE = no        # Default is 6KRO which is plenty
MIDI_ENABLE = no        # Midi driver (untested)
UNICODE_ENABLE = no 	# We use unicodemap, not unicode
UCIS_ENABLE = no 	# We use unicodemap, not ucis
FAUXCLICKY_ENABLE = no  # Emulates clicks using speaker, who would want this?
VARIABLE_TRACE = no     # Allows debugging variables
API_SYSEX_ENABLE = no   # Allows OS to send signals.

# Manually configure these on each keyboard individually
# BLUETOOTH_ENABLE        # For bluetooth
# AUDIO_ENABLE            # Audio stuff
# BACKLIGHT_ENABLE        # Switch LEDs
# RGBLIGHT_ENABLE         # LED strip
# RGB_MATRIX_ENABLE       # Per-key RGB LED
# ENCODER_ENABLE          # Rotary encoder

# Disabling this makes it compile, i dont know why

# Userspace code
SRC += bbaserdem.c

# Macros
SRC += bb-macro.c

# Audio code
ifeq ($(strip $(AUDIO_ENABLE)), yes)
SRC += bb-audio.c
endif

# Rotary encoder stuff
ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += bb-rotary.c
endif

# Backlight code
ifeq ($(strip $(BACKLIGHT_ENABLE)), yes)
SRC += bb-backlight.c
endif

# RGB LED Underglow code
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
SRC += bb-underglow.c
endif

# RGB LED (Perkey) code
ifneq ($(strip $(RGB_MATRIX_ENABLE)),)
    ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
	SRC += bb-keylight.c
    endif
endif
