#include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _CODE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_CODE,
    KC_CTGL, // code toggle
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| PLAY  |    |  N/A  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  | ALT  | CTRL |Space | / CODE  /       \ CTGL \  |Enter | BSPC |  [   |  ]   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------.                   ,-----------------------------------------------.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                     KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
  //|-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                     KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL ,
  //|-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------|
     KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                     KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------|  ===  |   |  ===  |-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_MPLY,    XXXXXXX, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------|  ===  |   |  ===  |-------+-------+-------+-------+-------+-------|
                     KC_LGUI,KC_LALT,KC_LCTL,KC_SPC ,KC_CODE,    KC_CTGL,KC_ENT ,KC_BSPC,KC_LBRC,KC_RBRC
  //                \-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------/
),

/* CODE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Ins  | Home |  Up  | End  |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |  Del |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_CODE] = LAYOUT(
  //,-----------------------------------------------.                   ,-----------------------------------------------.
     KC_GRV , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------|
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    KC_INS ,KC_HOME, KC_UP ,KC_END ,XXXXXXX,KC_F12 ,
  //|-------+-------+-------+-------+-------+-------|                   |-------+-------+-------+-------+-------+-------|
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
  //|-------+-------+-------+-------+-------+-------|  ===  |   |  ===  |-------+-------+-------+-------+-------+-------|
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,    _______,XXXXXXX,XXXXXXX,_______,_______,KC_BSLS,_______,
  //|-------+-------+-------+-------+-------+-------|  ===  |   |  ===  |-------+-------+-------+-------+-------+-------|
                     _______,_______,_______,_______,_______,    _______,_______,KC_DEL ,_______,_______
  //                \-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------/
),

};



#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Laura\nDell"), false);

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _CODE:
            oled_write_ln_P(PSTR("Code"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
      oled_write_ln_P(PSTR("CAPS"), false);
    }
    else {
      oled_write_ln_P(PSTR(""), false); // we have to overwrite this line in a buffer I guess?
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool is_code_pressed = false;
bool is_code_toggled = false;

void update_code_state(void) {

  bool current_code_state = layer_state_is(_CODE);
  bool desired_code_state = is_code_pressed != is_code_toggled;

  if (desired_code_state != current_code_state) {
    if (current_code_state) {
      layer_off(_CODE);
    }
    else {
      layer_on(_CODE);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CODE:
          is_code_pressed = record->event.pressed;
          update_code_state();
          return false;
        case KC_CTGL:
          if (record->event.pressed) {
            is_code_toggled = !is_code_toggled;
            update_code_state();
          }
          return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
				if (clockwise) {
					tap_code(KC_PGDN);
				} else {
					tap_code(KC_PGUP);
				}
    }
    return true;
}

#endif
