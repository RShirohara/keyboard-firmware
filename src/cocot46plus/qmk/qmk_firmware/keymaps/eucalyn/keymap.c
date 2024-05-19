/*
Copyright 2022 aki27

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
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};


// Tap Dance declarations
enum {
    TD_IME
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_IME] = ACTION_TAP_DANCE_DOUBLE(KC_LNG2, KC_LNG1)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
       KC_TAB,    KC_Q,    KC_W, KC_COMM,  KC_DOT, KC_SCLN,                                 KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, KC_BSPC,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                                 KC_G,    KC_T,    KC_K,    KC_S,    KC_N, KC_SLSH,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,                                 KC_B,    KC_H,    KC_J,    KC_L, KC_QUOT,  KC_ESC,
  //|--------|--------|--------|--------|--------|--------||--------|        |--------||--------|--------|--------|--------|--------|--------|
                        KC_LALT, KC_LGUI,TD(TD_IME),KC_SPC,  KC_BTN1,          KC_BTN2,   KC_ENT,   MO(1), KC_RALT,   MO(3),
                   //||--------|--------|--------|--------||--------|--------|--------||--------|--------|--------|--------||
                                                             KC_WH_U, KC_BTN3, KC_WH_D,  XXXXXXX, XXXXXXX, XXXXXXX
                                                        //||--------|--------|--------||--------|--------|--------||
    ),
  [_LOWER] = LAYOUT(
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
       KC_TAB, XXXXXXX,    KC_1,    KC_2,    KC_3, KC_MINS,                               KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LCTL, XXXXXXX,    KC_4,    KC_5,    KC_6, KC_LBRC,                              KC_RBRC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LSFT, XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_GRV, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ESC,
  //|--------|--------|--------|--------|--------|--------||--------|        |--------||--------|--------|--------|--------|--------|--------|
                        KC_LALT, KC_LGUI,   MO(2),  KC_SPC,  KC_BTN4,          KC_BTN5,   KC_ENT, _______, KC_RALT, XXXXXXX,
                   //||--------|--------|--------|--------||--------|--------|--------||--------|--------|--------|--------||
                                                             KC_WH_L, KC_BTN3, KC_WH_R,  XXXXXXX, XXXXXXX, XXXXXXX
                                                        //||--------|--------|--------||--------|--------|--------||
    ),
  [_RAISE] = LAYOUT(
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                              KC_PSCR, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, KC_BSPC,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                              XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_SLSH,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      KC_LSFT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                              XXXXXXX, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,  KC_ESC,
  //|--------|--------|--------|--------|--------|--------||--------|        |--------||--------|--------|--------|--------|--------|--------|
                        KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_BTN1,          KC_BTN2,   KC_ENT, _______, KC_RALT, XXXXXXX,
                   //||--------|--------|--------|--------||--------|--------|--------||--------|--------|--------|--------||
                                                             KC_WH_L, KC_BTN3, KC_WH_R,  XXXXXXX, XXXXXXX, XXXXXXX
                                                        //||--------|--------|--------||--------|--------|--------||
    ),
  [_TRACKBALL] = LAYOUT(
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                              XXXXXXX,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                              XXXXXXX, SCRL_TO, SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------|--------|--------|--------|--------|--------||--------|        |--------||--------|--------|--------|--------|--------|--------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_BTN1,          KC_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
                   //||--------|--------|--------|--------||--------|--------|--------||--------|--------|--------|--------||
                                                             KC_WH_L, KC_BTN3, KC_WH_R,  XXXXXXX, XXXXXXX, XXXXXXX
                                                        //||--------|--------|--------||--------|--------|--------||
    )
//   [_Layer4] = LAYOUT(
//   //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------|--------|--------|--------|--------|--------||                          ||--------|--------|--------|--------|--------|--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------|--------|--------|--------|--------|--------||--------|        |--------||--------|--------|--------|--------|--------|--------|
//                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                    //||--------|--------|--------|--------||--------|--------|--------||--------|--------|--------|--------||
//                                                              XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
//                                                         //||--------|--------|--------||--------|--------|--------||
//     )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (encoder1_ccw.pressed) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (encoder1_cw.pressed) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif
