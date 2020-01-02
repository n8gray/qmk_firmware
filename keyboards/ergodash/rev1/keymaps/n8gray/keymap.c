#include QMK_KEYBOARD_H
#include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_4key(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LPRN, KC_RPRN, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_RGUI, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_CAPS, KC_MUTE, KC_LALT, KC_LGUI, KC_BSPC, TT(1), KC_DEL, KC_ENT, TT(2), KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_4key(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12, _______, _______, KC_HOME, KC_UP, KC_END, KC_PGUP, _______, _______, KC_PGUP, KC_HOME, KC_UP, KC_END, _______, KC_F11, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______),
	[2] = LAYOUT_4key(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, RGB_MOD, RGB_RMOD, _______, KC_TRNS, _______, _______, KC_TRNS, _______, _______, _______, _______, _______)
};

#define BASE_LAYER 0

//#if 0

// Define led overlays for each layer
static rgblight_overlay_t capslock_overlays[] = {
	{9, HSV_RED},
	{10, HSV_RED},
	{11, HSV_RED},
	{12, HSV_RED},
	{13, HSV_RED},
	{14, HSV_RED},
	RGBLIGHT_END_OVERLAYS
};
static rgblight_overlay_t layer1_overlays[] = {
	{10, HSV_CYAN}, 
	{11, HSV_CYAN}, 
	RGBLIGHT_END_OVERLAYS
};
static rgblight_overlay_t layer2_overlays[] = {
	{12, HSV_PURPLE}, 
	{13, HSV_PURPLE}, 
	RGBLIGHT_END_OVERLAYS
};

// Now define the array of layers. Later layers take precedence
static rgblight_overlay_t * const mod_led_layers[] = {
	capslock_overlays,
	layer1_overlays,
	layer2_overlays,
	NULL
};

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = mod_led_layers;
}

#define BIT_SET(intval, bitnum) ((intval & (1 << bitnum)) > 0)

// Use the RGBLight layers feature to indicate active layers
uint32_t layer_state_set_user(uint32_t state) {
	rgblight_set_layer_state(1, BIT_SET(state, 1));
	rgblight_set_layer_state(2, BIT_SET(state, 2));
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

//#endif
