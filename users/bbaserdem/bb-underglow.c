/*
Copyright 2020 Batuhan Başerdem <baserdem.batuhan@gmail.com> @bbaserdem
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
#include "sbp-underglow.h"
/* UNDERGLOW IMPLEMENTATION
 *  This is my underglow implementation
 *  I used to do this using constants and checking before.
 *  Now; the layer indicator is implemented in the RGB codebase.
 *  Switch this portion to use rgblight_set_layer_state functions
 */

// Set RGBLIGHT state depending on layer
layer_state_t layer_state_set_underglow(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    // rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    // rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}
