// Copyright 2022 LucW (@luc-languagetools)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H
#include <stdio.h>
#include "dvorak_42_key.h"
#include "tap_dances.h"

// to build: qmk compile -kb crkbd/rev1 -km dvorak_42_key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // COLEMAK
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y, T_COLON, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_T(KC_TAB),  KC_A, KC_R, KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,   KC_O,    T_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, QK_GESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            LGUI(KC_ESC),   LT(2,KC_TAB),  LSFT_T(KC_SPC),    RALT_T(KC_ENT),   LT(FNUM,KC_BSPC), LALT_T(KC_DELETE)
                                      //`--------------------------'  `--------------------------'
  ),

  // Numpad and function keys
  [FNUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,  KC_F3,   KC_F4,   XXXXXXX,                       KC_PGUP, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                      XXXXXXX, KC_4,    KC_5,    KC_6,    KC_O,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      KC_PGDN,   KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(SYMBOLS),  _______,     _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Symbols and brackets and cursors
  [SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, T_TILD, KC_EXCLAIM, KC_AT, KC_HASH, KC_LPRN,                     KC_RPRN, KC_EQL,  KC_PLUS, KC_MINS, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_AMPR, KC_PERC, KC_ASTR, KC_LBRC,                      KC_RBRC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DLR, KC_LT,                         KC_GT,   KC_UNDS, KC_QUES, KC_PIPE, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(MAUSE),  _______
                                      //`--------------------------'  `--------------------------'
    ),


  [MAUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
TO(BASE),SHELL_GIT_DIFF, SHELL_PGREP, SHELL_PLESS, SHELL_LESS, KC_TRNS,              RCTL(KC_D), KC_HOME, KC_UP, KC_END, RCTL(KC_L), RCTL(KC_X),
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
XXXXXXX,SHELL_GIT_STATUS,SHELL_CDPRE,SHELL_LSLTR,SHELL_LS, SHELL_LSLA,              LALT(KC_B), KC_LEFT, KC_DOWN, KC_RIGHT, LALT(KC_F), RCTL(KC_W),
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
KC_TRNS,SHELL_SCREEN_LIST, SHELL_SCREENRD, SHELL_SCREEN_NEW, SHELL_TAILF, KC_TRNS,   RCTL(KC_U), LALT(KC_DOT), RCTL(KC_R), KC_BTN2, RCTL(KC_K), RCTL(KC_C),
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,              LCTL(LSFT(KC_V)), KC_TRNS, KC_TRNS
                                      //`--------------------------'            `--------------------------'
  ),


};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  // return rotation;
  return OLED_ROTATION_180;
}
  

#define DISPLAY_LAYER_NAME(LAYER_NAME, LAYER_STRING) \
  if(get_highest_layer(layer_state) == LAYER_NAME) { \
      oled_write_ln_P(PSTR(LAYER_STRING), false); \
      return;\
  }\


void oled_render_layer_state(void) {
  // if caps word is enabled, show
  if(is_caps_word_on()) {
      oled_write_ln_P(PSTR("CAPS WORD"), false);
      return;
  }
  DISPLAY_LAYER_NAME(MAUSE, "MAUSE");
  DISPLAY_LAYER_NAME(SYMBOLS, "SYMBOLS");
  DISPLAY_LAYER_NAME(FNUM, "FUNC & NUM");
  DISPLAY_LAYER_NAME(BASE, "BASE");

}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master( )) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
     }
    return false;
}

#endif // OLED_ENABLE
