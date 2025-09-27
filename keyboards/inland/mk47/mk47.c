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

#include "quantum.h"
#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t PROGMEM g_snled27351_leds[SNLED27351_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, CB4_CA1,   CB5_CA1,   CB6_CA1},
    {0, CB4_CA2,   CB5_CA2,   CB6_CA2},
    {0, CB4_CA3,   CB5_CA3,   CB6_CA3},
    {0, CB4_CA4,   CB5_CA4,   CB6_CA4},
    {0, CB4_CA5,   CB5_CA5,   CB6_CA5},
    {0, CB4_CA6,   CB5_CA6,   CB6_CA6},
    {0, CB4_CA7,   CB5_CA7,   CB6_CA7},
    {0, CB4_CA8,   CB5_CA8,   CB6_CA8},
    {0, CB4_CA9,   CB5_CA9,   CB6_CA9},
    {0, CB4_CA10,  CB5_CA10,  CB6_CA10},
    {0, CB4_CA11,  CB5_CA11,  CB6_CA11},
    {0, CB4_CA12,  CB5_CA12,  CB6_CA12},

    {0, CB7_CA1,   CB8_CA1,   CB9_CA1},
    {0, CB7_CA2,   CB8_CA2,   CB9_CA2},
    {0, CB7_CA3,   CB8_CA3,   CB9_CA3},
    {0, CB7_CA4,   CB8_CA4,   CB9_CA4},
    {0, CB7_CA5,   CB8_CA5,   CB9_CA5},
    {0, CB7_CA6,   CB8_CA6,   CB9_CA6},
    {0, CB7_CA7,   CB8_CA7,   CB9_CA7},
    {0, CB7_CA8,   CB8_CA8,   CB9_CA8},
    {0, CB7_CA9,   CB8_CA9,   CB9_CA9},
    {0, CB7_CA10,  CB8_CA10,  CB9_CA10},
    {0, CB7_CA11,  CB8_CA11,  CB9_CA11},
    {0, CB7_CA12,  CB8_CA12,  CB9_CA12},

    {0, CB10_CA1,   CB11_CA1,   CB12_CA1},
    {0, CB10_CA2,   CB11_CA2,   CB12_CA2},
    {0, CB10_CA3,   CB11_CA3,   CB12_CA3},
    {0, CB10_CA4,   CB11_CA4,   CB12_CA4},
    {0, CB10_CA5,   CB11_CA5,   CB12_CA5},
    {0, CB10_CA6,   CB11_CA6,   CB12_CA6},
    {0, CB10_CA7,   CB11_CA7,   CB12_CA7},
    {0, CB10_CA8,   CB11_CA8,   CB12_CA8},
    {0, CB10_CA9,   CB11_CA9,   CB12_CA9},
    {0, CB10_CA10,  CB11_CA10,  CB12_CA10},
    {0, CB10_CA11,  CB11_CA11,  CB12_CA11},
    {0, CB10_CA12,  CB11_CA12,  CB12_CA12},

    {0, CB10_CA13,  CB11_CA13,  CB12_CA13},
    {0, CB10_CA14,  CB11_CA14,  CB12_CA14},
    {0, CB10_CA15,  CB11_CA15,  CB12_CA15},
    {0, CB10_CA16,  CB11_CA16,  CB12_CA16},
    {0, CB4_CA13,  CB5_CA13,  CB6_CA13},
    {0, CB4_CA14,  CB5_CA14,  CB6_CA14},
    {0, CB4_CA15,  CB5_CA15,  CB6_CA15},
    {0, CB7_CA13,  CB8_CA13,  CB9_CA13},
    {0, CB7_CA14,  CB8_CA14,  CB9_CA14},
    {0, CB7_CA15,  CB8_CA15,  CB9_CA15},
    {0, CB7_CA16,  CB8_CA16,  CB9_CA16},
};

#endif

#ifdef RGB_MATRIX_ENABLE

//set numlock to always on, thanks to drashna
void	led_set_keymap(uint8_t usbLED)
{
	led_t	led_state	=host_keyboard_led_state();

	if(!led_state.num_lock)
	{
		register_code(KC_NUM_LOCK);
		unregister_code(KC_NUM_LOCK);
	}
}

hsv_t	MakeHSV(uint8_t h, uint8_t s, uint8_t v)
{
	hsv_t	ret	={	h, s, v	};

	return	ret;
}

rgb_t	MakeRGB(uint8_t r, uint8_t g, uint8_t b)
{
	rgb_t	ret	={	r, g, b	};

	return	ret;
}

