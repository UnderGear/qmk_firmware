#include QMK_KEYBOARD_H


#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define DEFAULT MO(_DEFAULT)

enum custom_keycodes {
    KC_PRWD = SAFE_RANGE,
    KC_NXWD,
    KC_DLIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_6x6(

     KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
     KC_GRV, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB, KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_EQL ,
    KC_LSFT, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                         KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
    KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_K  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                    KC_LPRN,KC_RPRN,                                                        KC_LBRC,KC_RBRC,
                                     RAISE ,KC_SPC ,                        KC_SPC , LOWER,
                                            KC_LCTL,KC_LSFT,        KC_DEL ,KC_BSPC,
                                            KC_LALT,KC_ESC ,        KC_RGUI,KC_ENT
  ),

  [_LOWER] = LAYOUT_6x6( //right hand is a numpad

    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        KC_CIRC,KC_PERC,KC_PSLS,KC_PAST,KC_PEQL,KC_LABK,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        KC_PIPE, KC_P7 , KC_P8 , KC_P9 ,KC_PMNS,KC_RABK,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        KC_AMPR, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS,KC_LPRN,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        KC_EXLM, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,KC_RPRN,
                    XXXXXXX,XXXXXXX,                                                         KC_P0 ,KC_PDOT, 
                                    XXXXXXX,XXXXXXX,                        XXXXXXX,_______,
                                            XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX
  ),

  [_RAISE] = LAYOUT_6x6( //media controls and navigation

    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,XXXXXXX,KC_PGUP,XXXXXXX,XXXXXXX,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_PRWD, KC_UP ,KC_NXWD,XXXXXXX,                      XXXXXXX,KC_MUTE,KC_VOLU,KC_MSTP,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,                      XXXXXXX,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_END ,XXXXXXX,                      XXXXXXX,XXXXXXX,KC_VOLD,XXXXXXX,XXXXXXX,XXXXXXX,
                    XXXXXXX,XXXXXXX,                                                      XXXXXXX,XXXXXXX,
                                    _______,XXXXXXX,                      XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLIN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

