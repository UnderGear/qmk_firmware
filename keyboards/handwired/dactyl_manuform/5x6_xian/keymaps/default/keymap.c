#include QMK_KEYBOARD_H

#include "RTC.h"

#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2

#define DEFAULT MO(_DEFAULT)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum custom_keycodes
{
    KC_PRWD = SAFE_RANGE, // previous word
    KC_NXWD, // next word
    KC_DLIN, // delete line
    RM_RSET, // matrix color reset
    RM_SPUE, // speed up / RTC month up
    RM_SPDE, // speed down / RTC month down
    RM_HUUE, // hue up / RTC day of month up
    RM_HUDE, // hue down / RTC day of month down
    RM_SAUE, // saturation up / RTC hour up
    RM_SADE, // saturation down / RTC hour down
    RM_VAUE, // value up / RTC minute up
    RM_VADE, // value down / RTC minute down
    RM_PRVE, // previous color mode / RTC day of week down
    RM_NXTE, // next color mode / RTC day of week up
    RM_SCOL, // modify colors
    RM_SRTC, // modify RTC
    RM_RTYU, // RTC year up
    RM_RTYD, // RTC year down
    RM_RTSU, // RTC second up
    RM_RTSD // RTC second down
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

  [_DEFAULT] = LAYOUT_5x6(

     KC_GRV, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB, KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_EQL ,
    KC_LSFT, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                         KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
    KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_K  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                    KC_LPRN,KC_RPRN,                                                        KC_LBRC,KC_RBRC,
                                     RAISE ,KC_SPC ,                        KC_SPC , LOWER,
                                            KC_LCTL,KC_LSFT,        KC_DEL ,KC_BSPC,
                                            KC_LALT,KC_ESC ,        KC_RGUI,KC_ENT
  ),

  [_LOWER] = LAYOUT_5x6( //right hand is a numpad, left hand modifies RGB matrix

    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        KC_CIRC,KC_PERC,KC_PSLS,KC_PAST,KC_PEQL,KC_LABK,
    RM_RTYU,RM_SPUE,RM_HUUE,RM_SAUE,RM_VAUE,RM_RTSU,                        KC_PIPE, KC_P7 , KC_P8 , KC_P9 ,KC_PMNS,KC_RABK,
    RM_RTYD,RM_SPDE,RM_HUDE,RM_SADE,RM_VADE,RM_RTSD,                        KC_AMPR, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS,KC_LPRN,
    XXXXXXX,RM_RSET,RM_TOGG,RM_PRVE,RM_NXTE,XXXXXXX,                        KC_EXLM, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,KC_RPRN,
                    RM_SCOL,RM_SRTC,                                                         KC_P0 ,KC_PDOT,
                                    XXXXXXX,XXXXXXX,                        XXXXXXX,_______,
                                            XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX
  ),

  [_RAISE] = LAYOUT_5x6( //media controls and navigation

    KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                        KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
    XXXXXXX,XXXXXXX,KC_PRWD, KC_UP ,KC_NXWD,XXXXXXX,                      XXXXXXX,KC_MUTE,KC_VOLU,KC_MSTP,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,                      XXXXXXX,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_END ,XXXXXXX,                      XXXXXXX,XXXXXXX,KC_VOLD,XXXXXXX,XXXXXXX,XXXXXXX,
                    XXXXXXX,XXXXXXX,                                                      XXXXXXX,XXXXXXX,
                                    _______,XXXXXXX,                      XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,
                                            XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX
  ),
};

void rgb_reset(void)
{
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
    rgb_matrix_set_speed(45);
    rgb_matrix_sethsv(HSV_RED);
}

bool mode_color = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case KC_PRWD:
            if (record->event.pressed)
            {
                if (keymap_config.swap_lctl_lgui)
                {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                }
                else
                {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            }
            else
            {
                if (keymap_config.swap_lctl_lgui)
                {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                }
                else
                {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXWD:
             if (record->event.pressed)
             {
                if (keymap_config.swap_lctl_lgui)
                {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                }
                else
                {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            }
            else
            {
                if (keymap_config.swap_lctl_lgui)
                {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                }
                else
                {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLIN:
            if (record->event.pressed)
            {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            }
            else
            {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed)
            {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            }
            else
            {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed)
            {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            }
            else
            {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed)
            {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            }
            else
            {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed)
            {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            }
            else
            {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case RM_RSET:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_reset();
                }
            }
            return false;
        case RM_SPUE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_increase_speed();
                }
                else
                {
                    increment_month();
                }
            }
            return false;
        case RM_SPDE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_decrease_speed();
                }
                else
                {
                    decrement_month();
                }
            }
            return false;
        case RM_HUUE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_increase_hue();
                }
                else
                {
                    increment_day_of_month();
                }
            }
            return false;
        case RM_HUDE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_decrease_hue();
                }
                else
                {
                    decrement_day_of_month();
                }
            }
            return false;
        case RM_SAUE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_increase_sat();
                }
                else
                {
                    increment_hours();
                }
            }
            return false;
        case RM_SADE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_decrease_sat();
                }
                else
                {
                    decrement_hours();
                }
            }
            return false;
        case RM_VAUE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_increase_val();
                }
                else
                {
                    increment_minutes();
                }
            }
            return false;
        case RM_VADE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_decrease_val();
                }
                else
                {
                    decrement_minutes();
                }
            }
            return false;
        case RM_PRVE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_step_reverse();
                }
                else
                {
                    decrement_day_of_week();
                }
            }
            return false;
        case RM_NXTE:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                    rgb_matrix_step();
                }
                else
                {
                    increment_day_of_week();
                }
            }
            return false;
        case RM_RTYU:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                }
                else
                {
                    increment_year();
                }
            }
            return false;
        case RM_RTYD:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                }
                else
                {
                    decrement_year();
                }
            }
            return false;
        case RM_RTSU:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                }
                else
                {
                    increment_seconds();
                }
            }
            return false;
        case RM_RTSD:
            if (record->event.pressed)
            {
                if (mode_color)
                {
                }
                else
                {
                    decrement_seconds();
                }
            }
            return false;
        case RM_SCOL:
            if (record->event.pressed)
            {
                mode_color = true;
            }
            return false;
        case RM_SRTC:
            if (record->event.pressed)
            {
                mode_color = false;
            }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE

