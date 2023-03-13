#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "dvorak_42_key.h"
// #include "tap_dances.h"

// to build: qmk compile -kb crkbd/rev1 -km dvorak_42_key

// tap dance definition
enum {
    TD_ESC_CAPS = 0,
    TD_SEMICOLON_COLON,
    TD_BACKTICK_TILDE,
    TD_LBRC_LCBR,
    TD_RBRC_RCBR,
    TD_QUOT_DQUO,
};

// qk_tap_dance_action_t tap_dance_actions[] = {
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ESCAPE, twice for Caps Lock
    [TD_ESC_CAPS]     = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for semicolon, twice for colon
    [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
    // Tap once for backtick, twice for tilde
    [TD_BACKTICK_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILD),
    // Tap once for [, twice for {
    [TD_LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    // Tap once for ], twice for }
    [TD_RBRC_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    // Tap once for ', twice for "
    [TD_QUOT_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  };

enum {
  BASE,
  FNUM,
  SYMBOLS,
  CURSOR,
  SHORT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // COLEMAK
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y, TD(TD_SEMICOLON_COLON), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_T(KC_TAB),  KC_A, KC_R, KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,   KC_O,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            GUI_T(KC_DELETE), LT(SYMBOLS,KC_TAB), LSFT_T(KC_SPC),    RALT_T(KC_ENT), LT(FNUM,KC_BSPC), LALT_T(KC_ESC)
                                      //`--------------------------'  `--------------------------'
  ),

  // Numpad and function keys
  [FNUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_LPRN,                       KC_RPRN, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8, TD(TD_LBRC_LCBR),       TD(TD_RBRC_RCBR), KC_4,    KC_5,    KC_6,    KC_0,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LT,                        KC_GT,   KC_1,    KC_2,    KC_3,    KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, MO(CURSOR),  _______,     _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Symbols and brackets and cursors
  [SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_EXCLAIM, KC_AT, KC_HASH, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_AMPR, KC_PERC, KC_ASTR, XXXXXXX,        TD(TD_BACKTICK_TILDE), KC_MINS, KC_EQL, KC_PLUS, TD(TD_QUOT_DQUO), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DLR, XXXXXXX,                       XXXXXXX, KC_UNDS, KC_QUES, KC_PIPE, KC_BSLS, XXXXXXX,                      
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, MO(SHORT),  _______
                                      //`--------------------------'  `--------------------------'
    ),

  // Cursors manipulation
  [CURSOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  // Shortcuts & macros
  [SHORT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  // return rotation;
  return OLED_ROTATION_0;
}
  

#define DISPLAY_LAYER_NAME(LAYER_NAME, LAYER_STRING) \
  if(get_highest_layer(layer_state) == LAYER_NAME) { \
      oled_write_ln_P(PSTR(LAYER_STRING), false); \
      return;\
  }\


void oled_render_layer_state(void) {
  // if caps word is enabled, show
  // if(is_caps_word_on()) {
  //     oled_write_ln_P(PSTR("CAPS WORD"), false);
  //     return;
  // }
  DISPLAY_LAYER_NAME(CURSOR, "CURSOR");
  DISPLAY_LAYER_NAME(SYMBOLS, "SYMBOLS");
  DISPLAY_LAYER_NAME(FNUM, "FUNC & NUM");
  DISPLAY_LAYER_NAME(BASE, "BASE");
  DISPLAY_LAYER_NAME(SHORT, "SHORT & MACRO");

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
        oled_write_P(PSTR("LAYER:"), false);
        oled_render_layer_state();
    } else {
      oled_write_P(PSTR("BUTTON:"), false);
      // oled_write_char(const char data, bool invert);
     }
    return false;
}

#endif // OLED_ENABLE
