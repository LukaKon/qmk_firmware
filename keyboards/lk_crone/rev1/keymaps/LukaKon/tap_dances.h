#pragma once

enum custom_tapdances {
    TD_ESC_CAPS = 0,
    TD_SEMICOLON_COLON,
    TD_BACKTICK_TILDE,
};

#define T_ESC   TD(TD_ESC_CAPS)          // Tap for ESC, double tap for CAPSLOCK
#define T_COLON TD(TD_SEMICOLON_COLON)   // Tap once for semicolon, twice for colon
#define T_TILD  TD(TD_BACKTICK_TILDE)    // Tap once for backtick, twice for tilde
