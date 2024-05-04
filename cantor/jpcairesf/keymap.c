#include QMK_KEYBOARD_H
#include "quantum.h"

extern uint8_t is_master;

// markstos defines

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

// enum combos {
//   JK_ESC
// };

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   // For Vim, put Escape on the home row
//   [JK_ESC]    = COMBO(jk_combo, KC_ESC),
// };

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

// For _QWERTY layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSL_FUN  OSL(_FUNC)
#define GUI_BSP  GUI_T(KC_BSPC)
#define LOW_SPC  LT(_LOWER, KC_SPC)
#define RSE_ENT  LT(_RAISE, KC_ENT)
#define OSM_SFT  OSM(MOD_LSFT)

// For _LOWER layer
#define C_CED    UC(0x00E7)

// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)
#define ACUTE    UC(0x00B4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_DEL ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_HOME,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       OSM_SFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_END ,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        OSM_LCTL, OSM_ALT, LOW_SPC,    RSE_ENT,  GUI_BSP, OSL_FUN\
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,KC_BSLS, KC_PIPE, C_CED,   KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, LOWER,    KC_TRNS, KC_TRNS, KC_COLON\
                                      //`--------------------------'  `--------------------------'
  ),


  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_QUOT, KC_DQUO, KC_GRV,  KC_TILD, ACUTE,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS  ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,KC_COLON,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_LT  , KC_GT  ,KC_QUES ,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MUTE , KC_VOLD, KC_VOLU, KC_PSCR, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, RESET  ,XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, FUNC   , XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_ENT):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_SPC):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}
