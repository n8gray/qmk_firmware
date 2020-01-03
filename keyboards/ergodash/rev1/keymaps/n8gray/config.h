/*
This is the c configuration file for the keymap

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


/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// When we use TT it should work with only 2 taps, not 5
#define TAPPING_TOGGLE 2

// The LEDs on the slave half go in reverse order
#define RGBLIGHT_LED_MAP { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, \
                          23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12}

// Try to get the rgb lights to turn off when the computer is sleeping. Doesn't seem to work reliably.
#define RGBLIGHT_SLEEP

// Enable lighting layers
#define RGBLIGHT_LAYERS
