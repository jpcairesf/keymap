#include QMK_KEYBOARD_H
#include "quantum.h"

extern uint8_t is_master;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  NUMS
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3
#define _NUMS 4

// For _QWERTY layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSL_FUN  OSL(_FUNC)
#define OSM_SFT  OSM(MOD_LSFT)
#define S_SLSH   S(KC_SLSH)
#define TTLOWER  TT(_LOWER)
#define TTRAISE  TT(_RAISE)
// #define AGR_TAB  RALT_T(KC_TAB)
#define NUMS_TAB LT(_NUMS,KC_TAB)

// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)
#define RALT_Q   RALT(KC_W)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      NUMS_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LGUI,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       OSM_SFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,OSL_FUN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_DEL ,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TTLOWER, OSM_ALT, KC_SPC,     KC_ENT,  KC_BSPC, TTRAISE \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_ESC, KC_CAPS, KC_RCBR, KC_RBRC, KC_LPRN,                      KC_RPRN, KC_BSLS, KC_PIPE, KC_LBRC, KC_QUOT,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS,  KC_TRNS, LOWER,     KC_TRNS, KC_TRNS, KC_COLON\
                                      //`--------------------------'  `--------------------------'
  ),


  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6    , KC_7   ,  KC_8  , KC_9   , KC_0   ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_ASTR,                     KC_LEFT , KC_DOWN, KC_UP  , KC_RGHT, KC_GRV ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_EXLM, XXXXXXX, S_SLSH , KC_AMPR,                     KC_NUBS , KC_PSLS, RALT_Q , KC_LBRC, KC_QUOT,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , XXXXXXX, KC_MS_U, XXXXXXX,                     KC_MUTE , KC_VOLD, KC_VOLU, KC_PSCR, KC_BTN1,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, QK_BOOT, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R,                     XXXXXXX , KC_BRID, KC_BRIU, KC_WH_U, KC_WH_D,XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          DM_REC1, DM_RSTP, DM_PLY1,    SH_TOGG, FUNC   , KC_BTN2\
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_7    , KC_8   , KC_9   , XXXXXXX, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_4    , KC_5   , KC_6   , XXXXXXX, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_1    , KC_2   , KC_3   , XXXXXXX, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_ENT , KC_0   , KC_BSPC\
                                      //`--------------------------'  `--------------------------'
  )
};
