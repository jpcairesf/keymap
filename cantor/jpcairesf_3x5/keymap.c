/*
 * QMK keymap file
 *
 * This keymap uses a simple combo implementation.
 *
 * Keyboard: cantor
 * Layout: LAYOUT_split_3x6_3
 * Keymap: cantor_layout_split_3x6_3_2025-07-28
 *
 * Combos:
 * - J + K = Escape
 * - X + C = Shift + Tab
 * - C + V = Tab
 * - Q + B = Reset
 */

#include QMK_KEYBOARD_H
#include "quantum.h"

extern uint8_t is_master;

#define DOCK LCTL(KC_F3)
#define PRSCN C(S(G(KC_4)))

// Define layer names for better readability
enum layers {
  _BASE,
  _LOWER,
  _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BASE: Default QWERTY Layer */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO,   KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO,   KC_A,         KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC, KC_NO,
        KC_NO,   LALT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LSFT, KC_NO,
                                        KC_LCTL, KC_LGUI, KC_SPC,      KC_ENT,  MO(_LOWER), MO(_RAISE)
    ),

    /* _LOWER: Symbols, Navigation, and Media */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_NO,   KC_CAPS, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_NO,
        KC_NO,   KC_LALT, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,     KC_SLSH, KC_QUES, DOCK,    PRSCN,   KC_LSFT, KC_NO,
                                   KC_LCTL, KC_LGUI, KC_SPC,      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* _RAISE: More Symbols and System Keys */
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
        KC_NO,   KC_GRV,  KC_BSLS, KC_SLSH, KC_LBRC, KC_RBRC,     KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_BSPC, KC_NO,
        KC_NO,   KC_TILD, KC_PIPE, KC_QUES, KC_LCBR, KC_RCBR,     KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, KC_LSFT, KC_NO,
                                   KC_LCTL, KC_LGUI, KC_SPC,      QK_BOOT, KC_TRNS, KC_TRNS
    )
};

// --- Simple Combos ---
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM qb_combo[] = {KC_Q, KC_B, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
    COMBO(xc_combo, S(KC_TAB)),
    COMBO(cv_combo, KC_TAB),
    COMBO(qb_combo, QK_BOOT),
};
