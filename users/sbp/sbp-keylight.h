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
#include "sbp.h"
/* Hooks involving perkey RGB LEDs
 */

// For custom indicators
void rgb_matrix_indicators_user(void);
// Hook into shutdown code
void shutdown_keylight(void);
void suspend_wakeup_init_keylight(void);
void suspend_power_down_keylight(void);
// These should be defined worst case on this file
void keylight_set_right(uint8_t red, uint8_t green, uint8_t blue);
void keylight_set_left(uint8_t red, uint8_t green, uint8_t blue);
