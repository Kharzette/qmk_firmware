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

#include	"uthash.h"
#include	<string.h>

typedef struct	HSVPerKey_t
{
	uint16_t	key;
	hsv_t		color;

	UT_hash_handle	hh;
}	HSVPerKey;

//look up table for key type to color
HSVPerKey	*gpHSVLUT	=NULL;

void	AddHSV(uint16_t key, uint8_t h, uint8_t s, uint8_t v)
{
	HSVPerKey	*pNewVal	=malloc(sizeof(HSVPerKey));

	pNewVal->key		=key;
	pNewVal->color.h	=h;
	pNewVal->color.s	=s;
	pNewVal->color.v	=v;

	HASH_ADD_INT(gpHSVLUT, key, pNewVal);
}

void	keyboard_post_init_user(void)
{
	//gold modifierish keys
	AddHSV(KC_ESC, HSV_GOLD);
	AddHSV(KC_BSPC, HSV_GOLD);
	AddHSV(KC_TAB, HSV_GOLD);
	AddHSV(KC_ENT, HSV_GOLD);
	AddHSV(KC_LSFT, HSV_GOLD);
	AddHSV(KC_LCTL, HSV_GOLD);
	AddHSV(KC_LGUI, HSV_GOLD);
	AddHSV(KC_LALT, HSV_GOLD);
	AddHSV(MO(1), HSV_GOLD);
	AddHSV(MO(2), HSV_GOLD);

	//tealish alpha keys
	AddHSV(KC_A, HSV_TEAL);
	AddHSV(KC_B, HSV_TEAL);
	AddHSV(KC_C, HSV_TEAL);
	AddHSV(KC_D, HSV_TEAL);
	AddHSV(KC_E, HSV_TEAL);
	AddHSV(KC_F, HSV_TEAL);
	AddHSV(KC_G, HSV_TEAL);
	AddHSV(KC_H, HSV_TEAL);
	AddHSV(KC_I, HSV_TEAL);
	AddHSV(KC_J, HSV_TEAL);
	AddHSV(KC_K, HSV_TEAL);
	AddHSV(KC_L, HSV_TEAL);
	AddHSV(KC_M, HSV_TEAL);
	AddHSV(KC_N, HSV_TEAL);
	AddHSV(KC_O, HSV_TEAL);
	AddHSV(KC_P, HSV_TEAL);
	AddHSV(KC_Q, HSV_TEAL);
	AddHSV(KC_R, HSV_TEAL);
	AddHSV(KC_S, HSV_TEAL);
	AddHSV(KC_T, HSV_TEAL);
	AddHSV(KC_U, HSV_TEAL);
	AddHSV(KC_V, HSV_TEAL);
	AddHSV(KC_W, HSV_TEAL);
	AddHSV(KC_X, HSV_TEAL);
	AddHSV(KC_Y, HSV_TEAL);
	AddHSV(KC_Z, HSV_TEAL);

	//greenish symbols layer 0
	AddHSV(KC_SCLN, HSV_SPRINGGREEN);
	AddHSV(KC_COMM, HSV_SPRINGGREEN);
	AddHSV(KC_DOT, HSV_SPRINGGREEN);

	//greenish layer 1
	AddHSV(KC_SLSH, HSV_SPRINGGREEN);
	AddHSV(KC_EXLM, HSV_SPRINGGREEN);
	AddHSV(KC_AT, HSV_SPRINGGREEN);
	AddHSV(KC_HASH, HSV_SPRINGGREEN);
	AddHSV(KC_GRV, HSV_SPRINGGREEN);
	AddHSV(KC_TILD, HSV_SPRINGGREEN);
	AddHSV(KC_DLR, HSV_SPRINGGREEN);
	AddHSV(KC_PERC, HSV_SPRINGGREEN);
	AddHSV(KC_CIRC, HSV_SPRINGGREEN);
	AddHSV(KC_AMPR, HSV_SPRINGGREEN);
	AddHSV(KC_ASTR, HSV_SPRINGGREEN);
	AddHSV(KC_LPRN, HSV_SPRINGGREEN);
	AddHSV(KC_RPRN, HSV_SPRINGGREEN);

	//greenish layer 3
	AddHSV(KC_PMNS, HSV_SPRINGGREEN);
	AddHSV(KC_PEQL, HSV_SPRINGGREEN);
	AddHSV(KC_LBRC, HSV_SPRINGGREEN);
	AddHSV(KC_RBRC, HSV_SPRINGGREEN);
	AddHSV(KC_UNDS, HSV_SPRINGGREEN);
	AddHSV(KC_PPLS, HSV_SPRINGGREEN);
	AddHSV(KC_LCBR, HSV_SPRINGGREEN);
	AddHSV(KC_RCBR, HSV_SPRINGGREEN);
	AddHSV(KC_QUOT, HSV_SPRINGGREEN);
	AddHSV(KC_DQT, HSV_SPRINGGREEN);
	AddHSV(KC_BSLS, HSV_SPRINGGREEN);
	AddHSV(KC_PIPE, HSV_SPRINGGREEN);

	//arrows
	AddHSV(KC_UP, HSV_RED);
	AddHSV(KC_LEFT, HSV_RED);
	AddHSV(KC_DOWN, HSV_RED);
	AddHSV(KC_RIGHT, HSV_RED);

	//orange numpad
	AddHSV(KC_P1, HSV_ORANGE);
	AddHSV(KC_P2, HSV_ORANGE);
	AddHSV(KC_P3, HSV_ORANGE);
	AddHSV(KC_P4, HSV_ORANGE);
	AddHSV(KC_P5, HSV_ORANGE);
	AddHSV(KC_P6, HSV_ORANGE);
	AddHSV(KC_P7, HSV_ORANGE);
	AddHSV(KC_P8, HSV_ORANGE);
	AddHSV(KC_P9, HSV_ORANGE);
	AddHSV(KC_P0, HSV_ORANGE);
	AddHSV(KC_PPLS, HSV_ORANGE);
	AddHSV(KC_PENT, HSV_ORANGE);
	AddHSV(KC_PDOT, HSV_ORANGE);

	//ins home etc pink
	AddHSV(KC_INS, HSV_PINK);
	AddHSV(KC_HOME, HSV_PINK);
	AddHSV(KC_PGUP, HSV_PINK);
	AddHSV(KC_DEL, HSV_PINK);
	AddHSV(KC_END, HSV_PINK);
	AddHSV(KC_PGDN, HSV_PINK);

	//f keys
	AddHSV(KC_F1, HSV_CHARTREUSE);
	AddHSV(KC_F2, HSV_CHARTREUSE);
	AddHSV(KC_F3, HSV_CHARTREUSE);
	AddHSV(KC_F4, HSV_CHARTREUSE);
	AddHSV(KC_F5, HSV_CHARTREUSE);
	AddHSV(KC_F6, HSV_CHARTREUSE);
	AddHSV(KC_F7, HSV_CHARTREUSE);
	AddHSV(KC_F8, HSV_CHARTREUSE);
	AddHSV(KC_F9, HSV_CHARTREUSE);
	AddHSV(KC_F10, HSV_CHARTREUSE);
	AddHSV(KC_F11, HSV_CHARTREUSE);
	AddHSV(KC_F12, HSV_CHARTREUSE);

	//media keys
	AddHSV(KC_VOLU, 128, 128, 128);
	AddHSV(KC_MPLY, 128, 128, 128);
	AddHSV(KC_VOLD, 128, 128, 128);
	AddHSV(KC_MNXT, 128, 128, 128);

	//spaaaaaaaaace
	AddHSV(KC_SPC, HSV_BLUE);
}

void	LightUpLayer(uint8_t layer, uint8_t ledMin, uint8_t ledMax)
{
	for(uint8_t row=0;row < MATRIX_ROWS;row++)
	{
		for(uint8_t col=0;col < MATRIX_COLS;col++)
		{
			uint8_t	idx	=g_led_config.matrix_co[row][col];
			
			if(idx >= ledMin && idx < ledMax && idx != NO_LED)
			{
				int    key =keymap_key_to_keycode(layer, (keypos_t){col,row});
				
				HSVPerKey	*pHSV	=NULL;
				
				HASH_FIND_INT(gpHSVLUT, &key, pHSV);
				if(pHSV != NULL)
				{
					rgb_matrix_set_color(row * col,
						pHSV->color.h, pHSV->color.s, pHSV->color.v);
				}
			}
		}
	}
}

// clang-format on

