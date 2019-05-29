#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define IS_WIN 0

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  JAN,
  WIN_L,
  WIN_R,
  SETS_L,
  SETS_R,
  WIN_TAB,
  TAB_NEXT,
  TAB_PREV,
  WINDOW_DEL,
  TILDE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |TABNEX|           |TABPRE|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  '   |           |  ;   |   Y  |   U  |   I  |   O  |   P  | B_space|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Layer  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  /   | Enter  |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |   ↑  | WIN_TAB|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL | Win  |      | Alt  |Layer |                                       | Jan  |      |   ←  |   ↓  |   →  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   -  |      |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|  ,   |------|       |------|   .    |   -  |
 *                                 |      |      | End  |       | Home |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TAB_NEXT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_QUOT,
        MO(SYMB),       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LBRC,
        KC_LCTRL,       KC_LGUI,      KC_NO,  KC_LALT,MO(MDIA),
                                                             KC_MINS, KC_NO,
                                                                      KC_NO,
                                                     KC_SPC, KC_COMM, KC_END,
        // right hand
        TAB_PREV,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_SCLN,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_BSPC,
                     KC_H,   KC_J,   KC_K,    KC_L,    KC_SLSH,   KC_ENT,
        KC_RBRC,     KC_N,   KC_M,   KC_NO,   KC_NO,   KC_UP,     WIN_TAB,
                             JAN,    KC_NO,   KC_LEFT, KC_DOWN,   KC_RIGHT,
        KC_PGUP, KC_PGDN,
        KC_PGDN,
        KC_HOME, KC_DOT,  KC_MINS
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    `    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mute |  F6  |  F7  |  F8  |  F9  |  F10 |   ~    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      | W_DEL|      | Sets |           |VolUp |      |      |  Up  | F11  | F12  |  Del   |
 * |---------+------+------+------+------+------|  R   |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      | LEFT | Down |RIGHT |  \   |        |
 * |---------+------+------+------+------+------| Sets |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |  L   |           |VolDow|      |      |      |      |      | RESET  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|WIN_L |------|       |------|WIN_R |  ~   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, WINDOW_DEL, KC_TRNS, SETS_R,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, SETS_L,
          EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                         KC_NO,   KC_NO,
                                                  KC_NO,
                               KC_TRNS,  WIN_L,   KC_TRNS,
       // right hand
       KC_MUTE, KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  TILDE,
       KC_VOLU, KC_NO,   KC_NO,  KC_UP,   KC_F11,   KC_F12,  KC_DEL,
                KC_NO,   KC_LEFT,KC_DOWN, KC_RIGHT, KC_BSLS, KC_NO,
       KC_VOLD, KC_NO  , KC_NO,  KC_NO,   KC_NO,    KC_NO,   RESET,
                         KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,
       KC_TRNS,   KC_TRNS,
       KC_NO,
       KC_TRNS, WIN_R,   TILDE
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    case JAN:
      if (record->event.pressed) {
        if (IS_WIN) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_GRAVE)SS_UP(X_LCTRL));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_SPACE)SS_UP(X_LGUI));
        }
      }
      return false;
      break;

    case WIN_L:
      if (record->event.pressed) {
        if (IS_WIN) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTRL));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LGUI));
        }
      }
      return false;
      break;

    case WIN_R:
      if (record->event.pressed) {
        if (IS_WIN) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LGUI)SS_UP(X_LCTRL));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LGUI));
        }
      }
      return false;
      break;

    case SETS_L:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LSHIFT)SS_UP(X_LGUI)SS_UP(X_LCTRL));
      }
      return false;
      break;

    case SETS_R:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_TAB)SS_UP(X_LGUI)SS_UP(X_LCTRL));
      }
      return false;
      break;

    case WIN_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB)SS_UP(X_LGUI));
      }
      return false;

    case TAB_NEXT:
      if (record->event.pressed) {
        if (IS_WIN) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_TAB)SS_UP(X_LCTRL));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB)SS_UP(X_LGUI));
        }
      }
      return false;

    case TAB_PREV:
      if (record->event.pressed) {
        if (IS_WIN) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LSHIFT)SS_UP(X_LCTRL));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
        }
      }
      return false;

    case WINDOW_DEL:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT));
      }
      return false;

    case TILDE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_GRAVE)SS_UP(X_GRAVE)SS_UP(X_LSHIFT));
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
