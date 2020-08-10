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
#include "bbaserdem.h"
/* My song definitions and hooks
 */

/* Title:            People Vultures
 * Author/Composer:  King Gizzard & the Lizard Wizard
 */
#define PEOPLE_VULTURES \
    H__NOTE(_A3), H__NOTE(_G3), E__NOTE(_G3), QD_NOTE(_AS3),H__NOTE(_A3), \
    H__NOTE(_C4), H__NOTE(_D4), H__NOTE(_AS3),H__NOTE(_A3),

/* Title:            Wah Wah
 * Author/Composer:  King Gizzard & the Lizard Wizard
 */
#define WAH_WAH \
    QD_NOTE(_B2), QD_NOTE(_D3), Q__NOTE(_E3), Q__NOTE(_FS3), \
    QD_NOTE(_B2), QD_NOTE(_D3), Q__NOTE(_E3), Q__NOTE(_FS3), \
    S__NOTE(_A3), ED_NOTE(_B3), QD_NOTE(_A3), Q__NOTE(_GS3),Q__NOTE(_A3), \
    QD_NOTE(_B3), QD_NOTE(_A3), Q__NOTE(_GS3),Q__NOTE(_A3),

/* Title:            Big Fig Wasp
 * Author/Composer:  King Gizzard & the Lizard Wizard
 */
#define BIG_FIG_WASP \
    Q__NOTE(_E3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), \
    Q__NOTE(_E3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), \
    Q__NOTE(_E3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), \
    Q__NOTE(_E3), Q__NOTE(_D4), Q__NOTE(_B3), Q__NOTE(_A3),

/* Title:            Horology
 * Author/Composer:  King Gizzard & the Lizard Wizard
 */
#define HOROLOGY \
    Q__NOTE(_D4), Q__NOTE(_D3), Q__NOTE(_F4), Q__NOTE(_D3), Q__NOTE(_G4), Q__NOTE(_A4), Q__NOTE(_D3), \
    Q__NOTE(_D4), Q__NOTE(_D3), Q__NOTE(_F4), Q__NOTE(_D3), Q__NOTE(_C5), Q__NOTE(_A4), Q__NOTE(_D3), \
    Q__NOTE(_F4), Q__NOTE(_D3), Q__NOTE(_G4), Q__NOTE(_A4), Q__NOTE(_D3), Q__NOTE(_D4), Q__NOTE(_D3), \
    Q__NOTE(_F4), Q__NOTE(_D3), Q__NOTE(_G4), Q__NOTE(_F4), Q__NOTE(_D3),

/* Title:            Polygondwanaland
 * Author/Composer:  King Gizzard & the Lizard Wizard
 * Licence:          GPL
 */
#define POLYGONDWANALAND \
    HD_NOTE(_A2), H__NOTE(_D3), HD_NOTE(_C3), H__NOTE(_D3), \
    HD_NOTE(_G3), H__NOTE(_A3), HD_NOTE(_E3), H__NOTE(_D3),

/* Title:            Nonanon Infinity
 * Author/Composer:  King Gizzard & the Lizard Wizard
 */
#define NONAGON_INFINITY \
    E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), \
    E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), \
    E__NOTE(_A3), E__NOTE(_A3), E__NOTE(_B3), E__NOTE(_B3), Q__NOTE(_REST), \
    E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), \
    E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), E__NOTE(_B3), \
    E__NOTE(_DS4),E__NOTE(_DS4),E__NOTE(_DS4),E__NOTE(_D4),

// Define the song selections here
#define STARTUP_SONG    SONG(HOROLOGY)
#define GOODBYE_SONG    SONG(PEOPLE_VULTURES)
#define MUSIC_ON_SONG   SONG(NONAGON_INFINITY)
#define MUSIC_OFF_SONG  SONG(WAH_WAH)
#define GAME_ON_SONG    SONG(BIG_FIG_WASP)
#define GAME_OFF_SONG   SONG(POLYGONDWANALAND)

// Hook to layer change effects
layer_state_t layer_state_set_audio(layer_state_t state);

// Hook to audio keycodes
bool process_record_audio(uint16_t keycode, keyrecord_t *record);
