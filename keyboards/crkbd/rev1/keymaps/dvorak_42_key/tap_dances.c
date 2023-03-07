#include QMK_KEYBOARD_H
#include "tap_dances.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ESCAPE, twice for Caps Lock
    [TD_ESC_CAPS]     = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for semicolon, twice for colon
    [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
    // Tap once for backtick, twice for tilde
    [TD_BACKTICK_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILD),
};