const char *get_u8_str_2(uint8_t curr_num, char curr_pad)
{
    static char    buf[3]   = {0};
    static uint8_t last_num = 0xFF;
    static char    last_pad = '\0';
    if (last_num == curr_num && last_pad == curr_pad) {
        return buf;
    }
    last_num = curr_num;
    last_pad = curr_pad;
    return get_numeric_str(buf, sizeof(buf), curr_num, curr_pad);
}

static void print_layer_status(void)
{
    i2c_status_t read_status = read_rtc();
    if (read_status == I2C_STATUS_SUCCESS)
    {
        oled_write(get_u8_str_2(current_time.hours, '0'), false);
        oled_write_P(PSTR(":"), false);
        oled_write_ln(get_u8_str_2(current_time.minutes, '0'), false);

        switch(current_time.day_of_week)
        {
            case 0:
                oled_write_ln_P(PSTR("Sun"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Mon"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("Tue"), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("Wed"), false);
                break;
            case 4:
                oled_write_ln_P(PSTR("Thu"), false);
                break;
            case 5:
                oled_write_ln_P(PSTR("Fri"), false);
                break;
            case 6:
                oled_write_ln_P(PSTR("Sat"), false);
                break;
        }

        switch(current_time.month)
        {
            case 0:
                oled_write_P(PSTR("Jan"), false);
                break;
            case 1:
                oled_write_P(PSTR("Feb"), false);
                break;
            case 2:
                oled_write_P(PSTR("Mar"), false);
                break;
            case 3:
                oled_write_P(PSTR("Apr"), false);
                break;
            case 4:
                oled_write_P(PSTR("May"), false);
                break;
            case 5:
                oled_write_P(PSTR("Jun"), false);
                break;
            case 6:
                oled_write_P(PSTR("Jul"), false);
                break;
            case 7:
                oled_write_P(PSTR("Aug"), false);
                break;
            case 8:
                oled_write_P(PSTR("Sep"), false);
                break;
            case 9:
                oled_write_P(PSTR("Oct"), false);
                break;
            case 10:
                oled_write_P(PSTR("Nov"), false);
                break;
            case 11:
                oled_write_P(PSTR("Dec"), false);
                break;
        }
        oled_write_ln(get_u8_str_2(current_time.day_of_month, '0'), false);
        oled_write_ln(get_u16_str(current_time.year, ' '), false);
    }
    else
    {
        oled_write_ln_P(PSTR("\n"), false);
        oled_write_ln_P(PSTR("\n"), false);
        oled_write_ln_P(PSTR("\n"), false);
        oled_write_ln_P(PSTR("\n"), false);
    }
    oled_write_ln_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("Xian"), false);
    oled_write_ln_P(PSTR("\n"), false);

    oled_write_ln_P(PSTR("Layer"), false);

    if (IS_LAYER_ON(_DEFAULT))
    {
        oled_write_ln_P(PSTR("Main"), false);
    }
    else if (IS_LAYER_ON(_RAISE))
    {
        oled_write_ln_P(PSTR("Nav"), false);
    }
    else if (IS_LAYER_ON(_LOWER))
    {
        if (mode_color)
        {
            oled_write_ln_P(PSTR("Color"), false);
        }
        else
        {
            oled_write_ln_P(PSTR("Time"), false);
        }
    }
}

static void print_rgb_status(void)
{
    oled_write_P(PSTR("H "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_hue(), ' '), false);

    oled_write_P(PSTR("S "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_sat(), ' '), false);

    oled_write_P(PSTR("V "), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_val(), ' '), false);

    oled_write_P(PSTR("Sp"), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_speed(), ' '), false);

    oled_write_ln_P(PSTR("Mode"), false);
    if (rgb_matrix_is_enabled())
    {
        switch (rgb_matrix_get_mode())
        {
            case 1:
                oled_write_ln_P(PSTR("Solid"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("Cycle"), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("React"), false);
                break;
        }
    }
    else
    {
        oled_write_ln_P(PSTR("Off"), false);
    }

    oled_write_ln_P(PSTR("Layer"), false);

    if (IS_LAYER_ON(_DEFAULT))
    {
        oled_write_ln_P(PSTR("Main"), false);
    }
    else if (IS_LAYER_ON(_RAISE))
    {
        oled_write_ln_P(PSTR("Media"), false);
    }
    else if (IS_LAYER_ON(_LOWER))
    {
        oled_write_ln_P(PSTR("Num"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    rtc_init();
    return OLED_ROTATION_270;
}

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        print_layer_status();
    }
    else
    {
        print_rgb_status();
    }
    return false;
}

#endif
