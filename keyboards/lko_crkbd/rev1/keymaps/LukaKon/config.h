/*
Copyright 2019 @foostan
Copyright 2023 @asdfire1

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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE //Enable WPM across split keyboards (+268).
#define NO_ACTION_ONESHOT
#define SPLIT_OLED_ENABLE

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
