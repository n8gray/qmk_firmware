#include QMK_KEYBOARD_H
#include <print.h>

enum custom_keycodes {
	PREV_TAB = SAFE_RANGE,
	NEXT_TAB,
    LOWER,
    RAISE,
    ADJUST,
};

enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST,
};

#define SYMBOL_LAYER1 		_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_MNXT, 				KC_VOLU,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______ 
#define SYMBOL_LAYER2		 KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_MPRV, 				KC_VOLD,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS
#define SYMBOL_LAYER3		KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_MPLY, 				KC_MUTE, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS
#define SYMBOL_LAYER4		_______, KC_SLASH, KC_MINS,  KC_EQL, KC_PLUS, KC_ASTR, _______, 				_______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PGUP, _______
#define SYMBOL_LAYER5		_______, _______, _______, _______, _______, _______, _______, 				_______, _______, KC_UNDS, _______, KC_HOME, KC_PGDOWN, KC_END

#define EXPAND_LAYER(l1, l2, l3, l4, l5) LAYOUT_4key(l1, l2, l3, l4, l5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_4key(
	   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_MINS,                 KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
	   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,                KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
	  KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LPRN,                KC_RPRN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, 
	  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_GRV,                KC_RGUI,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_RSFT,
	  KC_CAPS, KC_MUTE,   TT(_NAV), KC_LALT,          KC_LGUI,   LOWER, KC_DEL, KC_ENT,  RAISE,  KC_SPC,         KC_SLASH, KC_LEFT, KC_DOWN, KC_RGHT
	  ),
	[_LOWER] = EXPAND_LAYER(
		SYMBOL_LAYER1,
		SYMBOL_LAYER2,
		SYMBOL_LAYER3,
		SYMBOL_LAYER4,
		SYMBOL_LAYER5
		),
	[_RAISE] = EXPAND_LAYER(
		SYMBOL_LAYER1,
		SYMBOL_LAYER2,
		SYMBOL_LAYER3,
		SYMBOL_LAYER4,
		SYMBOL_LAYER5
		),
	[_NAV] = LAYOUT_4key(
		_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_MNXT, 				KC_VOLU,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
		_______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_MPRV, 				KC_VOLD, KC_PGUP, KC_HOME, KC_UP, KC_END, _______, _______, 
		_______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_MPLY, 				KC_MUTE, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRACKET, KC_RBRACKET, 
		_______, _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______, 				_______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PGUP, _______, 
		_______, _______, _______, _______, _______, _______, _______, 			    _______, _______, KC_UNDS, _______, KC_HOME, KC_PGDOWN, KC_END
		),
	[_ADJUST] = LAYOUT_4key(
		_______, _______, _______, _______, _______, _______, RGB_VAI, 				RGB_HUI, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, RGB_VAD, 				RGB_HUD, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, RGB_SPI, RGB_TOG, 				RGB_MOD, RGB_SAI, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, RGB_SPD, RGB_MOD, 				RGB_RMOD, RGB_SAD, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, 				_______, _______, _______, _______, _______, _______, _______
		)
};

//#if 0

#define LAYER_VAL 120

// Define led segments for each layer
const rgblight_segment_t PROGMEM capslock_segments[] = {
	{9, 6, 0, 255, LAYER_VAL},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM lower_segments[] = {
	{10, 2, 10, 255, LAYER_VAL}, 
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM raise_segments[] = {
	{12, 2, 85, 255, LAYER_VAL}, 
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM nav_segments[] = {
	{9, 2, 64, 255, LAYER_VAL}, 
	{13, 2, 64, 255, LAYER_VAL}, 
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM adjust_segments[] = {
	{10, 4, 20, 255, LAYER_VAL}, 
	RGBLIGHT_END_SEGMENTS
};

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM mod_led_layers[] = {
	capslock_segments,
	lower_segments,
	raise_segments,
	nav_segments,
	adjust_segments,
	NULL
};

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = mod_led_layers;
}

#define BIT_SET(intval, bitnum) ((intval & (1 << bitnum)) > 0)

// Use the RGBLight layers feature to indicate active layers
uint32_t layer_state_set_user(uint32_t state) {
	uprintf("layer state: %d\n", state);
	rgblight_set_layer_state(1, BIT_SET(state, _LOWER));
	rgblight_set_layer_state(2, BIT_SET(state, _RAISE));
	rgblight_set_layer_state(3, BIT_SET(state, _NAV));
	rgblight_set_layer_state(4, BIT_SET(state, _ADJUST));
	// This isn't required but it improves the responsiveness
	rgblight_set();
  	return state;
}

// Called when the host computer indicates an LED should change state.
// This didn't work until I checked "Manipulate LED" in Karabiner Elements preferences
bool led_update_user(led_t led_state) {
	//uprintf("Caps_lock = %s  (%d)\n", led_state.caps_lock ? "ON": "OFF", led_state.raw);
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}

// Handle tri-layer setup
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
		case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
		case ADJUST:
		if (record->event.pressed) {
			layer_on(_ADJUST);
		} else {
			layer_off(_ADJUST);
		}
		return false;
		break;
	}
  	if (record->event.pressed) {
	  	switch (keycode) {
    	case PREV_TAB:
        	SEND_STRING(SS_LCMD("{"));
      		break;
    	case NEXT_TAB:
        	SEND_STRING(SS_LCMD("}"));
      		break;
		default:
			break;
		}
	}
  return true;
}


//#endif
