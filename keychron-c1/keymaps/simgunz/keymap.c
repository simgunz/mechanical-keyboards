/*
Copyright 2021 Simone Gaiarin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE    = 0,
    WIN_FN      = 1,
    MAC_BASE    = 2,
    MAC_FN      = 3,
    WIN_CAPS    = 4,
};

enum {
  RST_KB = SAFE_RANGE,
  KC_PTT
};

// custom tap dance
enum {
    TD_VSTS,  // leader key for vscode test commands
};

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_CRTN LGUI(KC_C)          // Cortana
#define KC_SNIP LGUI(LSFT(KC_S))    // Windows snip tool

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_SIRI LGUI(KC_SPC)        // Siri
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

#define KC_KACT LWIN(KC_Q)          // KDE activities
#define KC_MIC KC_F20               // Mute microphone

// layer modifiers
#define KC_MOFN MO(WIN_FN)
#define KC_MOCP MO(WIN_CAPS)

// key combinations
#define KC_PWRD LCTL(KC_LEFT)
#define KC_NWRD LCTL(KC_RIGHT)
#define KC_BWRD LCTL(KC_BSPC)
#define KC_DWRD LCTL(KC_DEL)
#define KC_SHIN LSFT(KC_INS)

#define PTT_TAPPING_TERM 400

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Windows layout
    +-------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|MIC |RGB |
    +--------------------------------------------------------------------------+ +--------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP|
    +--------------------------------------------------------------------------+ +--------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
    +--------------------------------------------------------------------------+ +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
    +--------------------------------------------------------------------------+      +----+    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+ +--------------+
    |LCTRL| LWIN| LALT |            SPACE            | RALT| RWIN | FN | RCTRL | |LFT |DWN |RGT |
    +-------------------------------------------------------------------------------------------+
    */

    [WIN_BASE] = { // Windows base layout
        /*  0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16     */
        {   KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,     KC_PSCR,   KC_PTT,    RGB_TOG },
        {   KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_INS,    KC_HOME,   KC_PGUP },
        {   KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL,    KC_END,    KC_PGDN },
        {   KC_MOCP,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_NO,     KC_NO   },
        {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     TD(TD_VSTS),KC_NO,    KC_UP,     KC_NO   },
        {   KC_LCTL,   KC_LWIN,   KC_LALT,   KC_NO,     KC_NO,     KC_NO,     KC_SPC,    KC_NO,     KC_NO,     KC_NO,     KC_RALT,   KC_RWIN,   KC_MOFN,   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT }
     },

    [WIN_FN] = { // Windows Fn overlay
        /*  0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16   */
        {   RESET,     KC_BRID,   KC_BRIU,   KC_KACT,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     _______,   _______,   RGB_MOD },
        {   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ },
        {   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ },
        {   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_NO,     _______,   KC_NO,     KC_NO,     KC_NO   },
        {   _______,   KC_NO,     _______,   _______,   _______,   _______,   RST_KB,    _______,   _______,   _______,   _______,   _______,   KC_NO,     _______,   KC_NO,     RGB_SPI,   KC_NO   },
        {   _______,   _______,   _______,   KC_NO,     KC_NO,     KC_NO,     _______,   KC_NO,     KC_NO,     KC_NO,     _______,   _______,   _______,   _______,   RGB_SAI,   RGB_SPD,   RGB_SAD }
    },

    [WIN_CAPS] = {
        /*  0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16   */
        {   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_NO,     _______,   _______,   _______ },
        {   _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_F12,    _______,   _______,   _______ },
        {   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_PWRD,   KC_HOME,   KC_END,    KC_NWRD,   _______,   _______,   _______,   _______,   _______,   _______ },
        {   _______,   _______,   _______,   KC_BTN4,   KC_BTN5,   _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_SHIN,   KC_BTN3,   KC_NO,     _______,   KC_NO,     KC_NO,     KC_NO   },
        {   _______,   KC_NO,     _______,   _______,   _______,   _______,   _______,   _______,   KC_BWRD,   KC_BSPC,   KC_DEL,    KC_DWRD,   KC_NO,     _______,   KC_NO,     _______,   KC_NO   },
        {   _______,   _______,   _______,   KC_NO,     KC_NO,     KC_NO,     _______,   KC_NO,     KC_NO,     KC_NO,     _______,   _______,   _______,   _______,   _______,   _______,   _______ }
    },

    /*  Mac layout
    +-------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|SIRI|RGB |
    +--------------------------------------------------------------------------+ +--------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP|
    +--------------------------------------------------------------------------+ +--------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
    +--------------------------------------------------------------------------+ +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
    +--------------------------------------------------------------------------+      +----+    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+ +--------------+
    |LCTRL| LALT| LGUI |            SPACE            | RGUI| RALT | FN | RCTRL | |LFT |DWN |RGT |
    +-------------------------------------------------------------------------------------------+
    */

    [MAC_BASE] = { // Mac base layout
        /*  0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16     */
        {   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_MSCR,  KC_SIRI,  RGB_MOD },
        {   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP },
        {   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN },
        {   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   KC_NO,    KC_NO,    KC_NO   },
        {   KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  KC_NO,    KC_UP,    KC_NO   },
        {   KC_LCTL,  KC_LALT,  KC_LGUI,  KC_NO,    KC_NO,    KC_NO,    KC_SPC,   KC_NO,    KC_NO,    KC_NO,    KC_RGUI,  KC_RALT,  MO(3),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT }
    },

    [MAC_FN] = { // Mac Fn overlay
        /*  0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16     */
        {   RESET,    KC_BRID,  KC_BRIU,  KC_MSSN,  KC_FIND,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  KC_MSNP,  _______,  RGB_TOG },
        {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ },
        {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ },
        {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO   },
        {   _______,  KC_NO,    _______,  _______,  _______,  _______,  RST_KB,   _______,  _______,  _______,  _______,  _______,  KC_NO,    _______,  KC_NO,    RGB_HUI,  KC_NO   },
        {   _______,  _______,  _______,  KC_NO,    KC_NO,    KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO,    _______,  _______,  _______,  _______,  RGB_SAD,  RGB_HUD,  RGB_SAI }
    }

};

bool muted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t ptt_timer;
    switch (keycode) {
        case RST_KB:
            NVIC_SystemReset();
            return false;
        case KC_PTT:
            if(record->event.pressed) {
                ptt_timer = timer_read();
                tap_code(KC_MIC);
                muted = !muted;
            } else {
                if (timer_elapsed(ptt_timer) > PTT_TAPPING_TERM) {
                    tap_code(KC_MIC);
                    muted = !muted;
                }
            }
            if (muted) {
                // pulsating red light when mic muted
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
                rgb_matrix_set_color_all(RGB_RED);
                rgb_matrix_set_speed_noeeprom(255);
                rgb_matrix_enable_noeeprom();
            } else {
                rgb_matrix_disable_noeeprom();
            }
            return false; // keypress handled
    }
    return true; // keypress not handled
}

// combos, change COMBO_COUNT in config.h before adding combos!
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_jk, KC_ESC),
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for right shift, twice for Ctrl+;, the vscode leader
    [TD_VSTS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, LCTL(KC_SCLN)),
};
