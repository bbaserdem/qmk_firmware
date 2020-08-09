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

BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
AUDIO_ENABLE = no

# Planck light
ifneq (,$(findstring planck/light,$(KEYBOARD)))
    AUDIO_ENABLE = yes
    RGB_MATRIX_ENABLE = yes
endif

# Planck rev6
ifneq (,$(findstring planck/rev6,$(KEYBOARD)))
    AUDIO_ENABLE = yes
    RGBLIGHT_ENABLE = yes
endif
