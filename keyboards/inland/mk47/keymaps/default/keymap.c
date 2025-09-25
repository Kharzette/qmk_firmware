/* Copyright (C) 2023 jonylee@hfd
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_planck_mit(
		KC_ESC,		KC_Q,		KC_W,		KC_E,		KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,		KC_O,		KC_P,		KC_BSPC,
		KC_TAB,		KC_A,		KC_S,		KC_D,		KC_F,	KC_G,	KC_H,	KC_J,	KC_K,		KC_L,		KC_SCLN,	KC_ENT,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,		KC_UP,		KC_SLSH,
		KC_LCTL,	KC_LGUI,	KC_LALT,	KC_VOLU,	MO(2),	KC_SPC,			MO(1),	KC_MPLY,	KC_LEFT,	KC_DOWN,	KC_RGHT
	),

	[1] = LAYOUT_planck_mit(
		//numpad								//block of symbols												//upper right / left thumb
		KC_P7,	KC_P8,	KC_P9,		KC_PPLS,	KC_EXLM,	KC_AT,		KC_HASH,	KC_NO,		KC_NO,	KC_NO,	KC_GRV,	KC_TILD,
		KC_P4,	KC_P5,	KC_P6,		KC_PPLS,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,
		KC_P1,	KC_P2,	KC_P3,		KC_PENT,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_NO,	KC_NO, 	KC_NO,	KC_NO,
		KC_P0,	KC_P0,	KC_PDOT,	KC_PENT,	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_NO,	KC_NO,	KC_NO,	KC_NO
	),

	[2] = LAYOUT_planck_mit(
		//top left / right thumb									//moar symbols									//functions
		KC_INS,		KC_HOME,	KC_PGUP,	KC_NO,		KC_NO,		KC_PMNS,	KC_PEQL,	KC_LBRC,	KC_RBRC,	KC_F1,	KC_F2,	KC_F3,
		KC_DEL,		KC_END,		KC_PGDN,	KC_NO,		KC_NO,		KC_UNDS,	KC_PPLS,	KC_LCBR,	KC_RCBR,	KC_F4,	KC_F5,	KC_F6,
		KC_LSFT,	KC_LSFT,	KC_NO,		KC_NO,		KC_NO,		KC_QUOT,	KC_DQT,		KC_BSLS,	KC_PIPE,	KC_F7, 	KC_F8,	KC_F9,
		KC_LCTL,	KC_LGUI,	KC_LALT,	KC_VOLD,	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_MNXT,	KC_F10,	KC_F11,	KC_F12
	)
};

#ifndef RGB_MATRIX_ENABLE

//layer colours, oops these don't work with matrix
const rgblight_segment_t PROGMEM	myLayer0[]	=RGBLIGHT_LAYER_SEGMENTS(
	{	0, 1, HSV_GOLD	},			//esc gold
	{	1, 10, HSV_TEAL	},			//q to p teal
	{	11, 2, HSV_GOLD	},			//backspace and tab gold
	{	13, 9, HSV_TEAL	},			//a to l teal
	{	22, 1, HSV_SPRINGGREEN	},	//; green
	{	23, 2, HSV_GOLD	},			//return and shift gold
	{	25, 7, HSV_TEAL	},			//z to m teal
	{	32, 2, HSV_SPRINGGREEN	},	//, . green
	{	34, 1, HSV_RED	},			//uparrow red
	{	35, 1, HSV_SPRINGGREEN	},	//slash green
	{	36, 3, HSV_GOLD	},			//ctrl sup alt gold
	{	39, 1, 128, 128, 128	},	//volume up grey
	{	40, 1, HSV_GOLD	},			//L2 gold
	{	41, 1, HSV_BLUE	},			//spacebar blue
	{	42, 1, HSV_GOLD	},			//L1 gold
	{	43, 1, 128, 128, 128	},	//playpause grey
	{	44, 3, HSV_RED	}			//arrows red
);

const rgblight_segment_t PROGMEM	myLayer1[]	=RGBLIGHT_LAYER_SEGMENTS(
	{	0, 4, HSV_ORANGE	},		//numpad orange
	{	4, 3, HSV_SPRINGGREEN	},	//symbols green
	{	7, 3, HSV_OFF	},			//blank space
	{	10, 2, HSV_SPRINGGREEN	},	//` and ~ green in corner
	{	12, 4, HSV_ORANGE	},		//numpad orange
	{	16, 3, HSV_SPRINGGREEN	},	//symbols green
	{	19, 5, HSV_OFF	},			//blank space
	{	24, 4, HSV_ORANGE	},		//numpad orange
	{	28, 4, HSV_SPRINGGREEN	},	//symbols green
	{	32, 4, HSV_OFF	},			//blank space
	{	36, 4, HSV_ORANGE	},		//numpad orange
	{	40, 1, HSV_GOLD	},			//L2 gold
	{	41, 1, HSV_BLUE	},			//spacebar blue
	{	42, 1, HSV_GOLD	},			//L1 gold
	{	43, 4, HSV_OFF	}			//blank space
);

const rgblight_segment_t PROGMEM	myLayer2[]	=RGBLIGHT_LAYER_SEGMENTS(
	{	0, 3, HSV_PINK	},			//ins home etc
	{	3, 2, HSV_OFF	},			//blank space
	{	5, 4, HSV_SPRINGGREEN	},	//symbols green
	{	9, 3, HSV_CHARTREUSE	},	//F keys
	{	12, 3, HSV_PINK	},			//ins home etc
	{	15, 2, HSV_OFF	},			//blank space
	{	17, 4, HSV_SPRINGGREEN	},	//symbols green
	{	21, 3, HSV_CHARTREUSE	},	//F keys
	{	24, 2, HSV_GOLD	},			//big shift gold
	{	26, 3, HSV_OFF	},			//blank space
	{	29, 4, HSV_SPRINGGREEN	},	//symbols green
	{	33, 3, HSV_CHARTREUSE	},	//F keys
	{	36, 3, HSV_GOLD	},			//ctrl sup alt gold
	{	39, 1, 128, 128, 128	},	//volume up grey
	{	40, 1, HSV_GOLD	},			//L2 gold
	{	41, 1, HSV_BLUE	},			//spacebar blue
	{	42, 1, HSV_GOLD	},			//L1 gold
	{	43, 1, 128, 128, 128	},	//playpause grey
	{	44, 3, HSV_CHARTREUSE	}	//F keys
);

const rgblight_segment_t	*const	PROGMEM	myLayers[]	=RGBLIGHT_LAYERS_LIST(
	myLayer0, myLayer1, myLayer2);
#endif

// clang-format on

