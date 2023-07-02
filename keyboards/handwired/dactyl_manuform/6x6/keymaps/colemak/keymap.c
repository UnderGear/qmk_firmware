#include QMK_KEYBOARD_H


#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define DEFAULT MO(_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_6x6(

      KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
      KC_GRV, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
      KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , KC_EQL,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_BSLS,
                     KC_LPRN,KC_RPRN,                                                        KC_LBRC,KC_RBRC,
                                      RAISE, KC_SPC,                         KC_SPC, LOWER,
                                             KC_LCTL,KC_LSFT,        KC_DEL ,KC_BSPC,
                                             KC_LALT, KC_ESC,        KC_RGUI, KC_ENT
  ),

  [_LOWER] = LAYOUT_6x6( //right hand is a numpad

     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        KC_CIRC,KC_PERC,KC_PSLS,KC_PAST,KC_PEQL,KC_LABK,
     _______,_______,_______,_______,_______,_______,                        KC_PIPE, KC_P7 , KC_P8 , KC_P9 ,KC_PMNS,KC_RABK,
     _______,_______,_______,_______,_______,_______,                        KC_AMPR, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS,KC_LPRN,
     _______,_______,_______,_______,_______,_______,                        KC_EXLM, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,KC_RPRN,
                     _______,_______,                                                         KC_P0 ,KC_PDOT, 
                                     _______,_______,                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),

  [_RAISE] = LAYOUT_6x6( //media controls and navigation

       _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______,_______,
       _______,_______,KC_HOME, KC_UP , KC_END,_______,                      _______,KC_MUTE,KC_VOLU,KC_MSTP,_______,_______,
       _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,                      _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,
       _______,KC_UNDO,KC_CUT ,KC_COPY,KC_PSTE,_______,                      _______,_______,KC_VOLD,_______,_______,_______,
                       _______,_______,                                                      _______,_______,
                                       _______,_______,                      _______,_______,
                                               _______,_______,      _______,_______,
                                               _______,_______,      _______,_______
  ),

};
