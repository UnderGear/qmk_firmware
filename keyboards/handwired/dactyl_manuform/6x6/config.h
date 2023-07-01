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


#define USE_I2C

#define SPLIT_LAYER_STATE_ENABLE

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 14
#define MATRIX_COLS 6

// wiring of each half
// I reversed the columns when wiring the left side
//#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2, B6 }

// switched from COL2ROW for my amoeba PCBs
#define DIODE_DIRECTION ROW2COL

#define EE_HANDS
