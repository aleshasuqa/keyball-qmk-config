/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "oled_driver.h"
#include QMK_KEYBOARD_H
#include "keyball44/keyball44.h"

#include "quantum.h"
#include "c_keycodes.h"
#include "c_layers.h"

// #define BASE 0
// #define NAV 1
// #define NUM 2
// #define FUN 3
// #define GAME 4

#define SF_BS MT(MOD_LSFT,KC_BSPC)
#define NNNN KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default

  [BASE] = LAYOUT_universal( // BASE
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,    KC_B     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_SCLN   ,    QK_REP   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_ESC    ,    KC_A     ,    KC_R     ,    KC_S     ,    KC_T     ,    KC_G     ,        KC_M     ,    KC_N     ,    KC_E     ,    KC_I     ,     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_D     ,    KC_V     ,        KC_K     ,    KC_H     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    KC_UNDS  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    TO(FUN)   ,   TO(NUM)   ,  OSL(SYM)   ,LT(NAV,KC_SPC),OSM(MOD_LSFT),      KC_BSPC   ,   OSL(NAV)  ,  _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NAV] = LAYOUT_universal( // NAV
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
       KC_F1    ,    KC_F2    ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,        KC_F7    ,    KC_F8    ,    KC_F9    ,    KC_F10   ,    KC_F11   ,    KC_F12   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        NNNN    ,    KC_A     ,OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LGUI),   KC_F11    ,       KC_LEFT   ,   KC_DOWN   ,    KC_UP    ,   KC_RGHT   ,     KC_O    ,    KC_F12   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      TO(FUN)   ,    KC_Z     ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,       KC_BTN4   ,   KC_BTN1   ,   SCRL_MO   ,   KC_BTN2   ,   KC_BTN5   ,   TO(NUM)   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    TO(GAME)  ,   TO(FUN)   ,   KC_ESC    ,   NUMWORD   ,   KC_LSFT   ,       KC_BSPC   ,   NUMWORD   ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NUM] = LAYOUT_universal( // NUM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
     _______    ,  _______    ,  _______    ,   _______   ,  _______    ,   _______   ,       _______   ,   _______   ,   _______   ,   _______   ,   _______   ,  _______    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,    KC_6     ,    KC_4     ,     KC_2    ,    KC_0     ,   _______   ,       _______   ,     KC_1    ,     KC_3    ,     KC_5    ,     KC_7    ,  _______    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,  _______    ,  _______    ,   _______   ,    KC_8     ,   _______   ,       _______   ,     KC_9    ,   _______   ,   _______   ,   _______   ,  _______    ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,    KC_ESC   ,   KC_SPC    ,   KC_LSFT   ,       KC_BSPC   ,   TO(BASE)  ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [SYM] = LAYOUT_universal( // SYM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
     _______    ,  _______    ,  KC_PERC    ,   KC_ASTR   ,   KC_CIRC   ,   _______   ,       _______   ,   KC_DLR    ,   KC_AT     ,   KC_HASH   ,   _______   ,  _______    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,   KC_EXLM   ,  KC_MINS    ,   KC_PLUS   ,   KC_EQL    ,    KC_GT    ,       KC_SCLN   ,   KC_LPRN   ,   KC_LCBR   ,   KC_LBRC   ,   KC_BSLS   ,  _______    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,  _______    ,  _______    ,   KC_PIPE   ,   KC_AMPR   ,    KC_LT    ,       _______   ,   KC_RPRN   ,   KC_RCBR   ,   KC_RBRC   ,   _______   ,  _______    ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,    KC_ESC   ,   KC_SPC    ,   KC_LSFT   ,       KC_RSFT   ,   KC_ENT    ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [FUN] = LAYOUT_universal( // FUN
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      QK_BOOT   ,    KC_F2    ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,       RGB_MOD   ,   RGB_HUI   ,   RGB_SAI   ,   RGB_VAI   ,   KC_SCLN   ,   QK_BOOT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        NNNN    ,    KC_A     ,    KC_F4    ,    KC_F5    ,    KC_F6    ,   KC_F11    ,       RGB_RMOD  ,OSM(MOD_LGUI),OSM(MOD_LCTL),OSM(MOD_LALT),     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      TO(FUN)   ,    KC_Z     ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,       RGB_TOG   ,   RGB_M_P   ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    TO(2)    ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    TO(GAME)  ,   TO(FUN)   ,   KC_ESC    ,   KC_SPC    ,   KC_LSFT   ,        SF_BS    ,    KC_ENT   ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [GAME] = LAYOUT_universal(
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_ESC    ,    KC_Q     ,    KC_R     ,    KC_W     ,    KC_E     ,    KC_G     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_SCLN   ,    KC_DEL   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_T     ,    KC_A     ,    KC_S     ,    KC_D     ,    KC_F     ,     RALT_T(KC_H), RGUI_T(KC_N), RCTL_T(KC_E),    KC_I     ,     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_LCTL   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_K     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    TO(NUM)  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,   KC_LCTL   ,   KC_SPC    ,   KC_LSFT   ,        SF_BS   ,LT(BASE,KC_ENT),   _______   ,   _______  ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),
};

//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      // QK_BOOT   ,  KBC_SAVE   ,    KC_W     ,   AML_I50   ,  SCRL_DVI   ,  CPI_I100   ,                                                                                                                                                                           // clang-format on
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      // KC_LCTL   ,   KBC_RST   ,    KC_R     ,   AML_D50   ,  SCRL_DVD   ,  CPI_D100   ,                                                                                                                                                                           layer_state_t layer_state_set_user(layer_state_t state) {
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                                                                                                                                                                               // Auto enable scroll mode when the highest layer is 3
      // QK_MAKE   ,    KC_Z     ,    KC_X     ,  SSNP_VRT   ,  SSNP_VRT   ,   AML_TO    ,                                                                                                                                                                               keyball_set_scroll_mode(get_highest_layer(state) == 3);
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                                                                                                                                                                               return state;
                    // KC_LALT   ,   KC_LGUI   ,   KC_ESC    ,   KC_SPC    ,   KC_LSFT   ,                                                                                                                                                                           }
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯
  // ),                                                                                                                                                                                                                                                              __attribute__ ((weak))
bool process_record_user_kb(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#include "macros/num_word.h"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_num_word(keycode, record)) {
        return false;
    }
    return process_record_user_kb(keycode, record);
}

#ifdef OLED_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_270;
}

#include "keyball/lib/keyball/keyball.h"

void master_render(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

// #include "animation.h"
// #define FRAME_DURATION 200

// uint32_t timer = 0;
// uint8_t c_frame = 0;

// void periph_render(void) {
//     render_anim();
// }

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        master_render();
    }
    // else
    // {
    //     periph_render();
    // }

    return false;
}
#endif
