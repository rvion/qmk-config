#include "kb.h"

enum unicode_names { SNEK, GREN, RED, ORNG, HND1, HND2, HND3 };
const uint32_t PROGMEM unicode_map[] = {
    [SNEK] = 0x1F40D,  // 🐍 https://emojiguide.org/snake
    [RED]  = 0x1F534,  // 🔴 https://emojiguide.org/red-circle
    [ORNG] = 0x1F536,  // 🔶 https://emojiguide.org/large-orange-diamond
    [GREN] = 0x1F7E2,  // 🟢 https://emojiguide.org/green-circle
    [HND1] = 0x1F44B,  // 👋 https://emojiguide.org/waving-hand
    [HND2] = 0x1F44D,  // 👍 https://emojiguide.org/thumbs-up
    [HND3] = 0x1F44C   // 👌 https://emojiguide.org/ok-hand
};

enum layer_number {
    //
    _QWERTY = 0,
    _COLEMAK,
    _SYMBOLS,
    _EMOJIS,
    // _NUMBERS,
    _EMPTY
    // _ADJUST
};

enum custom_keycodes {
    //
    QWERTY = SAFE_RANGE,
    COLEMAK,

    // ALT CODES on windows
    // see https://sites.psu.edu/symbolcodes/windows/codealt/
    RV_E1,  // è 0232
    RV_E2,  // é 0233
    RV_E3,  // ê 0234
    RV_E4,  // ë 0235

    RV_A1,  // â 0226
    RV_A2,  // à 0224

    RV_C1,  // ç 0231
};

#define SYMBOLS MO(_SYMBOLS)
#define EMOJIS MO(_EMOJIS)
// #define NUMBERS MO(_NUMBERS)

// THUMBS KEYS
// l r A         B u d  // L5
//       4 2   8 5      // L6 (1/2)E
//       3 1   7 6      // L6 (2/2)
#define RV_TA MT(MOD_LCTL, KC_ENTER)
#define RV_T4 LT(_SYMBOLS, KC_BSPACE)  // was: SYMBOLS
#define RV_T2 KC_LSFT                  // was: MT(MOD_LSFT, KC_BSPACE)

#define RV_T3 KC_LWIN
#define RV_T1 LCTL(KC_LSFT)  // KC_LSFT | KC_LCTL

#define RV_TB KC_SPC
#define RV_T5 EMOJIS
#define RV_T7 LM(EMOJIS, MOD_LSFT)

#define RV_T6 KC_LALT
#define RV_T8 KC_ESC
// MT(MOD_LSFT, KC_SPACE)

#define RV_CLFT LCTL(KC_LEFT)
#define RV_CRGT LCTL(KC_RIGHT)

// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic#punctuation
#define RV_PARO LSFT(KC_9)      // (
#define RV_PARC LSFT(KC_0)      // (
#define RV_BRAO LSFT(KC_RBRC)   // [
#define RV_BRAC LSFT(KC_LBRC)   // ]
#define RV_CURO KC_RBRC         // {
#define RV_CURC KC_LBRC         // }
#define RV_PLUS LSFT(KC_EQUAL)  // +
#define RV_ACPT LCTL(KC_ENTER)  // accept(ctrl+enter)
#define RV_QMRK LSFT(KC_SLSH)   // ?
#define RV_BANG LSFT(KC_1)      // !
#define RV_COLN LSFT(KC_SCLN)   // :

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = KEYMAP(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        SYMBOLS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LEFT, KC_RGHT, RV_TA,                         RV_TB,   KC_UP,   KC_DOWN,
                          RV_T1,   RV_T2,   RV_T3,   RV_T4,       RV_T5,   RV_T6,   RV_T7,   RV_T8),

    [_COLEMAK] = KEYMAP(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, // KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLS, // KC_DEL,
        SYMBOLS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_SCLN, // KC_GRV,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, // KC_BSLS,
                          KC_LEFT, KC_RGHT, RV_TA,                         RV_TB,   KC_UP,   KC_DOWN,
                          RV_T1,   RV_T2,   RV_T3,   RV_T4,       RV_T5,   RV_T6,   RV_T7,   RV_T8),

    [_SYMBOLS] = KEYMAP(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_PSCR, _______, RESET,
        _______, KC_APP,  RV_E1,   RV_E2,   RV_E3,   RV_E4,       _______, RV_PARC, RV_BRAO, RV_CURO, _______, _______,
        _______, RV_A1,   RV_A2,   RV_ACPT, RV_QMRK, RV_BANG,     KC_SLSH, RV_PARO, RV_BRAC, RV_CURC, KC_MINS, _______,
        _______, _______, _______, RV_C1,   RV_COLN, _______,     RV_PLUS, KC_EQL,  KC_QUOT, KC_MINS, _______, _______,
                          _______, _______, _______,                       _______, KC_DEL,  _______,
                          _______, _______, _______, _______,     KC_LSFT, COLEMAK, KC_LSFT, QWERTY),

    [_EMOJIS] = KEYMAP(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, RESET,
        _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______,     KC_F10,  KC_7,    KC_8,    KC_9,    _______, X(ORNG),
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,      KC_F11,  KC_4,    KC_5,    KC_6,    KC_DOT,  X(GREN),
        _______, _______, KC_TAB,  _______, _______, _______,     KC_F12,  KC_1,    KC_2,    KC_3,    KC_DOT,  X(RED),
                          _______, _______, _______,                       _______, KC_0,    KC_GRV,
                          _______, _______, _______, KC_LALT,     _______, _______, _______, _______),

    // in case I need to create additional layer, I can copy paste this:
    [_EMPTY] = KEYMAP(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, X(HND1),
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, X(HND2),
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, X(HND3),
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
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

// REGULAR UTF-8 CHARS (no need for Win Compose)
#define _0 SS_TAP(X_KP_0)
#define _1 SS_TAP(X_KP_1)
#define _2 SS_TAP(X_KP_2)
#define _3 SS_TAP(X_KP_3)
#define _4 SS_TAP(X_KP_4)
#define _5 SS_TAP(X_KP_5)
#define _6 SS_TAP(X_KP_6)
#define _7 SS_TAP(X_KP_7)
#define _8 SS_TAP(X_KP_8)
#define _9 SS_TAP(X_KP_9)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY: if (record->event.pressed) { set_single_persistent_default_layer(_QWERTY); } return false;
        case COLEMAK: if (record->event.pressed) { set_single_persistent_default_layer(_COLEMAK); } return false;
        case RV_E1: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _3 _2)); } return false;
        case RV_E2: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _3 _3)); } return false;
        case RV_E3: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _3 _4)); } return false;
        case RV_E4: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _3 _5)); } return false;
        case RV_A1: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _2 _4)); } return false;
        case RV_A2: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _2 _6)); } return false;
        case RV_C1: if (record->event.pressed) { SEND_STRING(SS_LALT(_0 _2 _3 _1)); } return false;
    }
    return true;
}

// UNUSED
// void led_set_user(uint8_t usb_led) {
//     if (usb_led & (1 << USB_LED_NUM_LOCK)) { } else { }
//     if (usb_led & (1 << USB_LED_CAPS_LOCK)) { } else { }
//     if (usb_led & (1 << USB_LED_SCROLL_LOCK)) { } else { }
//     if (usb_led & (1 << USB_LED_COMPOSE)) { } else { }
//     if (usb_led & (1 << USB_LED_KANA)) { } else { }
// }


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
//     KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSPC,
//     KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_DEL,
//     KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_COMM, KC_GRV,
//     KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
//     KC_LALT, KC_RGUI, KC_SPC,                               KC_UP, KC_RBRC, KC_RALT,
//     MO(1), KC_LSFT, KC_LCTL, KC_ENT,             KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT),


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
