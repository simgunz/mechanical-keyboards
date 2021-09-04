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
    WIN_BASE = 0,
    WIN_FN = 1,
    WIN_CAPS = 2,
};

// layer modifiers
#define KC_MOFN MO(WIN_FN)
#define KC_MOCP LT(WIN_CAPS, KC_CAPS)

// media keys
#define KC_TASK LWIN(KC_Q)
#define KC_FLXP LWIN(KC_E)
#define KC_MIC LWIN(KC_MUTE)

// key combinations
#define KC_PWRD LCTL(KC_LEFT)
#define KC_NWRD LCTL(KC_RIGHT)
#define KC_BWRD LCTL(KC_BSPC)
#define KC_DWRD LCTL(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
				+--------------------------------------------------------------------------+----------------+
				| ESC |    | F1 | F2 | F3 | F4 |  | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |PSCR|SCRL|PAUS|
				+---------------------------------------------------------------------------+------|----|----|
 				|  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP  | |INS |HOME|PGUP|
 				+---------------------------------------------------------------------------+------|----|----|
 				|  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \   | |DEL |END |PGDN|
 				+---------------------------------------------------------------------------+------|----|----|
 				| CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN   |                |
 				+---------------------------------------------------------------------------+      |----|    |
 				| LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT     |      | UP |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|LCTRL| LWIN| LALT |            SPACE            | RALT| RWIN | FN | RCTRL  | |LFT |DWN |RGT |
 				+---------------------------------------------------------------------------+----------------+
*/
    /*  Row:        0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16    */
    [WIN_BASE] = {
                {   KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     KC_PSCR,   KC_MIC,    RGB_TOG  },
                {   KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_INS,    KC_HOME,   KC_PGUP },
                {   KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL,    KC_END,    KC_PGDN },
                {   KC_MOCP,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_NO,     KC_NO   },
                {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_NO,     KC_UP,     KC_NO   },
                {   KC_LCTL,   KC_LWIN,   KC_LALT,   KC_NO,     KC_NO,     KC_NO,     KC_SPC,    KC_NO,     KC_NO,     KC_NO,     KC_RALT,   KC_RWIN,   KC_MOFN,   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT }
            },
/*
				+--------------------------------------------------------------------------+----------------+
				| RST |    |    |    |    |    |  |    |    |    |    | |    |    |    |    | |    |    |    |
				+---------------------------------------------------------------------------+------|----|----|
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |         | |    |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|       |    |    |    |    |    |    |    |    |    |    |    |    |       | |    |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|          |    |    |    |    |    |    |    |    |    |   |   |           |                |
 				+---------------------------------------------------------------------------+      |----|    |
 				|            |    |    |    |    |    |    |    |   |   |    |              |      |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|     |     |      |                             |     |      |    |        | |    |    |    |
 				+---------------------------------------------------------------------------+----------------+
*/
    /*  Row:        0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16   */
    [WIN_FN] = {
                {   RESET,     KC_BRID,   KC_BRIU,   KC_TASK,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,     KC_TRNS,   KC_TRNS,   RGB_MOD },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO   },
                {   KC_TRNS,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_TRNS,   KC_NO,     RGB_SPI,   KC_NO   },
                {   KC_TRNS,   KC_LALT,   KC_LWIN,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   RGB_SAI,   RGB_SPD,   RGB_SAD }
            },
/*
				+--------------------------------------------------------------------------+----------------+
				|     |    |    |    |    |    |  |    |    |    |    | |    |    |    |    | |    |    |    |
				+---------------------------------------------------------------------------+------|----|----|
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |         | |    |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|       |    |    |    |    |    |    |    |    |    |    |    |    |       | |    |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|          |    |    |    |    |    |    |    |    |    |   |   |           |                |
 				+---------------------------------------------------------------------------+      |----|    |
 				|            |    |    |    |    |    |    |    |   |   |    |              |      |    |    |
 				+---------------------------------------------------------------------------+------|----|----|
 				|     |     |      |                             |     |      |    |        | |    |    |    |
 				+---------------------------------------------------------------------------+----------------+
*/
    /*  Row:        0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16   */
    [WIN_CAPS] = {
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS },
                {   KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_F12,    KC_TRNS,   KC_TRNS,   KC_TRNS },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_PWRD,   KC_HOME,   KC_END,    KC_NWRD,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_TRNS,   KC_TRNS,   KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO   },
                {   KC_TRNS,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_BWRD,   KC_BSPC,   KC_DEL,    KC_DWRD,   KC_NO,     KC_TRNS,   KC_NO,     KC_TRNS,   KC_NO   },
                {   KC_TRNS,   KC_LALT,   KC_LWIN,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS }
            }
};

// combos, change COMBO_COUNT in config.h before adding combos!
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_jk, KC_ESC),
};

void dip_switch_update_user(uint8_t index, bool active){
  index = 1;
  if(active) { //Mac mode
    writePin(LED_NUM_LOCK_PIN, 0);
    writePin(LED_SCROLL_LOCK_PIN, 1);
    //layer_move(0);
  } else { //Windows mode
    writePin(LED_NUM_LOCK_PIN, 1);
    writePin(LED_SCROLL_LOCK_PIN, 0);
    layer_move(WIN_BASE);
  }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}