#include "kb.h"

// avant derniere ligne
// 1 2 3         4 5 6
// dernière ligne
//       4 2   7 5
//       3 1   8 6

enum layer_number {
    //
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _RAISE,
    // _ADJUST
};

enum custom_keycodes {
    //
    QWERTY = SAFE_RANGE,
    COLEMAK,

    A_E1,  // è
    A_E2,  // é
    A_E3,  // ê
    A_E4   // ë
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap

// KC_LALT, KC_RGUI, KC_SPC,                       KC_UP,   KC_RBRC, KC_RALT,
//   MO(1), KC_LSFT, KC_LCTL, KC_ENT,     KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT),

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY]=KEYMAP(
		KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
		LOWER,   KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K, KC_L, KC_COMM, KC_GRV,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,

        KC_LEFT, KC_RIGHT, MT(MOD_LCTL, KC_ENTER),    LSFT(KC_SPACE), KC_UP, KC_DOWN,
        KC_1, KC_2, KC_3, KC_BSPACE,                  KC_5, KC_6, KC_7, KC_8),

    [_COLEMAK] = KEYMAP(
		KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
		KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G,        KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_DEL,
		LOWER,   KC_A, KC_R, KC_S, KC_T, KC_D,        KC_H, KC_N, KC_E, KC_I, KC_O, KC_GRV,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,

        KC_LEFT, KC_RIGHT, MT(MOD_LCTL, KC_ENTER),    LT(_LOWER, KC_SPACE), KC_UP, KC_DOWN,
        KC_1, KC_2, KC_3, KC_BSPACE,                  KC_5, KC_6, KC_7, KC_8),

	[_LOWER]=KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_TRNS, A_E1,    A_E2,    A_E3,    A_E4,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,     KC_TRNS, KC_TRNS,
		KC_1, KC_2, KC_3, KC_4,                                   KC_5, KC_6, COLEMAK, QWERTY),

	[_RAISE]=KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	// keyevent_t event = record->event;
	// switch (id) { }
	return MACRO_NONE;
}

void matrix_init_user(void) { }
void matrix_scan_user(void) { }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) { set_single_persistent_default_layer(_QWERTY); }
            return false;
        case COLEMAK:
            if (record->event.pressed) { set_single_persistent_default_layer(_COLEMAK); }
            return false;
        case A_E1:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_2))); }
            return false;
        case A_E2:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3))); }
            return false;
        case A_E3:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_4))); }
            return false;
        case A_E4:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_5))); }
            return false;

    }
    return true;
}

// UNUSED
void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) { } else { }
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) { } else { }
	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) { } else { }
	if (usb_led & (1 << USB_LED_COMPOSE)) { } else { }
	if (usb_led & (1 << USB_LED_KANA)) { } else { }
}


// KEYMAP(
// 	KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSPC,
// 	KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_DEL,
// 	KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_COMM, KC_GRV,
// 	KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
// 	KC_LALT, KC_RGUI, KC_SPC,                               KC_UP, KC_RBRC, KC_RALT,
// 	MO(1), KC_LSFT, KC_LCTL, KC_ENT,             KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT),
