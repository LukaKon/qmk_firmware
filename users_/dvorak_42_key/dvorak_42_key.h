#pragma once

#include "quantum.h"

// LAYERS
// ======

enum layer_names {
    BASE,            // base dvorak layer
    FNUM,
    SYMBOLS,
    MAUSE,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  
  // shell nav macros
  SHELL_LS,
  SHELL_LSLTR,
  SHELL_LSLA,
  SHELL_CDPRE,
  SHELL_LESS,
  SHELL_PLESS,
  SHELL_PGREP,
  SHELL_TAILF,

  SHELL_SCREENRD,
  SHELL_SCREEN_NEW,
  SHELL_SCREEN_LIST,

  SHELL_GIT_DIFF,
  SHELL_GIT_STATUS,

  // linux screen macros
  SCREEN_TAB_LEFT,
  SCREEN_TAB_RIGHT,

  SCREEN_NEW_TAB,
  SCREEN_DETACH,
  SCREEN_RENAME,
  SCREEN_NUMBER,
  SCREEN_KILL,

  SCREEN_0,
  SCREEN_1,
  SCREEN_2,
  SCREEN_3,
  SCREEN_4,
  SCREEN_5,
  SCREEN_6,
  SCREEN_7,
  SCREEN_8,
  SCREEN_9,

  SCREEN_COPY_MODE,
  SCREEN_PASTE,

  SCREEN_READREG_1,
  SCREEN_READREG_2,
  SCREEN_READREG_3,
  SCREEN_PASTEREG_1,
  SCREEN_PASTEREG_2,
  SCREEN_PASTEREG_3,

  // Windows 10 macros
  WINDOWS10_WORKSPACE_LEFT,
  WINDOWS10_WORKSPACE_RIGHT,
  WINDOWS10_TASK_VIEW,

};

// tap-dance configuration
// =======================

enum {
    // TD_BSPC_CTL_BSPC,
    // TD_BSPC_CTL_BSPC_IOS,
    TD_DEL_WORD_DEL,
    TD_DEL_WORD_DEL_IOS
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }
