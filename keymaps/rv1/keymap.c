#include "kb.h"

// 1 2 3         4 5 6  // L5
//       3 1   8 6      // L6 (1/2)
//       4 2   7 5      // L6 (2/2)

enum layer_number {
    //
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _NUMBERS,
    _MOVE,
    // _ADJUST
};

enum custom_keycodes {
    //
    QWERTY = SAFE_RANGE,
    COLEMAK,

    RV_E1,  // è
    RV_E2,  // é
    RV_E3,  // ê
    RV_E4   // ë

};

#define LOWER MO(_LOWER)
#define MOVE MO(_MOVE)
#define NUMBERS MO(_NUMBERS)

#define RV_T3 MT(MOD_LCTL, KC_ENTER)
#define RV_T4 KC_SPC
// MT(MOD_LSFT, KC_SPACE)

#define RV_1 KC_LWIN
#define RV_2 KC_LSFT
#define RV_3 KC_3
#define RV_4 LT(_LOWER, KC_BSPACE)
#define RV_5 MOVE
#define RV_6 KC_6
#define RV_7 KC_7
#define RV_8 KC_8

// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic#punctuation
#define RV_PARO LSFT(KC_9)      // (
#define RV_PARC LSFT(KC_0)      // (
#define RV_BRAO LSFT(KC_RBRC)   // [
#define RV_BRAC LSFT(KC_LBRC)   // ]
#define RV_CURO KC_RBRC         // {
#define RV_CURC KC_LBRC         // }
#define RV_PLUS LSFT(KC_EQUAL)  // +

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY]=KEYMAP(
     // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
		LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LEFT, KC_RGHT, RV_T3,                         RV_T4,   KC_UP,   KC_DOWN,
                          RV_1,    RV_2,    RV_3,    RV_4,        RV_5,    RV_6,    RV_7,    RV_8),

    [_COLEMAK] = KEYMAP(
     // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_DEL,
		LOWER,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_GRV,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
                          KC_LEFT, KC_RGHT, RV_T3,                         RV_T4,   KC_UP,   KC_DOWN,
                          RV_1,    RV_2,    RV_3,    RV_4,        RV_5,    RV_6,    RV_7,    RV_8),

	[_LOWER]=KEYMAP(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, RESET,
		_______, _______, RV_E1,   RV_E2,   RV_E3,   RV_E4,       _______, RV_PARC, RV_BRAO, RV_CURO, _______, _______,
		_______, _______, _______, _______, NUMBERS, _______,     KC_SLSH, RV_PARO, RV_BRAC, RV_CURC, _______, _______,
		_______, _______, _______, _______, _______, _______,     RV_PLUS, KC_EQL,  KC_QUOT, KC_MINS, _______, _______,
		                  _______, _______, _______,                       KC_LSFT, _______, _______,
		                  _______, _______, _______, _______,     _______, _______, COLEMAK, QWERTY),

	[_NUMBERS]=KEYMAP(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, RESET,
		_______, _______, RV_E1,   RV_E2,   RV_E3,   RV_E4,       _______, KC_7,    KC_8,    KC_9,    _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_4,    KC_5,    KC_6,    _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_1,    KC_2,    KC_3,    _______, _______,
		                  _______, _______, _______,                       _______, _______, _______,
		                  _______, _______, _______, _______,     _______, _______, COLEMAK, QWERTY),

	[_MOVE]=KEYMAP(
		_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_PGUP, _______, KC_PGDN,  _______, _______,
		_______, _______, _______, KC_LCTL, KC_LSFT, _______,     _______, KC_HOME, KC_UP,   KC_END, _______, _______,
		_______, _______, _______, _______, _______, _______,     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		                  _______, _______, _______,                       _______, _______, _______,
		                  _______, _______, _______, _______,     _______, _______, _______, _______)
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
        case RV_E1:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_2))); }
            return false;
        case RV_E2:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3))); }
            return false;
        case RV_E3:
            if (record->event.pressed) { SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_4))); }
            return false;
        case RV_E4:
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


// https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
// enum combos {
//   AB_ESC,
//   JK_TAB
// };

// const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [AB_ESC] = COMBO(ab_combo, KC_ESC),
//   [JK_TAB] = COMBO(jk_combo, KC_TAB)
// };

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

// TODO: I can't leave delete as-is
// mod tap is also quite bad so far

// Notes
// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
// reduce TAPPING_TERM  ?
// #define IGNORE_MOD_TAP_INTERRUPT ?
// #define PERMISSIVE_HOLD
