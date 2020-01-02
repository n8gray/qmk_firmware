#include QMK_KEYBOARD_H
#include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_4key(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LPRN, KC_RPRN, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_RGUI, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_CAPS, KC_MUTE, KC_LALT, KC_LGUI, KC_BSPC, TT(1), KC_DEL, KC_ENT, TT(2), KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_4key(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12, _______, _______, KC_HOME, KC_UP, KC_END, KC_PGUP, _______, _______, KC_PGUP, KC_HOME, KC_UP, KC_END, _______, KC_F11, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______),
	[2] = LAYOUT_4key(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, RGB_MOD, RGB_RMOD, _______, KC_TRNS, _______, _______, KC_TRNS, _______, _______, _______, _______, _______)
};

#define BASE_LAYER 0
uint32_t prev = BASE_LAYER;

//#if 0

static led_overlay_t mod_led_overlay[7] = {
	{DISABLED_OVERLAY, 2, 0, 0xFF, 0xFF},  // Capslock x4
	{DISABLED_OVERLAY, 3, 0, 0xFF, 0xFF},
	{DISABLED_OVERLAY, 4, 0, 0xFF, 0xFF},
	{DISABLED_OVERLAY, 5, 0, 0xFF, 0xFF},
	{DISABLED_OVERLAY, 6, 0x22, 0xFF, 0xFF},  // Layer 1
	{DISABLED_OVERLAY, 7, 0x99, 0xFF, 0xFF},  // Layer 2
	{END_OVERLAY, 0, 0, 0xFF, 0xFF}
};
static void set_caps_lock_overlay_state(uint8_t state);
static void set_layer_overlay_state(uint8_t layer, uint8_t state);

void keyboard_post_init_user(void) {
	led_overlay = &mod_led_overlay[0];
}

// The idea here is to use the RGB LEDs as an indicator of what layer we're on.  The trick
// is that qmk doesn't have a great way to save/restore state for the leds, so we have to 
// hack something together ourselves.  It gets ugly because the rgb config keys are often in
// a separate layer, so they get clobbered when you return to the base layer.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = get_highest_layer(state);

  if (prev == layer) {
	  return state;
  }

	switch (layer) {
	case BASE_LAYER:
		set_layer_overlay_state(1, DISABLED_OVERLAY);
		set_layer_overlay_state(2, DISABLED_OVERLAY);
		print("base\n");
		break;

	case 1:
		set_layer_overlay_state(1, ENABLED_OVERLAY);
		set_layer_overlay_state(2, DISABLED_OVERLAY);

		print("Layer 1\n");
		break;
	default: 
		set_layer_overlay_state(1, DISABLED_OVERLAY);
		set_layer_overlay_state(2, ENABLED_OVERLAY);
		print("Layer 2\n");
		break;
	}
	rgblight_set();
    prev = layer;
  return state;
}

// Called when the locking modifiers have state changes
// XXX This doesn't get called when I hit caps lock??
bool led_update_user(led_t led_state) {
	uprintf("Caps_lock = %s\n", led_state.caps_lock ? "ON": "OFF");
	set_caps_lock_overlay_state(led_state.caps_lock ? ENABLED_OVERLAY : DISABLED_OVERLAY);
	return true;
}

static void set_caps_lock_overlay_state(uint8_t state) {
	mod_led_overlay[0].enabled = state;
	mod_led_overlay[1].enabled = state;
	mod_led_overlay[2].enabled = state;
	mod_led_overlay[3].enabled = state;
}

static void set_layer_overlay_state(uint8_t layer, uint8_t state) {
	mod_led_overlay[3 + layer].enabled = state;
}

//#endif
