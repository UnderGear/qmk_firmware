/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define SPLIT_TRANSPORT_MIRROR
#define USE_I2C

#define SPLIT_LAYER_STATE_ENABLE

#define EE_HANDS
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_CENTER { 127, 67 }

#define LTO_ENABLE

#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING
#define NO_MUSIC_MODE

#define SPLIT_OLED_ENABLE
#define OLED_IC OLED_IC_SSD1306
#define OLED_BRIGHTNESS 255
