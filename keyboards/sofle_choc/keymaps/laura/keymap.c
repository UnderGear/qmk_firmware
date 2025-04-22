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
    KC_RGBS
};

enum rgb_encoder_selection {
    EN_HUE = 0,
    EN_SAT,
    EN_VAL,
    EN_SPEED,
    EN_MODE,
    EN_ENABLE,
    EN_COUNT
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
 * |------+------+------+------+------+------| PLAY  |    |  RGB  |------+------+------+------+------+------|
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
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_MPLY,    KC_RGBS, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------|  ===  |   |  ===  |-------+-------+-------+-------+-------+-------|
                     KC_LCTL,KC_LALT,KC_LGUI,KC_SPC ,KC_CODE,    KC_CTGL,KC_ENT ,KC_BSPC,KC_LBRC,KC_RBRC
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

rgb_encoder_selection current_selection = EN_HUE;

#ifdef OLED_ENABLE

static void render_rgb_status(void) {
    oled_write_P(PSTR("H "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_hue(), ' '), false);

    oled_write_P(PSTR("S "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_sat(), ' '), false);

    oled_write_P(PSTR("V "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_val(), ' '), false);

    oled_write_P(PSTR("Sp"), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_speed(), ' '), false);

    oled_write_P(PSTR("M "), false);
    if (rgb_matrix_is_enabled())
    {
        oled_write_ln(get_u8_str(rgb_matrix_get_mode(), ' '), false);
    }
    else
    {
        oled_write_ln_P(PSTR("Off"), false);
    }

    oled_write_ln_P(PSTR("Edit"), false);
    switch (current_selection) {
    case EN_HUE:
      oled_write_ln_P(PSTR("Hue"), false);
      break;
    case EN_SAT:
      oled_write_ln_P(PSTR("Sat"), false);
      break;
    case EN_VAL:
      oled_write_ln_P(PSTR("Val"), false);
      break;
    case EN_SPEED:
      oled_write_ln_P(PSTR("Speed"), false);
      break;
    case EN_MODE:
      oled_write_ln_P(PSTR("Mode"), false);
      break;
    case EN_ENABLE:
      oled_write_ln_P(PSTR("OnOff"), false);
      break;
    }
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Laura\nDell"), false);

    oled_write_P(PSTR("\n\n\n"), false);

    // Print state info
    int extra_lines = 0;
    if (get_highest_layer(layer_state) == _CODE) {
      oled_write_ln_P(PSTR("CODE"), false);
    }
    else {
      ++extra_lines;
    }

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
      oled_write_ln_P(PSTR("CAPS"), false);
    }
    else {
      ++extra_lines;
    }

    // we have to overwrite these lines in a buffer I guess
    for (int i = 0; i < extra_lines; ++i) {
      oled_write_ln_P(PSTR(""), false);
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
        render_rgb_status();
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
        case KC_RGBS:
          if (record->event.pressed) {
            // toggle through selected rgb parameter
            ++current_selection;
            current_selection %= EN_COUNT;
          }
          return false;
    }
    return true;
}

void encoder_rgb_up(void) {
  switch (current_selection) {
    case EN_HUE:
      rgb_matrix_increase_hue();
      break;
    case EN_SAT:
      rgb_matrix_increase_sat();
      break;
    case EN_VAL:
      rgb_matrix_increase_val();
      break;
    case EN_SPEED:
      rgb_matrix_increase_speed();
      break;
    case EN_MODE:
      rgb_matrix_step();
      break;
    case EN_ENABLE:
      rgb_matrix_enable();
      break;
  }
}

void encoder_rgb_down(void) {
  switch (current_selection) {
    case EN_HUE:
      rgb_matrix_decrease_hue();
      break;
    case EN_SAT:
      rgb_matrix_decrease_sat();
      break;
    case EN_VAL:
      rgb_matrix_decrease_val();
      break;
    case EN_SPEED:
      rgb_matrix_decrease_speed();
      break;
    case EN_MODE:
      rgb_matrix_step_reverse();
      break;
    case EN_ENABLE:
      rgb_matrix_disable();
      break;
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            encoder_rgb_up();
        } else {
            encoder_rgb_down();
        }
    }
    return false;
}
