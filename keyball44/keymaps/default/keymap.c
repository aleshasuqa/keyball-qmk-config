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

#include QMK_KEYBOARD_H
#include "keyball44/keyball44.h"

#include "quantum.h"

#define BASE 0
#define NAV 1
#define NUM 2
#define FUN 3

#define SF_BS MT(MOD_LSFT,KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default

  [BASE] = LAYOUT_universal( // BASE
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,    KC_G     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_SCLN   ,    KC_DEL   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_A     ,    KC_R     , LCTL_T(KC_S), LGUI_T(KC_T), LALT_T(KC_D),     RALT_T(KC_H), RGUI_T(KC_N), RCTL_T(KC_E),    KC_I     ,     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_LCTL   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_K     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    TO(NUM)  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI  ,LT(NAV,KC_ESC),LT(NUM,KC_SPC),OSM(MOD_LSFT),        SF_BS   ,LT(NUM,KC_ENT),   _______   ,   _______  ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NAV] = LAYOUT_universal( // NAV
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
       KC_F1    ,    KC_F2    ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,        KC_F7    ,    KC_F8    ,    KC_F9    ,    KC_F10   ,    KC_F11   ,    KC_F12   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_LCTL   ,    KC_A     ,    KC_F4    ,    KC_F5    ,    KC_F6    ,   KC_F11    ,       KC_LEFT   ,   KC_DOWN   ,    KC_UP    ,   KC_RGHT   ,     KC_O    ,    KC_F12   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      TO(FUN)   ,    KC_Z     ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,       KC_BTN4   ,   KC_BTN1   ,   SCRL_MO   ,   KC_BTN2   ,   KC_BTN5   ,   TO(NUM)   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,   KC_ESC    ,   KC_SPC    ,   KC_LSFT   ,        SF_BS    ,   KC_ENT    ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NUM] = LAYOUT_universal( // NUM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
     _______    ,   KC_HASH   ,    KC_7     ,     KC_8    ,    KC_9     ,     KC_0    ,       KC_AMPR   ,   KC_ASTR   ,   KC_LPRN   ,   KC_RPRN   ,   KC_DOT    ,   KC_BSLS   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,    KC_AT    ,    KC_4     ,     KC_5    ,    KC_6     ,   KC_PERC   ,       KC_MINS   ,   KC_PLUS   ,   KC_LCBR   ,   KC_RCBR   ,   KC_TILD   ,   KC_PIPE   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
     _______    ,   KC_EXLM   ,    KC_1     ,     KC_2    ,    KC_3     ,    KC_DLR   ,       KC_UNDS   ,    KC_EQL   ,    KC_EQL   ,   KC_LBRC   ,   KC_RBRC   ,  S(KC_INT3) ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,    KC_ESC   ,   KC_SPC    ,   KC_LSFT   ,        SF_BS    ,   KC_ENT    ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [FUN] = LAYOUT_universal( // FUN
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      QK_BOOT   ,  KBC_SAVE   ,    KC_W     ,   AML_I50   ,  SCRL_DVI   ,  CPI_I100   ,       RGB_MOD   ,   RGB_HUI   ,   RGB_SAI   ,   RGB_VAI   ,   KC_SCLN   ,   QK_BOOT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_LCTL   ,   KBC_RST   ,    KC_R     ,   AML_D50   ,  SCRL_DVD   ,  CPI_D100   ,       RGB_RMOD  ,   RGB_HUD   ,   RGB_SAD   ,   RGB_VAD   ,     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      _______   ,    KC_Z     ,    KC_X     ,  SSNP_VRT   ,  SSNP_VRT   ,   AML_TO    ,       RGB_TOG   ,   RGB_M_P   ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    TO(2)    ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,   KC_ESC    ,   KC_SPC    ,   KC_LSFT   ,        SF_BS    ,    KC_ENT   ,   _______   ,   _______   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

// #    include "lib/oledkit/oledkit.h"
//
// void oledkit_render_info_user(void) {
//     //keyball_oled_render_keyinfo();
//     //keyball_oled_render_ballinfo();
//     keyball_oled_render_layerinfo();
// }
#include "animation.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : rotation;
}

void master_render(void) {
    oled_set_cursor(0, 1);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write("BASE", false);
            break;
        case NAV:
            oled_write("NAV", false);
            break;
        case NUM:
            oled_write("NUM", false);
            break;
        case FUN:
            oled_write("FUN", false);
            break;
    }

}

#define FRAME_DURATION 200

uint32_t timer = 0;
uint8_t c_frame = 0;

static void render_anim(void) {

    uint16_t frame_sizes[2] = {
        sizeof(epd_bitmap_frame_0),
        sizeof(epd_bitmap_frame_1)
    };

    // Run animation
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated time
        timer = timer_read();

        // Increment frame
        c_frame = (c_frame + 1) % (sizeof(epd_bitmap_allArray) / sizeof(epd_bitmap_allArray[0]));

        // Draw frame to OLED
        oled_write_raw_P(epd_bitmap_allArray[c_frame], frame_sizes[c_frame]);
    }
}

void periph_render(void) {
    render_anim();
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        master_render();
    } else {
        periph_render();
    }

    return false;
}
#endif
