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

#define R_T3 MT(MOD_LCTL, KC_ENTER)
#define R_T4 MT(MOD_LSFT, KC_SPACE)

#define R_1 KC_1;
#define R_2 KC_2
#define R_3 KC_3
#define R_4 LT(_LOWER, KC_BSPACE)

#define R_5 RAISE
#define R_6 KC_6
#define R_7 KC_7
#define R_8 KC_8

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY]=KEYMAP(
     // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
		LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LEFT, KC_RGHT, R_T3,                          R_T4,    KC_UP,   KC_DOWN,
                          KC_1,    KC_LWIN, KC_3,    R_4,         RAISE,   KC_6,    KC_7,    KC_8),

    [_COLEMAK] = KEYMAP(
     // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_DEL,
		LOWER,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_GRV,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
                          KC_LEFT, KC_RGHT, R_T3,                          R_T4,    KC_UP,   KC_DOWN,
                          KC_1,    KC_LWIN, KC_3,    R_4,         RAISE,   KC_6,    KC_7,    KC_8),

	[_LOWER]=KEYMAP(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, RESET,
		_______, _______, A_E1,    A_E2,    A_E3,    A_E4,        _______, KC_7,    KC_8,    KC_9,    _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_4,    KC_5,    KC_6,    _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_1,    KC_2,    KC_3,    _______, _______,
		_______, _______, _______,                   _______,     _______, _______,
		KC_1, KC_2, KC_3, KC_4,                                   KC_5, KC_6, COLEMAK, QWERTY),

	[_RAISE]=KEYMAP(
     // -------, -------, -------, -------, -------, -------,     -------, -------, -------, -------, -------, -------,
		_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,     KC_HOME, KC_PGUP, KC_UP, KC_PGDN, _______, _______,
		_______, _______, _______, _______, _______, _______,     KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                                _______, _______, _______,
		_______, _______, _______, _______,                       _______, _______, _______, _______)
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


// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap

// KC_LALT, KC_RGUI, KC_SPC,                       KC_UP,   KC_RBRC, KC_RALT,
//   MO(1), KC_LSFT, KC_LCTL, KC_ENT,     KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT),