rgb_t	ColorForKey(int key, uint8_t layer)
{
	switch(key)
	{
		//numpad plus has two colours depending on layer
		case	KC_PPLS:
			if(layer == 1)
			{
				return	MakeRGB(RGB_ORANGE);
			}
			else
			{
				return	MakeRGB(RGB_GREEN);
			}
			break;

		//gold modifierish keys
		case	KC_ESC:		
		case	KC_BSPC:
		case	KC_TAB:
		case	KC_ENT:
		case	KC_LSFT:
		case	KC_LCTL:
		case	KC_LGUI:
		case	KC_LALT:
			return	MakeRGB(RGB_GOLD);

		//magenta layer keys
		case	MO(1):
		case	MO(2):
			return	MakeRGB(RGB_MAGENTA);

		//tealish alpha keys
		case	KC_A:
		case	KC_B:
		case	KC_C:
		case	KC_D:
		case	KC_E:
		case	KC_F:
		case	KC_G:
		case	KC_H:
		case	KC_I:
		case	KC_J:
		case	KC_K:
		case	KC_L:
		case	KC_M:
		case	KC_N:
		case	KC_O:
		case	KC_P:
		case	KC_Q:
		case	KC_R:
		case	KC_S:
		case	KC_T:
		case	KC_U:
		case	KC_V:
		case	KC_W:
		case	KC_X:
		case	KC_Y:
		case	KC_Z:
			return	MakeRGB(RGB_CYAN);

		//greenish symbols layer 0
		case	KC_SCLN:
		case	KC_COMM:
		case	KC_DOT:
		//greenish layer 1
		case	KC_SLSH:
		case	KC_EXLM:
		case	KC_AT:
		case	KC_HASH:
		case	KC_GRV:
		case	KC_TILD:
		case	KC_DLR:
		case	KC_PERC:
		case	KC_CIRC:
		case	KC_AMPR:
		case	KC_ASTR:
		case	KC_LPRN:
		case	KC_RPRN:
		//greenish layer 3
		case	KC_PMNS:
		case	KC_PEQL:
		case	KC_LBRC:
		case	KC_RBRC:
		case	KC_UNDS:
		case	KC_LCBR:
		case	KC_RCBR:
		case	KC_QUOT:
		case	KC_DQT:
		case	KC_BSLS:
		case	KC_PIPE:
			return	MakeRGB(RGB_GREEN);

		//arrows
		case	KC_UP:
		case	KC_LEFT:
		case	KC_DOWN:
		case	KC_RIGHT:
			return	MakeRGB(RGB_RED);

		//orange numpad
		case	KC_P1:
		case	KC_P2:
		case	KC_P3:
		case	KC_P4:
		case	KC_P5:
		case	KC_P6:
		case	KC_P7:
		case	KC_P8:
		case	KC_P9:
		case	KC_P0:
		case	KC_PENT:
		case	KC_PDOT:
			return	MakeRGB(RGB_ORANGE);

		//ins home etc pink
		case	KC_INS:
		case	KC_HOME:
		case	KC_PGUP:
		case	KC_DEL:
		case	KC_END:
		case	KC_PGDN:
			return	MakeRGB(RGB_PINK);

		//f keys
		case	KC_F1:
		case	KC_F2:
		case	KC_F3:
		case	KC_F4:
		case	KC_F5:
		case	KC_F6:
		case	KC_F7:
		case	KC_F8:
		case	KC_F9:
		case	KC_F10:
		case	KC_F11:
		case	KC_F12:
			return	MakeRGB(RGB_PURPLE);

		//media keys
		case	KC_VOLU:
		case	KC_MPLY:
		case	KC_VOLD:
		case	KC_MNXT:
		case	LM_BRID:
		case	LM_BRIU:
		case	RM_VALU:
		case	RM_VALD:
			return	MakeRGB(88, 88, 88);

		//spaaaaaaaaace
		case	KC_SPC:
			return	MakeRGB(RGB_BLUE);
		default:
			return	MakeRGB(RGB_OFF);
	}
}

rgb_t	ModulateColour(rgb_t col, uint8_t m)
{
	col.r	*=m;
	col.g	*=m;
	col.b	*=m;

	return	col;
}

void	LightUpLayer(uint8_t layer, uint8_t ledMin, uint8_t ledMax)
{
	uint8_t	bright	=rgb_matrix_get_val();

	for(uint8_t row=0;row < MATRIX_ROWS;++row)
	{
		for(uint8_t col=0;col < MATRIX_COLS;++col)
		{
			uint8_t	idx	=g_led_config.matrix_co[row][col];
			
			if(idx >= ledMin && idx < ledMax && idx != NO_LED)
			{
				//special case for layer keys
				int	keyL0	=keymap_key_to_keycode(0, (keypos_t){col,row});
				if(keyL0 == MO(1) || keyL0 == MO(2))
				{
					rgb_t	colour	=ModulateColour(ColorForKey(keyL0, 0), bright);
					rgb_matrix_set_color(idx,
						colour.r, colour.g, colour.b);
					continue;
				}

				int	key	=keymap_key_to_keycode(layer, (keypos_t){col,row});
				
				rgb_t	colour	=ModulateColour(ColorForKey(key, layer), bright);
				rgb_matrix_set_color(idx,
					colour.r, colour.g, colour.b);
			}
		}
	}
}

bool	rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
	if(IS_LAYER_ON(2))
	{
		LightUpLayer(2, led_min, led_max);
	}
	else if(IS_LAYER_ON(1))
	{
		LightUpLayer(1, led_min, led_max);
	}
	else
	{
		LightUpLayer(0, led_min, led_max);
	}
	return	true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_indicators_advanced_user(led_min, led_max) != true) {
        return false;
    }

    //donut think I have a caps lock anymore
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(12, 255, 0, 0);
    }

    return true;
}
#endif
